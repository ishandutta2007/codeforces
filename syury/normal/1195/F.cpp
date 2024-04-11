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

struct pt{
    ll x, y;
    pt operator - (const pt & p)const{
        return pt{x - p.x, y - p.y};
    }
    inline ll cross(const pt & p)const{
        return x * p.y - y * p.x;
    }
    inline char half()const{
        return char(y < 0 || (!y && x < 0));
    }
    inline bool operator < (const pt & p)const{
        return half() == p.half() ? cross(p) > 0 : half() < p.half();
    }
    inline bool operator == (const pt & p)const{
        return half() == p.half() && cross(p) == 0;
    }
};

const int N = (int)3e5 + 55;

pt sides[N];
int sz = 0;
int n;
vector<pt> p[N];
vector<int> s[N];
vector<int> occ[N];
size_t ptr[N];
int t[N];

void add(int v, int d){
    ++v;
    while(v < N){
        t[v] += d;
        v += v&-v;
    }
}

int get(int r){
    ++r;
    int ans = 0;
    while(r > 0){
        ans += t[r];
        r -= r&-r;
    }
    return ans;
}

void solve(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int cu;
        scanf("%d", &cu);
        p[i].resize(cu);
        for(int j = 0; j < cu; j++)
            scanf("%lld%lld", &p[i][j].x, &p[i][j].y);
        int pos = 0;
        for(int j = 1; j < cu; j++){
            if(p[i][j].y < p[i][pos].y || (p[i][j].y == p[i][pos].y && p[i][j].x < p[i][pos].x))
                pos = j;
        }
        rotate(p[i].begin(), p[i].begin() + pos, p[i].end());
        for(int j = 1; j <= cu; j++){
            int pos = j%cu;
            pt vec = p[i][pos] - p[i][j - 1];
            sides[sz++] = vec;
        }
    }
    sort(sides, sides + sz);
    sz = unique(sides, sides + sz) - sides;
    for(int i = 0; i < n; i++){
        s[i].resize(p[i].size());
        for(int j = 1; j <= (int)p[i].size(); j++){
            int pos = j%p[i].size();
            pt vec = p[i][pos] - p[i][j - 1];
            s[i][j - 1] = lower_bound(sides, sides + sz, vec) - sides;
            occ[s[i][j - 1]].push_back(i);
        }
    }
    for(int i = 0; i < sz; i++){
        sort(all(occ[i]));
        if(!occ[i].empty()){
            add(occ[i][0], 1);
        }
    }
    int q;
    scanf("%d", &q);
    vector<int> ans(q);
    vector<tuple<int, int, int> > qs(q);
    for(int i = 0; i < q; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        --l; --r;
        qs[i] = {l, r, i};
    }
    sort(all(qs));
    size_t qp = 0;
    for(int i = 0; i < n; i++){
        while(qp < qs.size() && get<0>(qs[qp]) == i){
            ans[get<2>(qs[qp])] = get(get<1>(qs[qp]));
            ++qp;
        }
        for(auto x: s[i]){
            add(i, -1);
            while(ptr[x] < occ[x].size() && occ[x][ptr[x]] == i)
                ++ptr[x];
            if(ptr[x] < occ[x].size())
                add(occ[x][ptr[x]], 1);
        }
    }
    for(int i = 0; i < q; i++)
        printf("%d\n", ans[i]);
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    int T = 1;
    while(T--)
        solve();
    return 0;
}