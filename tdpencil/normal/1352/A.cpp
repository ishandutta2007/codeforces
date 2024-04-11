#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i<(n);i++)
#define readVec(v) forn(i, v.size()){cin >> v[i];}
#define printArr(arr, n) forn(i, n){if (i) cout << " "; cout << arr[i];} cout << endl;	
#define ll long long
#define vt vector
#define FOR(i, a) for(int i = 0; i < a; i++)
#define pb push_back
#define ld double
#define mp make_pair
#define f first
#define s second
#define bint int64_t
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef long double lld;

ll n, m, l, x, y, z, k;
string s;
int t, g, i;
const int INF = 1e9;

void solve() {

	cin >> n;
	while(n--) {
		int a;
		cin >> a;
		vt<int> ans;
		int power = 1;
		while(a>0){
			if(a%10>0) ans.pb((a%10) * power);
			a/=10;
			power*=10;
		}
		cout << ans.size() << endl;
		reverse(ans.begin(), ans.end());
		for(auto &b : ans) cout << b << " ";
		cout << endl;
	}
	
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