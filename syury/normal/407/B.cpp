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

const lint mod = 1e9 + 7;

vector<lint> dp;
vector<lint> pref;
vector<int> p;
int n;

lint getsum(int l, int r){
	if(l == 0)ret pref[r];
	else ret pref[r] - pref[l - 1];
}

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	dp.rs(n); pref.rs(n); p.rs(n);
	F(i, 0, n)
		scanf("%d", &p[i]);
	dp[0] = 1ll;
	p[0]--;
	pref[0] = 1;
	F(i, 1, n){
		p[i]--;
		int prv = p[i];
		if(i == prv){dp[i] = 1;}
		else{dp[i] = 1 + i - prv + getsum(prv, i - 1);
		dp[i] %= mod;}
		pref[i] = pref[i - 1] + dp[i];
		pref[i] %= mod;
	}
	lint ans = n + pref[n - 1];
	ans = ((ans % mod) + mod) % mod;
	printf("%lld", ans);
	ret 0;
}