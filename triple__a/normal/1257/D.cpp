#include<bits/stdc++.h>
//#define int long long
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
int t,n,m;
int pw[maxn],a[maxn];
int main(){
    scanf("%d",&t);
    while (t--){
        scanf("%d",&n);
        rep1(i,n) scanf("%d",&a[i]);
        rep1(i,n) pw[i]=0;
        scanf("%d",&m);
        rep1(i,m){
            int u,v;
            scanf("%d%d",&u,&v);
            pw[v]=max(pw[v],u);
        }
        int ret=0,ans=0;
        for (int i=n;i>0;--i){
            pw[i]=max(pw[i],ret);
            ret=max(pw[i],ret);
        }
        int i=1,mx=0,j=0;
        while (i<=n){
            mx=0,j=0;
            while (i+j<=n){
                mx=max(mx,a[i+j]);
                if (pw[j+1]<mx) break;
                j++;
            }
            if (!j){
                printf("-1\n");
                goto cont;
            }
            ans++;
            i+=j;
        }
        printf("%d\n",ans);
        cont:;
    }
    return 0;
}