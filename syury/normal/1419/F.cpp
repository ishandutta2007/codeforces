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

struct pt{
    int x, y, i;
    bool operator < (const pt & p)const{
        return x == p.x ? y < p.y : x < p.x;
    }
};

struct Edge{
    int v, u, w;
    bool operator < (const Edge & e)const{
        return w < e.w;
    }
};

const int N = (int)1e3 + 3;
const int P = 2*N*N;

int n;
int comp[N];
Edge e[4*N];
int se = 0;
int x[N], y[N];
int idl[N][N];
int idr[N][N];
int nxt[P][4];
bool was[N];
int sz = 0;
int real_id[P];
pt p[P];
pt px[N], py[N];
uint8_t mask[P];

void preprocess(){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(x[i] != x[j] && y[i] != y[j]){
                p[sz] = pt{x[i], y[j], sz};
                idl[i][j] = idl[j][i] = sz;
                ++sz;
                p[sz] = pt{x[j], y[i], sz};
                idr[i][j] = idr[j][i] = sz;
                ++sz;
            }
            else{
                idl[i][j] = idl[j][i] = sz;
                idr[i][j] = idr[j][i] = -1;
                if(x[i] == x[j]){
                    p[sz] = pt{x[i], (y[i] + y[j])/2, sz};
                    ++sz;
                }
                else{
                    p[sz] = pt{(x[i] + x[j])/2, y[i], sz};
                    ++sz;
                }
            }
        }
    }
    sort(p, p + sz);
    int ptr = 0;
    int bptr = 0;
    while(ptr < sz){
        int ptr2 = ptr;
        while(ptr2 < sz && !(p[ptr] < p[ptr2])){
            real_id[p[ptr2].i] = bptr;
            ++ptr2;
        }
        swap(p[bptr++], p[ptr]);
        ptr = ptr2;
    }
    sz = bptr;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            idl[i][j] = idl[j][i] = real_id[idl[i][j]];
            idr[i][j] = idr[j][i] = (idr[i][j] == -1 ? -1 : real_id[idr[i][j]]);
        }
    }
    for(int i = 0; i < n; i++){
        px[i] = pt{x[i], y[i], i};
        py[i] = pt{y[i], x[i], i};
    }
    sort(px, px + n);
    sort(py, py + n);
    for(int i = 0; i < sz; i++){
        //0 up
        //1 right
        //2 down
        //3 left
        fill(nxt[i], nxt[i] + 4, -1);
        int ix = lower_bound(px, px + n, p[i]) - px;
        int iy = lower_bound(py, py + n, pt{p[i].y, p[i].x, p[i].i}) - py;
        if(ix < n && px[ix].x == p[i].x){
            if(px[ix].y == p[i].y){
                continue;
            }
            nxt[i][0] = px[ix].i;
        }
        if(ix > 0 && px[ix - 1].x == p[i].x){
            nxt[i][2] = px[ix - 1].i;
        }
        if(iy < n && py[iy].x == p[i].y){
            nxt[i][1] = py[iy].i;
        }
        if(iy > 0 && py[iy - 1].x == p[i].y){
            nxt[i][3] = py[iy - 1].i;
        }
    }
    for(int i = 1; i < n; i++){
        if(px[i - 1].x == px[i].x){
            e[se++] = Edge{px[i - 1].i, px[i].i, abs(px[i - 1].y - px[i].y)};
        }
    }
    for(int i = 1; i < n; i++){
        if(py[i - 1].x == py[i].x){
            e[se++] = Edge{py[i - 1].i, py[i].i, abs(py[i - 1].y - py[i].y)};
        }
    }
    sort(e, e + se);
}

struct dsu{
    vector<int> p;
    dsu(int n):p(n){
        iota(all(p), 0);
    }
    int get(int v){
        return v == p[v] ? v : p[v] = get(p[v]);
    }
    void unite(int v, int u){
        v = get(v);
        u = get(u);
        if(v == u)
            return;
        p[v] = u;
    }
};

bool can(int t){
    dsu s(n);
    for(int i = 0; i < se; i++){
        if(e[i].w > t)
            break;
        s.unite(e[i].v, e[i].u);
    }
    set<int> all_comps;
    for(int i = 0; i < n; i++){
        int v = s.get(i);
        all_comps.insert(v);
        comp[i] = v;
        if(all_comps.size() > 4u)
            return false;
    }
    if(all_comps.size() == 1u)
        return true;
    for(int i = 0; i < sz; i++){
        int cu = 0;
        for(int c = 0; c < 4; c++){
            int v = nxt[i][c];
            if(v == -1 || abs(p[i].x - x[v]) + abs(p[i].y - y[v]) > t)continue;
            if(!was[comp[v]])++cu;
            was[comp[v]] = 1;
        } 
        for(int c = 0; c < 4; c++){
            int v = nxt[i][c];
            if(v == -1 || abs(p[i].x - x[v]) + abs(p[i].y - y[v]) > t)continue;
            was[comp[v]] = 0;
        }
        if(cu == all_comps.size())
            return true;
    }
    return false;
}

//#define TEST

void solve(){
#ifdef TEST
    n = 1000;
#else
    cin >> n;
#endif
    for(int i = 0; i < n; i++)
#ifdef TEST
        x[i] = y[i] = i;
#else
        cin >> x[i] >> y[i];
#endif
    preprocess();
    uint32_t L = 0, R = (uint32_t)2e9 + 9;
    if(!can(R)){
        cout << -1;
        return;
    }
    while(R - L > 1){
        uint32_t mid = (L + R)/2;
        if(can(mid))
            R = mid;
        else
            L = mid;
    }
    cout << R << endl;
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(3);
    int T=1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}