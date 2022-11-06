#include <bits/stdc++.h>

#define Pi acos(-1.)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define fi first
#define se second
#define FILE "474"
#define standart 1

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const ll INF = 1e9 + 322;
const ll LINF = 2e18 + 474;
const ll MAXN = 2e5 + 5;
const double eps = 1e-12;

int n, m;
set<int> small, big;
set<int> a[MAXN];
set<int> elem_small[MAXN], elem_big[MAXN];
int l, r, sum = 0;
vector<pair<pii, int > > ans;

void process() {
     for(int i = 1; i <= m; i++) {
        if(elem_big[i].empty())
            continue;
        set<int> small_to_del, big_to_del;
        for(auto it : small) {
            if(elem_small[i].find(it) == elem_small[i].end()) {
                a[it].insert(i);
                if(a[it].size() == l)
                    small_to_del.insert(it);
                elem_small[i].insert(it);

                int ind = *elem_big[i].begin();
                a[ind].erase(i);
                if(a[ind].size() == r) {
                    big_to_del.insert(ind);
                }
                elem_big[i].erase(ind);

                ans.pb(mp(mp(ind, it), i));

                if(elem_big[i].empty()) {
                    break;
                }
            }
        }
        for(auto it : small_to_del) {
            for(auto x : a[it]) {
                elem_small[x].erase(it);
            }
            small.erase(it);
        }
        for(auto it : big_to_del) {
            for(auto x : a[it]) {
                elem_big[x].erase(it);
            }
            big.erase(it);
        }
    }
}

void fill_sets() {
    for(int i = 0; i < n; i++) {
        int len = a[i].size();
        if(len < l) {
            small.insert(i);
            for(auto it : a[i]) {
                elem_small[it].insert(i);
            }
        }
        else if(len > r) {
            big.insert(i);
            for(auto it : a[i]) {
                elem_big[it].insert(i);
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        sum += k;
        for(int j = 0; j < k; j++) {
            int x; cin >> x;
            a[i].insert(x);
        }
    }
    l = sum / n;
    r = l+ (sum % n > 0 ? 1 : 0);
    fill_sets();
//    for(auto it : small) {
//        cout << it << " " ;
//    }
//    cout << endl;
//    for(auto it : big) {
//        cout << it << " " ;
//    }
//    cout << endl;
    process();

    assert(!(!big.empty() && !small.empty()));
    if(!big.empty()) {
        l++;
        fill_sets();
        process();
    }
    else if(!small.empty()) {
        r--;
        fill_sets();
        process();
    }
    cout << (int)ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i].fi.fi + 1 << " " << ans[i].fi.se + 1 << " " << ans[i].se << "\n";
    }
}

/*
4 5
2 1 2
3 1 2 3
4 1 2 3 4
4 1 2 3 4
*/

/*
4 5
2 1 2
2 1 2
3 1 2 3
4 1 2 3 4
*/


int main() {
    if(!standart) {
        freopen(FILE".in", "r", stdin);
        freopen(FILE".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    setlocale(LC_ALL, "Russian");
    int T = 1; //cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}