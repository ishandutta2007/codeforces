//#define NDEBUG

#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); cerr.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 10007;
const ll MAX = 1LL << 60;

ostream& operator<<(ostream& o, pii p){
    o << p.F << "," << p.S;
    return o;
}

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    vector<set<int>> trow(n), tcolumn(m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            trow[i].insert(a[i][j]);
            tcolumn[j].insert(a[i][j]);
        }
    }
    vector<vector<int>> row(n), column(m);
    for(int i = 0; i < n; i++){
        for(int j : trow[i]) row[i].pb(j);
    }
    for(int i = 0; i < m; i++){
        for(int j : tcolumn[i]) column[i].pb(j);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int t = a[i][j];
            int tr = lower_bound(iter(row[i]), t) - row[i].begin();
            int tc = lower_bound(iter(column[j]), t) - column[j].begin();
            //cerr << i << " " << j << " " << tr << " " << tc << "\n";
            int tt = tr - tc;
            cout << max(row[i].size() + max(-tt, 0), column[j].size() + max(tt, 0)) << " ";
        }
        cout << "\n";
    }

    return 0;
}