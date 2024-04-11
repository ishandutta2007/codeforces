#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define ef(a) emplace_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define tomin(a, b) ((a) = min((a), (b)))
#define topos(a) ((a) = (((a) % MOD + MOD) % MOD))
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    map<vector<int>, queue<int>> pos;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
        pos[a[i]].push(i);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> b[i][j];
        auto it = pos.find(b[i]);
        if(it == pos.end() || it->S.empty()){
            cout << "-1\n";
            return 0;
        }
        b[i].eb(it->S.front());
        it->S.pop();
    }

//    for(int i = 0; i < n; i++) printv(b[i], cerr);

    vector<int> ans;

    vector<int> col(m + 1);
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j <= m; j++){
            if(b[i][j] > b[i + 1][j]) col[j]++;
        }
    }

    vector<bool> ok(m + 1);
    vector<bool> g(n);
    g[n - 1] = true;
    while(!ok[m]){

        vector<int> c;
        for(int i = 0; i <= m; i++){
            if(!ok[i] && col[i] == 0) c.eb(i);
        }

        if(c.empty()) break;
//        cerr << "test ";
//        printv(c, cerr);

        vector<vector<int>> p(n);
        for(int i : c){
            for(int j = 0; j < n; j++){
                p[j].eb(b[j][i]);
            }
        }
        for(int i = 0; i < n; i++){
            if(g[i]) continue;
            if(p[i] == p[i + 1]) continue;
            for(int j = 0; j <= m; j++){
                if(b[i][j] > b[i + 1][j]) col[j]--;
            }
            g[i] = true;
        }

        for(int i : c){
            ok[i] = true;
            if(i != m) ans.eb(i + 1);
        }

    }

    if(!ok[m]){
        cout << "-1\n";
        return 0;
    }

    reverse(iter(ans));
    cout << ans.size() << "\n";
    printv(ans, cout);

    return 0;
}