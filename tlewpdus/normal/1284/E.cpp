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
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}

int n;
pll arr[3000];
int loc[3000];
int ord[3000];

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%lld%lld",&arr[i].first,&arr[i].second);
    sort(arr,arr+n);
    vector<pii> slo;
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            slo.push_back({i,j});
        }
    }
    sort(slo.begin(),slo.end(),[](pii a, pii b){
            ll v = ccw({0,0},{arr[a.y].x-arr[a.x].x,arr[a.y].y-arr[a.x].y},
                            {arr[b.y].x-arr[b.x].x,arr[b.y].y-arr[b.x].y});
            if (v) return v>0;
            return a<b;
         });
    ll ans = 0;
    iota(ord,ord+n,0);
    iota(loc,loc+n,0);
    for (int i=0;i<slo.size();i++) {
        pii v = slo[i];
        ll w = n-1-max(loc[v.x],loc[v.y]);
        ans += w*(w-1)*(w-2)/6;
        w = min(loc[v.x],loc[v.y]);
        ans += w*(w-1)*(w-2)/6;
        swap(loc[v.x],loc[v.y]);
        swap(ord[loc[v.x]],ord[loc[v.y]]);
    }
    printf("%lld\n",1LL*n*(n-1)*(n-2)*(n-3)*(n-4)/24-ans);

	return 0;
}