#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

typedef long long ll;
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second
#define ar array
#define vt vector
#define ub upper_bound
#define lb lower_bound
#define nl '\n'
#define vi vector<int>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vt vector
#define vl vector<ll>
#define vpi vector<pi>
#define vpl vt<pl>
#define vb vector<bool>
#define ull unsigned long long
#define sz(x) int(x.size())
#define rep(i, a, b) for(int i = a; i < (b); ++i)

ll n, m, k;
const int mxN=3e5,M=1e9+7;
const ll inf = 8e18;

template<typename K> using pq = priority_queue<K>;
template<typename K> using pqg = priority_queue<K, vt<K>, greater<K>>;
template<typename K> using dq = deque<K>;


void solve(int test_case = 0) {
	int a, b, c;
	cin >> a >> b >> c;

	bool pos[20000] = {};
	pos[0]=1;
	for(int i = 0; i < 15000; i++) {
		if(!pos[i])
			continue;
		pos[i+b]=pos[i+a]=true;
	}
	
	cout << (pos[c] ? "Yes\n" : "No\n");
}


int main()
{
    //setup();
	cin.tie(0)->sync_with_stdio(0);
    //precalc();
    int T = 1;

    for(int nt = 0, i; nt < T; nt++) {
        solve(nt);
        ++i;
    }
}