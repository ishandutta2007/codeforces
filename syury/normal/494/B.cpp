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

string s, t;
int n, m;
vector<int> z;
vector<lint> dp, sum, ssum;

lint get(int l, int r){
	if(l > r)ret 0;
	ret (ssum[l] - ((r == n - 1) ? 0 : ssum[r + 1]) + mod + mod) % mod;
}

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t;
	n = s.length(); m = t.length();
	dp.rs(n); sum.rs(n); ssum.rs(n);
	dp.asg(n, 0); sum.asg(n, 0); ssum.asg(n, 0);
	t += '#';
	t += s;
	z.rs(n + m + 1);
	z.asg(n + m + 1, 0);
	int l = 0, r = 0;
	F(i, 1, n + m + 1){
		if(r >= i){
			z[i] = min(z[i - l], r - i + 1);
		}
		while(i + z[i] < n + m + 1 && t[z[i]] == t[i + z[i]])z[i]++;
		if(i + z[i] - 1 > r){
			l = i; r = i + z[i] - 1;
		}
	}
	int le = n;
	Df(i, n - 1, -1){
		int pos = i + m + 1;
		if(i < n - 1)sum[i] = sum[i + 1]; else sum[i] = 0ll;
		ssum[i] = (i == n - 1) ? 0 : (ssum[i + 1]);
		if(i < n - 1)dp[i] = dp[i + 1]; else dp[i] = 0;
		if(z[pos] >= m){
			int _r = le - 1;
			int _l = i + m - 1;
			dp[i] += _r - _l + 1;
			_r = min(n - 1, _r + 1);
			_l = min(n - 1, _l + 1);
			dp[i] += get(_l, _r);
			while(dp[i] >= mod)dp[i] -= mod;
			le = i + m - 1;
		}
		sum[i] += dp[i];
		if(sum[i] >= mod)sum[i] -= mod;
		ssum[i] += sum[i];
		if(ssum[i] >= mod)ssum[i] -= mod;
		//printf("At %d dp = %lld sum = %lld ssum = %lld\n", i, dp[i], sum[i], ssum[i]);
	}
	printf("%lld", sum[0]);
	ret 0;
}