#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("avx")

#include <bits/stdc++.h>
#ifdef LOC
#define deb _deb
#else
#define deb(...)
#endif
#define x  first
#define y second
#define gcd __gcd
#define mp make_pair
#define pb push_back
#define sz(x)int((x).size())
#define each(a,x)for(auto&a:(x))
#define all(x)(x).begin(),(x).end()
#define rep(i,b,e)for(int i=(b);i<(e);i++)
#define tem template<class t,class u,class...w>
#define DBP(...)void print(...){DD(#__VA_ARGS__,__VA_ARGS__);}
#define pri(y)tem auto operator<<(t&o,u a)->decltype(y(a),o){return o<<
#define _deb(...)(DD("#, "#__VA_ARGS__,__LINE__,__VA_ARGS__),cerr<<endl)
using ll=long long;pri(a.print)"{",a.print(),o<<"}";}using namespace std;void DD(...){}using Pii=pair<int
,int>;tem void DD(t s,u a,w...k){while(*s&&*s!=',')cerr<<*s++;cerr<<": "<<a<<*s++;DD(s,k...);}pri(all)"["
,[&](){for(auto i : a)o<<i<<", ";}(),o<<"]";}using  Vi=vector<int>;pri(get<1>) "("<<a.x<<", "<<a.y<<")";}
//-----------------------------------------------------------------------------------------------------//

char mem[128<<20];
size_t nMem;

void* operator new(size_t n) { nMem += n; return &mem[nMem-n]; }
void operator delete(void*) noexcept {}
void operator delete(void*, size_t) noexcept {}

// ---

constexpr int perms[6][3] = {
	{ 1, 2, 4 }, { 1, 4, 2 }, { 2, 1, 4 }, { 2, 4, 1 }, { 4, 1, 2 }, { 4, 2, 1 }
};

Vi F[100001];
int D[8];
int full[8][8][8];

int solve(int a, int b, int c) {
	if (a > c) swap(a, c);
	int& result = full[a][b][c];
	if (result) return result;

	Vi &A = F[D[a]], &B = F[D[b]], &C = F[D[c]];
	int ret = 0, l = 0, r = 0;

	rep(m, 0, sz(B)) {
		while (l < sz(A) && A[l] < B[m]) l++;
		int le = sz(A) - l;
		if (l < sz(A) && A[l] == B[m]) l++;

		while (r < sz(C) && C[r] < B[m]) r++;
		int re = sz(C) - r;
		if (r < sz(C) && C[r] == B[m]) r++;

		ret += l*re + le*r;
	}

	result = ret;
	return ret;
}

int run(int a, int b, int c) {
	D[1] = a;
	D[2] = b;
	D[3] = gcd(a, b);
	D[4] = c;
	D[5] = gcd(a, c);
	D[6] = gcd(b, c);
	D[7] = gcd(gcd(a, b), c);

	int ret = 0;
	memset(full, 0, sizeof(full));

	rep(subset, 0, 64) {
		int cur[3] = { 0 };
		int sign = -1;

		rep(i, 0, 6) if (subset & (1<<i)) {
			auto& perm = perms[i];
			rep(j, 0, 3) cur[j] |= perm[j];
			sign *= -1;
		}

		ret += sign * solve(cur[0], cur[1], cur[2]);
	}

	return ret/2;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	rep(i, 1, 100001) for (int j = i; j <= 100000; j += i) F[j].pb(i);

	int n; cin >> n;
	while (n--) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << run(a, b, c) << '\n';
	}
	return 0;
}