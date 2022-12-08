#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int maxp = 10000007; 

ll h[maxp]; 
int sum[maxp]; 
int t[maxp]; 

void Add(ll x, int tt) {
	ll i = x % maxp; 
	for (;h[i] > 0 && h[i] != x;i = (i*23+23474) % maxp); 
	if (t[i] != tt) sum[i]++;
	h[i] = x; t[i] = tt; 
}

int Get(ll x) {
	ll i = x % maxp; 
	for (;h[i] > 0 && h[i] != x;i = (i*23+23474) % maxp); 
	return sum[i]; 
}

int n; 
ll s[80000]; 

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) {
		scanf( "%lld", &s[i] ); 
		for (ll b = 10; b <= 1000000000; b*=10)
			for (ll a = 1; a * b <= 1000000000; a*=10) 
				Add(s[i]/a%b+b, i); 
	}
	for (int i = 1; i <= n; ++i) {
		bool flag = false; 
		for (ll b = 10; b <= 1000000000; b*=10)
			for (ll a = 1; a*b <= 1000000000; a*=10) 
				if (!flag && (Get(s[i]/a%b+b) == 1)) {
					vector<int> ans; 
					ll x = s[i]/a; 
					for (ll c=1; c<b; c*=10) 
						ans.pb(x/c%10); 
					reverse(ans.begin(), ans.end()); 
					for (auto j : ans) printf( "%d", j); 
					puts( "" ); 
					flag = true; 
				}
	}
}