//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define move fjgjgjgjghd

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)3e5 + 5;

int n, k;
vector<int> who[N];
vector<int> what[N];
int p[N];
int sz[N];
int weight[N];
bool col[N];
int fix[N];
int neq[N];
ll ans = 0;
vector<int> comp[N];
string s;

inline int current_answer(int root){
    if(fix[root] == -1){
        return min(neq[root], sz[root] - neq[root]);
    }
    else{
        if(fix[root] == 1)
            return sz[root] - neq[root];
        else
            return neq[root];
    }
}

inline int get(int v){
    return v == p[v] ? v : get(p[v]);
}

inline void fix_color(int v, int c){
    int root = get(v);
    ans -= current_answer(root);
    if(col[v]){
        fix[root] = c;
    }
    else{
        fix[root] = c^1;
    }
    ans += current_answer(root);
}

inline void make_edge(int v, int u, bool eq){
    if(get(v) == get(u))
        return;
    if(sz[get(v)] < sz[get(u)])
        swap(v, u);
    int pv = get(v);
    int pu = get(u);
    ans -= current_answer(pv);
    ans -= current_answer(pu);
    eq ^= col[v];
    eq ^= col[u];
    p[pu] = pv;
    sz[pv] += sz[pu];
    if(!eq){
        I(w, comp[pu])
            col[w] ^= 1;
        neq[pv] += sz[pu] - neq[pu];
        if(fix[pu] != -1)
            fix[pv] = 1^fix[pu];
    }
    else{
        neq[pv] += neq[pu];
        if(fix[pu] != -1)
            fix[pv] = fix[pu];
    }
    I(w, comp[pu])
        comp[pv].pb(w);
    ans += current_answer(pv);
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    cin >> s;
    F(i, 0, k){
        int sz;
        cin >> sz;
        what[i].resize(sz);
        F(j, 0, sz){
            cin >> what[i][j];
            --what[i][j];
            who[what[i][j]].pb(i);
        }
        comp[i].pb(i);
    }
    fill(col, col + k, true);
    fill(fix, fix + k, -1);
    fill(sz, sz + k, 1);
    iota(p, p + k, 0);
    F(i, 0, n){
        if(who[i].empty()){
            cout << ans << '\n';
            cont;
        }
        if(who[i].size() == 1u){
            if(s[i] == '1'){
                fix_color(who[i][0], 0);
            }
            else{
                fix_color(who[i][0], 1);
            }
        }
        else{
            int v = who[i][0], u = who[i][1];
            if(s[i] == '1')
                make_edge(v, u, 1);
            else
                make_edge(v, u, 0);
        }
        cout << ans << '\n';
    }
    return 0;
}