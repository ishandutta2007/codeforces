//#define NDEBUG

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
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

//#define TEST

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

vector<vector<int>> g;
vector<int> ans, vst;

void dfs(int now){
    vst[now] = 1;
    ans[now] = 1;
    for(int i : g[now]){
        if(vst[i] == 1){
            cout << "No\n";
            exit(0);
        }
        if(vst[i] != 2) dfs(i);
        ans[now] = max(ans[now], ans[i] + 1);
    }
    vst[now] = 2;
}


int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    vector<vector<int>> tg(n + m);
    vector<string> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
        for(int j = 0; j < m; j++){
            if(s[i][j] == '=') tg[i].eb(n + j), tg[n + j].eb(i);
        }
    }

    vector<int> id(n + m, -1);
    int ts = 0;
    for(int i = 0; i < n + m; i++){
        if(id[i] != -1) continue;
        queue<int> q;
        q.push(i);
        id[i] = ts;
        while(!q.empty()){
            int now = q.front();
            q.pop();
            for(int j : tg[now]){
                if(id[j] != -1) continue;
                id[j] = ts;
                q.push(j);
            }
        }
        ts++;
    }
//    printv(id, cerr);

    g.resize(ts);
    ans.resize(ts);
    vst.resize(ts);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] == '<') g[id[n + j]].eb(id[i]);
            else if(s[i][j] == '>') g[id[i]].eb(id[n + j]);
        }
    }
//    for(int i = 0; i < ts; i++){
//        cerr << i << "  ";
//        printv(g[i], cerr);
//    }

    for(int i = 0; i < ts;i++){
        if(vst[i] == 0) dfs(i);
    }

    cout << "Yes\n";
    for(int i = 0; i < n; i++) cout << ans[id[i]] << " ";
    cout << "\n";
    for(int i = n; i < n + m; i++) cout << ans[id[i]] << " ";
    cout << "\n";

    return 0;
}