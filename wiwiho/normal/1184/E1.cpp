#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define fr front()
#define po pop()
#define ba back()
#define F first
#define S second
#define printv(a, b) bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n"

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 1000000001;

int getP(vector<int>& p, int n){
    if(p[n] == n){
        return n;
    }
    p[n] = getP(p, p[n]);
    return p[n];
}

void unionP(vector<int>& p, int n, int m){
    int t1 = getP(p, n);
    int t2 = getP(p, m);
    p[t1] = t2;
}

int ans = -1;
void dfs(vector<vector<pair<int, int>>>& g, int now, int p, int mx, int fb){
    if(ans != -1){
        return;
    }
    if(now == fb){
        ans = mx;
        return;
    }
    for(pair<int, int> pa : g[now]){
        if(pa.F == p){
            continue;
        }
        //cerr << now << " " << pa.F << " " << mx << " " << pa.S << "\n";
        dfs(g, pa.F, now, max(mx, pa.S), fb);
    }
}

int main(){

    StarBurstStream
    
    int n, m;
    cin >> n >> m;

    int fa, fb, fe;
    cin >> fa >> fb >> fe;

    vector<pair<int, pair<int, int>>> edge(m);
    for(int i = 1; i < m; i++){
        int a, b, e;
        cin >> a >> b >> e;
        edge[i] = mp(e, mp(a, b));
    }

    lsort(edge);

    vector<vector<pair<int, int>>> g(n + 1); //<v, e>
    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++){
        p[i] = i;
    }

    for(pair<int, pair<int, int>> pa : edge){
        if(getP(p, pa.S.F) == getP(p, pa.S.S)){
            continue;
        }
        unionP(p, pa.S.F, pa.S.S);
        //cerr << "mst " << pa.S.F << " " << pa.S.S << "\n";
        g[pa.S.F].pb(mp(pa.S.S, pa.F));
        g[pa.S.S].pb(mp(pa.S.F, pa.F));
    }

    if(getP(p, fa) != getP(p, fb)){
        cout << "1000000000\n";
        return 0;
    }

    dfs(g, fa, fa, 0, fb);

    cout << ans << "\n";

    return 0;
}