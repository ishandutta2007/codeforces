#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define I(i, a) for(auto i : a)
#define pb push_back
#define rs resize
#define mk make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define fi0(x) memset(x, 0, sizeof(x))
#define finf(x) memset(x, 127, sizeof(x))
#define y1 adjf
#define tm afhdhn

const lint mod = 1000000007;
const int MAXN = 2e5 + 5;

lint dp[MAXN], cnt[MAXN];

lint binpow(int p, lint x){
	if(x == 0)ret 1ll;
	lint prv = binpow(p, x/2);
	if(x&1){
		ret p * ((prv * prv) % mod) % mod;
	}
	else 
		ret prv * prv % mod;
}

int n;
int a[MAXN], pw[MAXN];
int sz = 0;
int p[MAXN];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n);
	int prv = -1;
	F(i, 0, n)scanf("%d", &p[i]);
	sort(p, p + n);
	F(i, 0, n){
		int x = p[i];
		if(prv != x){a[sz] = x; pw[sz] = 0; sz++; prv = x;}
		pw[sz - 1]++;
	}
	dp[0] = cnt[0] = 1;
	F(i, 1, sz + 1){
		lint c = pw[i - 1] * 1ll * (pw[i - 1] + 1)/2;
		c %= (mod - 1);
		c = c * cnt[i - 1] % (mod - 1);
		cnt[i] = cnt[i - 1] * (pw[i - 1] + 1) % (mod - 1);
		dp[i] = binpow(dp[i - 1], pw[i - 1] + 1);
		dp[i] = dp[i] * binpow(a[i - 1], c) % mod;
	}
	printf("%lld", dp[sz]);
	ret 0;
}