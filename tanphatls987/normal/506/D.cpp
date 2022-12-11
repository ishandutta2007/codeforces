#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("506d.inp","r",stdin)
#define OUTPUT freopen("506d.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,int> lli;

const int inf=1e9;
const int MOD=1e9+7,BAR=1e7;
const int N=1e5+10;

int n,m,k,x,y,w,ans[N],h[N],t[N],q[N],s[N],g[N];
ll p[N];
ii qu[N];
vector <ii> e[N];
vector <int> a[N];
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m) {
        scanf("%d%d%d",&x,&y,&w);
        e[w].push_back(ii(x,y));
    }
    scanf("%d",&k);
    FOR(i,1,k){
        scanf("%d%d",&qu[i].X,&qu[i].Y);
        if (qu[i].X>qu[i].Y) swap(qu[i].X,qu[i].Y);
        p[i]=1LL*qu[i].X*BAR+qu[i].Y;
    }
    sort(p+1,p+k+1);
    int k1=unique(p+1,p+k+1)-p-1;
    FOR(C,1,m){
        int type=(e[C].size()>=300);
        int Vt=0;
        for(auto j:e[C]){
            a[j.X].push_back(j.Y);
            if (g[j.X]!=C) s[++Vt]=j.X,g[j.X]=C;
            a[j.Y].push_back(j.X);
            if (g[j.Y]!=C) s[++Vt]=j.Y,g[j.Y]=C;
        }
        int c=0;
        for(int i1=1,cx=s[1];i1<=Vt;cx=s[++i1]) if (h[cx]!=C){
            int top=1,bot=1;
            q[top]=cx;
            h[cx]=C;
            t[cx]=++c;
            while (top<=bot){
                int x=q[top++];
                for(auto y:a[x]) if (h[y]!=C){
                    h[y]=C;t[y]=c;
                    q[++bot]=y;
                }
            }
            //printf("%d %d\n",c,)
            if (!type)
                REP(i,1,bot)
                    FOR(j,i+1,bot){
                        int x=q[i],y=q[j];
                        if (x>y) swap(x,y);
                        ll val=1LL*x*BAR+y;
                        int pos=upper_bound(p+1,p+k1+1,val)-p-1;
                        if (p[pos]==val) ans[pos]++;
                    }
        }
        FOR(i,1,Vt) a[s[i]].clear();
        if (type) FOR(i,1,k1) if (h[p[i]/BAR]==C&&h[p[i]%BAR]==C&&t[p[i]/BAR]==t[p[i]%BAR]) ans[i]++;
    }
    FOR(i,1,k){
        if (qu[i].X>qu[i].Y) swap(qu[i].X,qu[i].Y);
        ll val=1LL*qu[i].X*BAR+qu[i].Y;
        int R=lower_bound(p+1,p+k1+1,val)-p;
        printf("%d\n",ans[R]);
    }
}