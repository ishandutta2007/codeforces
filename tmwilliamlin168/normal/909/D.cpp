#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;

string x;
vector<pair<char,int>> v, v1;
int ans = 0;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> x;
	string t = "";
	for (char c: x) {
	    if (sz(t) && t.back() != c) {
	        v.pb({t.back(),sz(t)});
	        t = "";
	    }
	    t += c;
	}
	if (sz(t)) {
        v.pb({t.back(),sz(t)});
	}
	int ans = 0;
	while (sz(v) > 1) {
	    F0R(i,sz(v)) {
	        if (i == 0 || i == sz(v)-1) v[i].s --;
	        else v[i].s -= 2;
	        v[i].s = max(v[i].s,0);
	    }
	    v1.clear();
	    for (auto a: v) {
	        if (a.s == 0) continue;
	        if (sz(v1) && v1.back().f == a.f) v1.back().s += a.s;
	        else v1.pb(a);
	    }
	    swap(v,v1);
	    ans++;
	}
	cout << ans;
}