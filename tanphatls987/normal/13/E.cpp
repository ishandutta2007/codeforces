#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("13e.inp","r",stdin)
#define OUTPUT freopen("13e.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e5+10,M=300;

int n,m,x,y,f[N],re[N],h[N]={0},w[N],p[N],near[N],pos[N],t[N];
ii q[N];
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",w+i),w[i]=min(w[i],n+1-i);
    FOR(i,1,m){
        scanf("%d%d",t+i,&q[i].X);
        if (!t[i]) scanf("%d",&q[i].Y);
    }
    for(int st=1;st<=m;st+=M){
        int next=min(st+M-1,m),top=0;
        FOR(i,st,next) if (!t[i]) h[q[i].X]=st;
        h[n+1]=st;
        FORD(i,n,1) if (h[i]!=st){
            if (h[i+w[i]]==st) near[i]=i+w[i];
            else near[i]=near[i+w[i]];
            f[i]=f[i+w[i]]+1;
            if (i+w[i]<=n) re[i]=re[i+w[i]];
            else re[i]=i;
        }else f[i]=0;
        //FOR(i,1,n) cout<<re[i]<<" \n"[i==n];
        //FOR(i,1,n) cout<<f[i]<<" \n"[i==n];
        FOR(i,st,next) if (t[i]){
            int x=q[i].X,ans1=0,ans2=0;

            while (x<=n){
            //    printf("%d %d %d %d\n",i,x,ans1,ans2);
                if (h[x]==st){
                    if (x+w[x]>n) ans2=x;
                    x+=w[x];
                    ans1++;
                }else{
                    ans2=re[x];
                    ans1+=f[x];
                    x=near[x];
                }
            }
            printf("%d %d\n",ans2,ans1);
        }else{
            int x=q[i].X;
            w[x]=min(q[i].Y,n-x+1);
        }
    }
}