#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
using ll = int64_t;
const int N = 3e5;
int t, n, m;
int id[N];
void solve() {
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> a(n);
    // cost, type, index
    fill(id, id+n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i].second.first;
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second.second = i;
    }
    sort(a.begin(), a.end());
	//return;
    for(int i = 0; i < n; i++) {
        id[a[i].second.second] = i;
    }
    int cheapestId = 0; 
    for(int i =0 ; i < m; i++) {
        int idx, val;
        cin >> idx >> val;
		//cout << idx << " " << val << '\n';
        ll ans = 0;
        if(val >= a[id[idx-1]].second.first) {
            val -= a[id[idx-1]].second.first;
            ans += a[id[idx-1]].second.first * 1LL * a[id[idx-1]].first;
            a[id[idx-1]].second.first=0;
        } else {
            ans += a[id[idx-1]].first * 1LL * val;
            a[id[idx-1]].second.first -= val; 
            val = 0;
        }
        while(true && val > 0 && cheapestId < n) {
            if(a[cheapestId].second.first == 0) { ++cheapestId; continue;}
            if(a[cheapestId].second.first >= val) { ans += a[cheapestId].first * 1LL * val, a[cheapestId].second.first-=val,val=0; }
            else { ans += a[cheapestId].first * 1LL * a[cheapestId].second.first, val -= a[cheapestId].second.first, a[cheapestId].second.first=0, ++cheapestId;}
        }
		cout << (cheapestId==n?0:ans) << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cin >> t;
	t=1;
    while(t--) {
        solve();
    }
}