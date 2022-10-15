#include<bits/stdc++.h>
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int,int>

using namespace std;

typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/* DSU
int p[maxn]; // rep1(i,n) p[i]=i;

int find(int u){
    if (p[u]==u) return u;
    return p[u]=find(p[u]);
}

bool unite(int u,int v){
    int pu=find(u),pv=find(v);
    p[pu]=pv;
    return pu!=pv;
}
*/

const int maxn=100007;
int a[maxn],n,sum=0,q,t[maxn];
int main(){
    scanf("%d",&n);
    rep1(i,n){
        scanf("%d",&a[i]);
        if (a[i]) sum++;
    }
    if (sum==1){
        printf("-1");
        return 0;
    }
    int i=2;
    ll ret=1e18;
    for (;i<=sum;++i){
        if (sum%i==0){
            int cnt=0;
            ll ans=0;
            for (int j=1;j<=n;++j){
                if (a[j]) t[++cnt]=j;
                if (cnt==i){
                    for (int k=1;k<=cnt;++k){
                        ans+=abs(t[k]-t[(k+1)/2]);
                    }
                    cnt=0;
                }
            }
            ret=min(ret,ans);
        }
    }
    printf("%lld\n",ret);
    return 0;
}