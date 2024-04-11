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

int n, m;
vector<vector<int>> a;
vector<tuple<pii, pii, pii>> ans;

void flip(pii p){
    a[p.F][p.S] = !a[p.F][p.S];
}

void solve(int x, int y){
    vector<pii> o, z;
    for(int i = 0; i <= 1; i++){
        for(int j = 0; j <= 1; j++){
            if(a[x + i][y + j]) o.eb(mp(x + i, y + j));
            else z.eb(mp(x + i, y + j));
        }
    }
//    cerr << x << " " << y << " " << o.size() << " " << z.size() << "\n";
    if(o.size() >= 3){
        ans.eb(mt(o[0], o[1], o[2]));
        flip(o[0]);
        flip(o[1]);
        flip(o[2]);
    }
    else if(o.size() >= 1){
        ans.eb(mt(o[0], z[0], z[1]));
        flip(o[0]);
        flip(z[0]);
        flip(z[1]);
    }
    else return;
    solve(x, y);
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        a.clear();
        ans.clear();
        a.resize(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            for(int j = 0; j < m; j++){
                a[i][j] = s[j] - '0';
            }
        }

        for(int i = 0; i < n - 1; i += 2){
            for(int j = 0; j < m - 1; j += 2){
                solve(i, j);
            }
        }

        for(int i = 0; i < n - 1; i += 2){
            solve(i, m - 2);
        }
        for(int j = 0; j < m - 1; j += 2){
            solve(n - 2, j);
        }
        solve(n - 2, m - 2);

        cout << ans.size() << "\n";
        for(auto i : ans){
            pii x, y, z;
            tie(x, y, z) = i;
            cout << x.F + 1 << " " << x.S + 1 << " " << y.F + 1 << " " << y.S + 1 << " " << z.F + 1 << " " << z.S + 1 << "\n";
        }
    }

    return 0;
}