//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
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
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a) / (b) + !!((a) % (b)))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using namespace __gnu_pbds;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

int n, m;
vector<string> g;

vector<vector<int>> dis;

vector<pii> dir = {mp(1, 0), mp(0, 1), mp(-1, 0), mp(0, -1)};

void calc(char s){

    dis.clear();
    dis.resize(n + 2, vector<int>(m + 2, -1));

    std::priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<>> pq;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) if(g[i][j] == s){
            dis[i][j] = 0;
            pq.push(mp(0, mp(i, j)));
        }
    }

    while(!pq.empty()){
        int x = pq.top().S.F, y = pq.top().S.S;
        int d = pq.top().F;
        //cerr << s << " " << x << " " << y << ' ' << d << "\n";
        pq.pop();
        if(d > dis[x][y]) continue;

        for(pii p : dir){
            int nx = x + p.F, ny = y + p.S;
            //cerr << "test " << nx << " " << ny << " " << g[nx][ny] << "\n";
            if(g[nx][ny] == '#') continue;
            int nd = d + (g[nx][ny] == '.');
            //cerr << "test " << nx << " " << ny << ' ' << nd << " " << dis[nx][ny] << "\n";
            if(nd >= dis[nx][ny] && dis[nx][ny] != -1) continue;
            dis[nx][ny] = nd;
            pq.push(mp(nd, mp(nx, ny)));
        }
    }

}

int main(){
    StarBurstStream

    cin >> n >> m;

    g.resize(n + 2);
    g[0] = g[n + 1] = string(m + 2, '#');
    for(int i = 1; i <= n; i++){
        cin >> g[i];
        g[i] = '#' + g[i] + '#';
    }

    vector<vector<int>> ans(n + 2, vector<int>(m + 2));

    calc('1');
    for(int i = 1; i <= n; i++){
        //printv(dis[i], cerr);
        for(int j = 1; j <= m; j++){
            if(dis[i][j] == -1 || ans[i][j] == -1) ans[i][j] = -1;
            else ans[i][j] += dis[i][j];
        }
    }

    calc('2');
    for(int i = 1; i <= n; i++){
        //printv(dis[i], cerr);
        for(int j = 1; j <= m; j++){
            if(dis[i][j] == -1 || ans[i][j] == -1) ans[i][j] = -1;
            else ans[i][j] += dis[i][j];
        }
    }

    calc('3');
    for(int i = 1; i <= n; i++){
        //printv(dis[i], cerr);
        for(int j = 1; j <= m; j++){
            if(dis[i][j] == -1 || ans[i][j] == -1) ans[i][j] = -1;
            else ans[i][j] += dis[i][j];
        }
    }

    int mn = -1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(g[i][j] == '.') ans[i][j] -= 2;
            if(ans[i][j] >= 0 && (mn == -1 || ans[i][j] < mn)) mn = ans[i][j];
        }
    }

    cout << mn << "\n";

    return 0;
}