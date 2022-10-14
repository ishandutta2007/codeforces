#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i<(n);i++)
#define readVec(v) forn(i, v.size()){cin >> v[i];}
#define printArr(arr, n) forn(i, n){if (i) cout << " "; cout << arr[i];} cout << endl;	
#define ll long long
#define vi vector<int>
#define FOR(i, a) for(int i = 0; i < a; i++)
#define pb push_back
#define ld double
#define mp make_pair
#define f first
#define s second
#define all(n) n.begin(),n.end()
#define sum(x) accumulate(x.begin(), x.end(), 0)

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef long double lld;

ll n, m, l, x, y, z, k;
/* 
Fisrt you have to do stuff
then you have to do stuff */
int t, g, i;
const ll INF = 1e18;
// n+1*n -> greater than 10
bool distinct_c(vl &nums) {
	set<ll> vals;
	for(int i = 0; i < nums.size(); i++) {
		vals.insert(nums[i]);
	}
	if(vals.size()==1) return false;
	return true;
}
void solve() {
	cin >> n;
	string s;
	vl dp(1001);
	dp[0] = 0;
	dp[1] = 1;
	for(int i =2; i <= 1000; i++) {
		dp[i] = dp[i-1] + dp[i-2];
	}
	
	int t= 2;
	for(int i = 1; i <= n; i++) {
		if(i==dp[t]){
			s.pb('O');
			t++;
		} else {
			s.pb('o');
		}
	}
	cout << s;

	
}
void fast_io() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
	
int main() {
	fast_io();

	solve();
		
}