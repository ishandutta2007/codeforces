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
const int MAXN = 3e3 + 3;

lint gcdex(lint a, lint b, lint & x, lint & y){
	if(a == 0){
		x = 0, y = 1;
		ret b;
	}
	lint x1, y1;
	lint g = gcdex(b % a, a, x1, y1);
	y = x1;
	x = y1 - (b/a) * x1;
	ret g;
}

lint inv(lint a){
	lint x, y;
	gcdex(a, mod, x, y);
	x %= mod;
	ret (x + mod)%mod;
}

lint fac[MAXN];

lint C(lint n, lint k){
	if(k > n)ret 0;
	ret fac[n] * inv(fac[k] * fac[n - k] % mod) % mod;
}

int n, m, k;

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d%d", &n, &m, &k);
	fac[0] = 1ll;
	F(i, 1, MAXN)fac[i] = fac[i - 1] * i % mod;
	printf("%lld", C(m - 1, 2 * k) * C(n - 1, 2 * k) % mod);
	ret 0;
}