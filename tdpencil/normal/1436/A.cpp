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

ll n, k;
vector<vector<ll>> adj(10000);
vector<bool> seen;

const ll INF = 1e18;
// n+1*n -> greater than 10
template<typename... T>
void read(T&... args) {
	((cin >> args), ...);
}
template<typename... T>
void write(T&... args) {
	((cout << args << " "), ...);
}
template<typename... T>
void print(T&... args) {
	((cout << args << '\n'), ...);
}
bool isPrime(ll n) {
	if(n==1) return false;
	for(ll i =2; i<=sqrt(n); i++) {
		if(n%i==0) return false;
	}
	return true;
}

void solve() {
	cin >> n;
	while(n--) {
		ll a, b;
		cin >> a >> b;
		vl ns(a);
		for(int i = 0; i < a; i++) 
			cin>>ns[i];
		sort(all(ns));
		if(sum(ns)==b) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
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