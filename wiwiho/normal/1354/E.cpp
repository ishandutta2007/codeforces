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


vector<vector<int>> g;
vector<pii> l;
vector<int> cnt0, cnt1;

void dfs(int now, int id, int c){
    l[now] = mp(id, c);
    if(c == 0) cnt0[id]++;
    else cnt1[id]++;
    for(int i : g[now]){
        if(l[i].F == -1) dfs(i, id, !c);
        else if(l[i].S == c){
            cout << "NO\n";
            exit(0);
        }
    }
}

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    g.resize(n + 1);
    l.resize(n + 1, mp(-1, -1));
    cnt0.resize(n + 1);
    cnt1.resize(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }

    vector<int> tmp(1);
    for(int i = 1; i <= n; i++){
        if(l[i].F == -1) dfs(i, i, 0), tmp.eb(i);
    }

    vector<vector<int>> dp0(tmp.size(), vector<int>(n2 + 1, -1)), dp1(tmp.size(), vector<int>(n2 + 1, -1));
    dp0[0][0] = 0;
    dp1[0][0] = 0;
    for(int i = 1; i < tmp.size(); i++){
        int id = tmp[i];
        for(int j = cnt0[id]; j <= n2; j++){
            if(dp0[i - 1][j - cnt0[id]] != -1) dp0[i][j] = 0;
            else if(dp1[i - 1][j - cnt0[id]] != -1) dp0[i][j] = 1;
        }
        for(int j = cnt1[id]; j <= n2; j++){
            if(dp1[i - 1][j - cnt1[id]] != -1) dp1[i][j] = 1;
            else if(dp0[i - 1][j - cnt1[id]] != -1) dp1[i][j] = 0;
        }
    }

    vector<vector<bool>> two(n + 1, vector<bool>(2));
    int now = tmp.size() - 1, c, t = n2;
    if(dp0.back()[n2] != -1) c = 0;
    else if(dp1.back()[n2] != -1) c = 1;
    else{
        cout << "NO\n";
        return 0;
    }

    while(now > 0){
        two[tmp[now]][c] = true;
        int nt = t;
        if(c == 0) nt -= cnt0[tmp[now]];
        else nt -= cnt1[tmp[now]];
        c = c ? dp1[now][t] : dp0[now][t];
        t = nt;
        now--;
    }

    string ans(n, ' ');
    for(int i = 0; i < n; i++){
        if(two[l[i + 1].F][l[i + 1].S]) ans[i] = '2';
    }

    for(int i = 0; i < n && n1; i++){
        if(ans[i] != ' ') continue;
        ans[i] = '1';
        n1--;
    }

    for(int i = 0; i < n && n3; i++){
        if(ans[i] != ' ') continue;
        ans[i] = '3';
        n3--;
    }

    cout << "YES\n";
    cout << ans << "\n";

    return 0;
}