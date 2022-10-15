#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e6 + 17, z = 26, mod = 1e9 + 7;

int n;
string a, b;
int cnt[z], c[z], fac[maxn], rfac[maxn], save_rev[maxn];

int solve(string &s){
	memcpy(c, cnt, sizeof c);
	int cur = fac[n];
	for(int i = 0; i < z; i++)
		if(c[i])
			cur = (ll) cur * rfac[ c[i] ] % mod;
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int x = 0; x < s[i] - 'a'; x++)
			if(c[x]){
				int now = cur;
				now = (ll) now * save_rev[n - i] % mod;
				now = (ll) now * c[x] % mod;
				ans = (ans + now) % mod;
			}
		if(c[ s[i] - 'a' ]){
			cur = (ll) cur * save_rev[n - i] % mod;
			cur = (ll) cur * c[ s[i] - 'a' ] % mod;
			c[ s[i] - 'a' ]--;
		}
		else
			break;
	}
	return ans;
}
int rev(int a){
	int ret = 1;
	for(int b = mod - 2; b; b >>= 1, a = (ll) a * a % mod)
		if(b & 1)
			ret = (ll) ret * a % mod;
	return ret;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	fac[0] = rfac[0] = 1;
	for(int i = 1; i < maxn; i++){
		fac[i] = (ll) i * fac[i - 1] % mod;
		save_rev[i] = rev(i);
		rfac[i] = (ll) save_rev[i] * rfac[i - 1] % mod;
	}
	cin >> a >> b;
	n = a.size();
	for(auto c : a)
		cnt[c - 'a']++;
	cout << ((solve(b) + mod - solve(a)) % mod + mod - 1) % mod << '\n';
}