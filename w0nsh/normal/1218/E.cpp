#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(),(x).end()

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef vector < int > VI;
typedef double D;

const int MN = 100005, inf = 1000000005, Mod = 998244353, p2 = (1 << 15);
const LL INF = 1000000000000000005LL;

const double PI = acos(-1.0);

#define rep(i,k,n) for(LL i= (LL) k;i< (LL) n;i++)

namespace FFT
{
	const int MAX = (1 << 16);
	typedef LL value;
	typedef complex<double> comp;
	
	int N;
	comp omega[MAX];
	comp a1[MAX], a2[MAX];
	comp z1[MAX], z2[MAX];
	
	void fft(comp *a, comp *z, int m = N)
	{
		if(m == 1)
		{
			z[0] = a[0];
		}
		else
		{
			int s = N/m;
			m /= 2;
			fft(a, z, m);
			fft(a+s, z+m, m);
			
			rep(i, 0, m)
			{
				comp c = omega[s*i] * z[m+i];
				z[m+i] = z[i] - c;
				z[i] += c;
			}
		}
	}
	
	void mult(value *a, value *b, value *c, int len)
	{
		N = 2 * len;
		while(N & (N-1)) ++N;
		assert(N <= MAX);
		
		rep(i, 0, N) a1[i] = 0;
		rep(i, 0, N) a2[i] = 0;
		rep(i, 0, len) a1[i] = a[i];
		rep(i, 0, len) a2[i] = b[i];
		rep(i, 0, N) z1[i] = z2[i] = 0;
		
		rep(i, 0, N) omega[i] = polar(1.0, 2*PI/N*i);
		fft(a1, z1, N);
		fft(a2, z2, N);
		
		rep(i, 0, N) omega[i] = comp(1, 0) / omega[i];
		rep(i, 0, N) a1[i] = z1[i] * z2[i] / comp(N, 0);
		fft(a1, z1, N);
		
		rep(i, 0, 2*len) c[i] = round(z1[i].real());
	}
}

#define MAX (1<<16)

LL a0[MAX], a1[MAX], b0[MAX], b1[MAX], c0[MAX], c1[MAX], c2[MAX];

void mult_mod(LL *a, LL *b, LL*c, int len, int mod)
{
	rep(i, 0, len) a0[i] = a[i] & 0xFFFF;
	rep(i, 0, len) a1[i] = a[i] >> 16;
	
	rep(i, 0, len) b0[i] = b[i] & 0xFFFF;
	rep(i, 0, len) b1[i] = b[i] >> 16;
	
	FFT::mult(a0, b0, c0, len);
	FFT::mult(a1, b1, c2, len);
	
	rep(i, 0, len) a0[i] += a1[i];
	rep(i, 0, len) b0[i] += b1[i];
	
	FFT::mult(a0, b0, c1, len);
	rep(i, 0, 2*len) c1[i] -= c0[i] + c2[i];
	
	rep(i, 0, 2*len) c1[i] %= mod;
	rep(i, 0, 2*len) c2[i] %= mod;
	rep(i, 0, 2*len) c[i] = (c0[i] + (c1[i] << 16) + (c2[i] << 32)) % mod;
	rep(i, 0, 2*len) a0[i] = a1[i] = b0[i] = b1[i] = c0[i] = c1[i] = c2[i] = 0LL;
}

LL tab1[MN], tab2[MN], tab3[MN], A[MN], B[MN];

void solve(LL *a, int p, int k)
{
	int len = k - p + 1;
	if(len <= 1)
		return;
	int mid = (p + k) >> 1, hf = (len >> 1);
	solve(a, p, mid);
	solve(a, mid + 1, k);
	tab1[0] = tab2[0] = 1LL;
	for(int i = 1; i <= hf; ++i)
	{
		tab1[i] = *(a + p + i - 1);
		tab2[i] = *(a + mid + i);
	}
	mult_mod(tab1, tab2, tab3, hf + 1, Mod);
	/*for(int i = 0; i <= hf; ++i)
		printf("i %d tab1 %lld tab2 %lld\n", i, tab1[i], tab2[i]);
	for(int i = 0; i <= len; ++i)
		printf("i %d tab3 %lld\n", i, tab3[i]);*/
	for(int i = 1; i <= len; ++i)
		*(a + p + i - 1) = tab3[i];
	for(int i = 0; i <= len + 3; ++i)
		tab1[i] = tab2[i] = tab3[i] = 0LL;
}


int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%lld", &A[i]);
	int q;
	scanf("%d", &q);
	while(q--)
	{
		for(int i = 1; i <= n; ++i)
			B[i] = A[i];
		int typ, q;
		scanf("%d", &typ);
		if(typ == 1)
		{
			int x, d;
			scanf("%d%d%d", &q, &x, &d);
			B[x] = d;
		}
		else
		{
			int x, y, d;
			scanf("%d%d%d%d", &q, &x, &y, &d);
			for(int i = x; i <= y; ++i)
				B[i] += d;
		}
		for(int i = 1; i <= n; ++i)
			B[i] = (((q - B[i]) % Mod) + Mod) % Mod;
		solve(B, 0, p2 - 1);
		printf("%lld\n", B[k - 1]);
		for(int i = 0; i < p2; ++i)
			B[i] = 0;
	}
		
}