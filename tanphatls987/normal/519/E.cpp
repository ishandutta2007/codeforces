#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("a.inp","r",stdin)
#define OUTPUT freopen("a.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=1e5+10;

int n,q,x,y,p[N][20],f[N],lv[N]={0};
vector <int> a[N];
void DFS(int par,int x){
    f[x]=1;
    lv[x]=lv[par]+1;
    p[x][0]=par;
    for(auto y:a[x]) if (y!=par){
        DFS(x,y);
        f[x]+=f[y];
    }
}
int LCA(int x,int y){
    if (lv[x]<lv[y]) swap(x,y);
    FORD(i,18,0) if (lv[p[x][i]]>=lv[y]) x=p[x][i];
    //printf("%d %d %d\n",x,y,p[x][0]);
    if (x==y) return x;
    FORD(i,18,0) if (p[x][i]!=p[y][i]&&p[x][i])
        x=p[x][i],y=p[y][i];
    return p[x][0];
}
int findpar(int x,int len){
    for(int i=0;(1<<i)<=len;i++) if (len&(1<<i)) x=p[x][i];
    return x;
}
int solve(int x,int y){
    if (x==y) return n;
    int z=LCA(x,y),ans=0;
    if (z==x||z==y){
        if (z==x) swap(x,y);
        int len=lv[x]-lv[y];
        if (len%2==0){
            int G=findpar(x,len/2),G1=findpar(x,len/2-1);
            ans=f[G]-f[G1];
        }
    }else{
        int dis=lv[x]+lv[y]-2*lv[z];
        if (dis%2==0){
            if (lv[x]==lv[y]){
                int G1=findpar(y,lv[y]-lv[z]-1),G2=findpar(x,lv[x]-lv[z]-1);
                ans=n-f[G1]-f[G2];
            }else if (dis/2<lv[x]-lv[z]){
                int G=findpar(x,dis/2),G1=findpar(x,dis/2-1);
                ans=f[G]-f[G1];
            }else{
                int G=findpar(y,dis/2),G1=findpar(y,dis/2-1);
                ans=f[G]-f[G1];
            }
        }
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    FOR(i,2,n){
        scanf("%d%d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    DFS(0,1);
    FOR(i,1,18)
        FOR(x,1,n) p[x][i]=p[p[x][i-1]][i-1];
        //FOR(i,1,n) cout<<f[i]<<" \n"[i==n];
    scanf("%d",&q);
    while (q--){
        scanf("%d%d",&x,&y);
        printf("%d\n",solve(x,y));
    }
}