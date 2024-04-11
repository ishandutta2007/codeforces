#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

ll ccw(pll a, pll b, pll c) {
    return a.x*b.y+b.x*c.y+c.x*a.y-a.y*b.x-b.y*c.x-c.y*a.x;
}

struct cht {
    vector<pll> vec;
    void init() {
        vec.clear();
    }
    void add(ll a, ll b) {
        if (!vec.empty()&&vec.back().x==a) return;
        while(vec.size()>=2&&ccw(vec[(int)vec.size()-1],vec.back(),pll(a,b))<=0) vec.pop_back();
        vec.push_back(pll(a,b));
    }
    ll getv(ll x) {
        if (vec.empty()) return LINF;
        int s = 0, e = (int)vec.size()-2;
        while(s<=e) {
            int m = (s+e)/2;
            if (x*(vec[m+1].x-vec[m].x)<(vec[m].y-vec[m+1].y)) s = m+1;
            else e = m-1;
        }
        return vec[s].x*x+vec[s].y;
    }
} ch;

ll n;
ll sz[500100];
ll D[500100];
vector<int> lis[500100];

ll ans = LINF;
void dfs(int here, int p) {
    sz[here] = 1;
    vector<pll> vec;
    for (int &there : lis[here]) {
        if (there!=p) {
            dfs(there,here);
            sz[here] += sz[there];
            vec.push_back(pll(sz[there]*2,sz[there]*sz[there]-2*n*sz[there]+D[there]));
        }
    }
    sort(vec.begin(),vec.end());
    D[here] = sz[here]*sz[here];
    for (int &there : lis[here]) {
        if (there!=p) {
            D[here] = min(D[here],D[there]+(sz[here]-sz[there])*(sz[here]-sz[there]));
            ans = min(ans,D[there]+(n-sz[there])*(n-sz[there]));
        }
    }
    ch.init();
    for (pll &t : vec) {
        //printf("%lld, %lld!\n",t.x,t.y);
        ans = min(ans,ch.getv(t.x/2)+t.y+n*n);
        //printf("!");
        ch.add(t.x,t.y);
    }
}

int main() {
    int i;

    scanf("%lld",&n);
    for (i=0;i<n-1;i++) {
        int a, b;
        scanf("%d%d",&a,&b); --a; --b;
        lis[a].push_back(b);
        lis[b].push_back(a);
    }
    dfs(0,-1);
    printf("%lld\n",n*(n-1)/2+(n*n-ans)/2);

    return 0;
}