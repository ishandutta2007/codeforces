
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    vi ans;
    int q, x, y, i=0;
    vector<vi> locations(5e6+1);
    cin >> q;
    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            cin >> x;
            locations[x].push_back(i++);
        } else if(t == 2) {
            cin >> x >> y;
            vi &loc_x = locations[x];
            vi &loc_y = locations[y];

            if(x != y) {
                if(loc_x.size() > loc_y.size())
                    swap(loc_x, loc_y);

                for(int i : loc_x) {
                    loc_y.push_back(i); 
                }

                loc_x.clear();
            }
        }
    }
    ans.resize(i);
    for(int j = 1; j <= 5e6; j++)
        for(int e : locations[j])
            ans[e] = j;

    for(int j = 0; j < i; j++)
        cout << ans[j] << " ";

}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t=1;
    // cin >> t;
    while(t--) {
        solve();
    }
}