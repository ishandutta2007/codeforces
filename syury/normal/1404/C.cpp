//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
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
#define sz(a) ((int)a.size())

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef pair<int, int> pii;

const int N = (int)3e5 + 5;
const int inf = (int)1e9;

struct query{
    int x, y, i;
    bool operator < (const query & q)const{
        return x < q.x;
    }
};

struct FirstTree{
    vector<int> t;
    vector<int> tpos;
    vector<int> add;
    int n;
    FirstTree(int _n, vector<int> & arr):n(_n){
        t.resize(4*n + 3);
        tpos.resize(4*n + 3);
        add.resize(4*n + 3);
        build(1, 0, n - 1, arr);
    }
    inline void recalc(int v){
        if(t[2*v] < t[2*v+1]){
            t[v] = t[2*v];
            tpos[v] = tpos[2*v];
        }
        else{
            t[v] = t[2*v+1];
            tpos[v] = tpos[2*v+1];
        }
    }
    void build(int v, int l, int r, vector<int> & init){
        add[v] = 0;
        if(l == r){
            tpos[v] = l;
            t[v] = init[l];
            return;
        }
        int mid = (l + r)/2;
        build(2*v, l, mid, init);
        build(2*v+1, mid+1, r, init);
        recalc(v);
    }
    inline void push(int v){
        t[2*v] += add[v];
        add[2*v] += add[v];
        t[2*v+1] += add[v];
        add[2*v+1] += add[v];
        add[v] = 0;
    }
    void dec(int v, int l, int r, int ul, int ur){
        if(ul > ur)
            return;
        if(l == ul && r == ur){
            --add[v];
            --t[v];
            return;
        }
        push(v);
        int mid = (l + r)/2;
        dec(2*v, l, mid, ul, min(ur, mid));
        dec(2*v+1, mid+1, r, max(ul, mid+1), ur);
        recalc(v);
    }
    void setv(int v, int l, int r, int pos, int val){
        if(l == r){
            t[v] = val;
            return;
        }
        push(v);
        int mid = (l + r)/2;
        if(pos <= mid)
            setv(2*v, l, mid, pos, val);
        else
            setv(2*v+1, mid+1, r, pos, val);
        recalc(v);
    }
};

int n, q;
int a[N];
int f[N];
query qs[N];
int ans[N];
bool ok[N];
int fen[N];

void add(int x){
    ++x;
    while(x < N){
        ++fen[x];
        x += x&-x;
    }
}

void del(int x){
    ++x;
    while(x < N){
        --fen[x];
        x += x&-x;
    }
}

int get(int r){
    ++r;
    int ans = 0;
    while(r){
        ans += fen[r];
        r -= r&-r;
    }
    return ans;
}

void solve(){
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < q; i++){
        cin >> qs[i].x >> qs[i].y;
        qs[i].i = i;
    }
    sort(qs, qs + q);
    vector<int> delta(n);
    int tmp = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > i+1)
            delta[i] = inf;
        else{
            delta[i] = i+1 - a[i];
        }
    }
    FirstTree t1(n, delta);
    while(1){
        int best = t1.t[1];
        if(best > 0)
            break;
        int pos = t1.tpos[1];
        t1.dec(1, 0, n - 1, pos + 1, n - 1);
        t1.setv(1, 0, n - 1, pos, inf);
        f[pos] = 1;
    }
    set<pair<int, int> > s;
    int pref = 0;
    vector<int> bal(n);
    for(int i = 0; i < n; i++){
        if(f[i]){
            ok[i] = 1;
            add(i);
            bal[i] = -(i+1 - a[i] - pref);
        }
        else bal[i] = inf;
        pref += f[i];
    }
    int ptr = 0;
    FirstTree t2(n, bal);
    for(int i = 0; i < n; i++){
        while(ptr < q && qs[ptr].x == i){
            ans[qs[ptr].i] = get(n - 1 - qs[ptr].y);
            ++ptr;
        }
        if(ok[i]){
            ok[i] = 0;
            t2.setv(1, 0, n - 1, i, inf);
            t2.dec(1, 0, n - 1, i + 1, n - 1);
            del(i);
            while(1){
                int best = t2.t[1];
                if(best >= 0)break;
                int pos = t2.tpos[1];
                ok[pos] = 0;
                del(pos);
                t2.setv(1, 0, n - 1, pos, inf);
                t2.dec(1, 0, n - 1, pos + 1, n - 1);
            }
        }
    }
    for(int i = 0; i < q; i++)
        cout << ans[i] << '\n';
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}