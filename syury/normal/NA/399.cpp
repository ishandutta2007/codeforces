//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int BLOCK = 350;
const int N = (int)3e5 + 55;

struct Query{
    int tp, pos, val;
};

int n, q;
int V = 1;
int link[N];
int len[N];
int nxt[N][26];
int where[N];
int value[N];
int path[N];
int que[N];
int tin[N], tout[N];
vector<int> gr[N];
int L[N], R[N];
int iL[N], iR[N];
int tsz = 0;
vector<int> kek[N];
int gt = 0;

int add_string(string s){
    int v = 0;
    for(char c: s){
        int pos = c - 'a';
        if(nxt[v][pos] == -1)
            nxt[v][pos] = V++;
        v = nxt[v][pos];
    }
    return v;
}

void build_aho(){
    int qh = 0, qt = 1;
    que[0] = 0;
    while(qh < qt){
        int v = que[qh++];
        for(int c = 0; c < 26; c++){
            if(nxt[v][c] == -1){
                nxt[v][c] = v ? nxt[link[v]][c] : 0;
            }
            else{
                link[nxt[v][c]] = v ? nxt[link[v]][c] : 0;
                que[qt++] = nxt[v][c];
            }
        }
    }
}

void dfs(int v){
    tin[v] = gt++;
    L[v] = R[v] = tsz++;
    for(int u: gr[v]){
        dfs(u);
        R[v] = max(R[v], R[u]);
    }
    for(int i: kek[v]){
        iL[i] = L[v];
        iR[i] = R[v];
    }
    tout[v] = gt++;
}

struct Tree{
    int n;
    vector<multiset<int, greater<int>>> vals;
    vector<int> t;
    Tree(int _n):n(_n), vals(4*n+3), t(4*n+3, -1){}
    void upd(int v, int l, int r, int ul, int ur, int oldval, int val){
        if(l == ul && r == ur){
            if(oldval != -1)
                vals[v].erase(vals[v].find(oldval));
            vals[v].insert(val);
            t[v] = *vals[v].begin();
            return;
        }
        if(ul > ur)return;
        int mid = (l + r)/2;
        upd(2*v, l, mid, ul, min(ur, mid), oldval, val);
        upd(2*v+1, mid+1, r, max(ul, mid+1), ur, oldval, val);
    }
    int get(int v, int l, int r, int pos){
        if(l == r)
            return t[v];
        int mid = (l + r)/2;
        return max(t[v], pos <= mid ? get(2*v, l, mid, pos) : get(2*v+1, mid+1, r, pos));
    }
};

void solve(){
    fill(link, link + N, -1);
    for(int i = 0; i < N; i++)
        fill(nxt[i], nxt[i] + 26, -1);
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        where[i] = add_string(s);
        kek[where[i]].push_back(i);
    }
    build_aho();
    for(int i = 1; i < V; i++)
        gr[link[i]].push_back(i);
    dfs(0);
    fill(value, value + n, 0);
    Tree t(V);
    for(int i = 0; i < n; i++){
//        cerr << iL[i] << ' ' << iR[i] << endl;
        t.upd(1, 0, V - 1, iL[i], iR[i], -1, 0);
    }
    for(int i = 0; i < q; i++){
        int tp;
        cin >> tp;
        if(tp == 1){
            int pos, val;
            cin >> pos >> val;
            --pos;
            t.upd(1, 0, V - 1, iL[pos], iR[pos], value[pos], val);
            value[pos] = val;
        }
        else{
            string s;
            cin >> s;
            int ans = -1;
            int v = 0;
            for(char c: s){
                v = nxt[v][c - 'a'];
                ans = max(ans, t.get(1, 0, V - 1, L[v]));
            }
            cout << ans << '\n';
        }
    }
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(16);
    int T = 1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}