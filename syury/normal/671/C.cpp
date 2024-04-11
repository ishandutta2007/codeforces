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
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)2e5 + 5;

struct seg{
    int l, r, val;
    bool operator < (const seg & s)const{
        if(l == s.l)
            return val > s.val;
        return l < s.l;
    }
};

const int inf = (int)1e9;

ll ans = 0;
int n;
int a[N];
vector<int> pos[N], who[N];
ll t[4*N], mi[4*N], sec[4*N], mic[4*N];
ll add[4*N];

inline void push(int v){
    if(!add[v])
        return;
    if(mi[2*v] < mi[v]){
        t[2*v] += add[v] * mic[2*v];
        mi[2*v] += add[v];
        add[2*v] += add[v];
    }
    if(mi[2*v + 1] < mi[v]){
        t[2*v + 1] += add[v] * mic[2*v + 1];
        mi[2*v + 1] += add[v];
        add[2*v + 1] += add[v];
    }
    add[v] = 0;
}

ll get(int v, int l, int r, int ul, int ur){
    if(ul > ur)
        return 0;
    if(l == ul && r == ur)
        return t[v];
    push(v);
    int mid = (l + r)/2;
    return get(2*v, l, mid, ul, min(ur, mid)) + get(2*v + 1, mid + 1, r, max(ul, mid + 1), ur);
}

void paint(int v, int l, int r, int ul, int ur, int x){
    if(ul > ur || mi[v] >= x)
        return;
    if(l == ul && r == ur && sec[v] > x){
        t[v] += (x - mi[v]) * mic[v];
        add[v] += x - mi[v];
        mi[v] = x;
        return;
    }
    push(v);
    int mid = (l + r)/2;
    paint(2*v, l, mid, ul, min(ur, mid), x);
    paint(2*v + 1, mid + 1, r, max(ul, mid + 1), ur, x);
    t[v] = t[2*v] + t[2*v + 1];
    mi[v] = min(mi[2*v], mi[2*v + 1]);
    mic[v] = mic[2*v] * int(mi[2*v] == mi[v]) + mic[2*v + 1] * int(mi[2*v + 1] == mi[v]);
    sec[v] = min(sec[2*v], sec[2*v + 1]);
    if(mi[2*v] != mi[v])
        sec[v] = min(sec[v], mi[2*v]);
    if(mi[2*v + 1] != mi[v])
        sec[v] = min(sec[v], mi[2*v + 1]);
}

ll setval(int l, int r, int x){
    ll old = get(1, 0, n - 1, l, r);
    paint(1, 0, n - 1, l, r, x);
    ll curr = get(1, 0, n - 1, l, r);
    return curr - old;
}

void build(int v, int l, int r){
    if(l == r){
        t[v] = mi[v] = l;
        mic[v] = 1;
        sec[v] = inf;
        return;
    }
    int mid = (l + r)/2;
    build(2*v, l, mid);
    build(2*v + 1, mid + 1, r);
    mi[v] = mi[2*v];
    mic[v] = 1;
    t[v] = t[2*v] + t[2*v + 1];
    sec[v] = min(sec[2*v], mi[2*v + 1]);
}

void solve(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", a + i);
        who[a[i]].push_back(i);
    }
    build(1, 0, n - 1);
    vector<seg> s;
    for(int d = 1; d < N; d++){
        for(int x = d; x < N; x += d){
            for(auto i: who[x])
                pos[d].push_back(i);
        }
        sort(all(pos[d]));
    }
    for(int d = N - 1; d >= 1; d--){
        if(pos[d].size() <= 1u)
            continue;
        ans += d * setval(pos[d][1] + 1, n - 1, n);
        ans += d * setval(pos[d][0] + 1, pos[d].size() == 2u ? pos[d][1] - 1 : pos[d][1], pos[d].back());
        ans += d * setval(0, pos[d].size() == 2u ? pos[d][0] - 1 : pos[d][0], pos[d][pos[d].size() - 2]);
        //cerr << ans << endl;
    }
    printf("%lld\n", ans);
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}