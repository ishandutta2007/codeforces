#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define trav(a,x) for(auto& a : x)
typedef __int128_t ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll md = 1'000'000'007;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    int t;
    cin>>t;

    rep(i,0,t) {
        long long _m;
        cin>>_m;
        ll m = _m;
        ll m2 = m/2;
        ll m4 = m2/2;
        ll ans = (m4+1) % md * ((m2+1 - m4) % md+md)%md;
        cout << (long long)(ans) << "\n";
    }
}