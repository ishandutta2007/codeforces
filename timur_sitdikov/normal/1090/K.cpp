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

int n;
map<pair<string, set<char> >, vector<int> > a;

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s1, s2; cin >> s1 >> s2;
        set<char> st;
        for(int j = 0; j < (int)s2.size(); j++) {
            st.insert(s2[j]);
        }
        while(st.find(s1.back()) != st.end()) {
            s1.pop_back();
        }
        a[mp(s1, st)].pb(i + 1);
    }
    cout << (int)a.size() << "\n";
    for(auto it = a.begin(); it != a.end(); it++) {
        vector<int> cur = it->second;
        cout << (int)cur.size() << " ";
        for(int i = 0; i < (int)cur.size(); i++) {
            cout << cur[i] << " ";
        }
        cout << "\n";
    }
}




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