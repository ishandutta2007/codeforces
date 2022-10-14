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
#define s secondg

#define all(n) n.begin(),n.end()
#define sum(x) accumulate(x.begin(), x.end(), 0)
#define si(z) int64_t(z.size())

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

void solve() {
	cin >> n;
	vl ns(n);
	readVec(ns);
	ll a = *max_element(all(ns));
	ll b = *min_element(all(ns));
	ll ans = a-b-n+1;
	
	cout << ans;
	

	
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