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

vector<tuple<pii, pii, pii>> opes = {mt(mp(0, 0), mp(0, 1), mp(1, 0)),
                                     mt(mp(0, 0), mp(0, 1), mp(1, 1)),
                                     mt(mp(0, 0), mp(1, 1), mp(1, 0)),
                                     mt(mp(1, 1), mp(0, 1), mp(1, 0))};
int trans(int x, int y, int lx, int ly){
    return x * ly + y;
}

int trans(pii p0, pii p, int lx, int ly){
    return trans(p0.F + p.F,p0.S + p.S, lx, ly);
}

void solve1(int x, int y, int lx, int ly){
//    cerr << x << " " << y << " " << lx << " " << ly << "\n";
    int now = 0;
    for(int i = 0; i < lx; i++){
        for(int j = 0; j < ly; j++){
            if(a[x + i][y + j]) now |= 1 << trans(i, j, lx, ly);
        }
    }
    queue<int> q;
    q.push(now);
    vector<int> dis(1 << (lx * ly), -1);
    dis[now] = 0;
    vector<int> f(1 << (lx * ly));
    vector<tuple<pii, pii, pii>> ope(1 << (lx * ly));
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0; i < lx - 1; i++){
            for(int j = 0; j < ly - 1; j++){
                for(auto op : opes){
                    int tmp = now;
                    tmp ^= 1 << trans(mp(i, j), gt(op, 0), lx, ly);
                    tmp ^= 1 << trans(mp(i, j), gt(op, 1), lx, ly);
                    tmp ^= 1 << trans(mp(i, j), gt(op, 2), lx, ly);
//                    cerr << bitset<9>(now) << " " << bitset<9>(tmp) << "\n";
                    if(dis[tmp] != -1) continue;
                    dis[tmp] = dis[now] + 1;
                    f[tmp] = now;
                    gt(op, 0).F += i;
                    gt(op, 0).S += j;
                    gt(op, 1).F += i;
                    gt(op, 1).S += j;
                    gt(op, 2).F += i;
                    gt(op, 2).S += j;
                    ope[tmp] = op;
                    q.push(tmp);
                }
            }
        }
    }
    for(int i = 0; i < lx; i++){
        for(int j = 0; j < ly; j++) a[x + i][y + j] = 0;
    }
    vector<tuple<pii, pii, pii>> tans;
    int tmp = 0;
    while(tmp != now){
        tans.eb(ope[tmp]);
        tmp = f[tmp];
    }
    reverse(iter(tans));
//    cerr << dis[0] << " " << tans.size() << "\n";
    for(auto i : tans){
        gt(i, 0).F += x;
        gt(i, 0).S += y;
        gt(i, 1).F += x;
        gt(i, 1).S += y;
        gt(i, 2).F += x;
        gt(i, 2).S += y;
        ans.eb(i);
    }
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

        for(int i = 0; i < (n % 2 ? n - 3 : n - 1); i += 2){
            for(int j = 0; j < (m % 2 ? m - 3 : m - 1); j += 2){
                solve1(i, j, 2, 2);
            }
        }

        if(m % 2)
        for(int i = 0; i < (n % 2 ? n - 3 : n - 1); i += 2){
            solve1(i, m - 3, 2, 3);
        }
        if(n % 2)
        for(int j = 0; j < (m % 2 ? m - 3 : m - 1); j += 2){
            solve1(n - 3, j, 3, 2);
        }
        if(n % 2 && m % 2) solve1(n - 3, m - 3, 3, 3);

        cout << ans.size() << "\n";
        for(auto i : ans){
            pii x, y, z;
            tie(x, y, z) = i;
            cout << x.F + 1 << " " << x.S + 1 << " " << y.F + 1 << " " << y.S + 1 << " " << z.F + 1 << " " << z.S + 1 << "\n";
        }
    }

    return 0;
}