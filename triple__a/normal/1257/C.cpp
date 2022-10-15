#include<bits/stdc++.h>
#define int long long
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
const int maxn=200007;
int l[maxn],ans[maxn];
int n,t;
#undef int
int main(){
    scanf("%lld",&t);
    while (t--){
        scanf("%lld",&n);
        rep1(i,n) l[i]=-n-1, ans[i]=n+7;
        rep1(i,n){
            int u;
            scanf("%d",&u);
            ans[u]=min(ans[u],i-l[u]);
            l[u]=i;
        }
        int ret=n+7;
        rep1(i,n){
            ret=min((ll)ret,ans[i]);
        }
        if (ret>n){
            printf("-1\n");
        }
        else{
            printf("%d\n",ret+1);
        }
    }
    return 0;
}