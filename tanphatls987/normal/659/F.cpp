#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("F.inp","r",stdin)
#define OUTPUT freopen("F.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e3+10;
const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

int n,m,n1;
ll k;
int t[N*N],ans[N][N],a[N][N],p[N*N];
ii q[N*N];
vector <ii> v[N*N];

bool check(int x,int y){
    return x>=0&&x<n&&y>=0&&y<m;
}
int cv(int x,int y){
    return x*m+y;
}
ii topair(int x){
    return ii(x/m,x%m);
}
int root(int x){
    if (t[x]<0) return x;
    t[x]=root(t[x]);
    return t[x];
}
void merge(int x,int y){
    x=root(x),y=root(y);
    if (x==y) return;
    if (t[x]>t[y]) swap(x,y);
    t[x]+=t[y];
    t[y]=x;
}
void prepare(){
    scanf("%d%d%lld",&n,&m,&k);
    REP(i,0,n)
        REP(j,0,m) scanf("%d",a[i]+j);
    REP(i,0,n)
        REP(j,0,m) p[i*m+j]=a[i][j];
    sort(p,p+n*m);
    n1=unique(p,p+n*m)-p;
    REP(i,0,n)
        REP(j,0,m){
            int idx=lower_bound(p,p+n1,a[i][j])-p;
            v[idx].push_back(ii(i,j));
        }
    memset(t,-1,sizeof(t));
}
void trace(int sx,int sy){
    ll need=k/a[sx][sy];
    int top=1,bot=1;
    q[1]=ii(sx,sy);
    ans[sx][sy]=a[sx][sy];
    while (top<=bot){
        ii cur=q[top++];
        FOR(dir,0,3){
            int nx=cur.X+dx[dir],ny=cur.Y+dy[dir];
            if (check(nx,ny)&&a[nx][ny]>=a[sx][sy]&&!ans[nx][ny]&&bot<need){
                ans[nx][ny]=a[sx][sy];
                q[++bot]=ii(nx,ny);
            }
        }
    }
    REP(i,0,n){
        REP(j,0,m) printf("%d ",ans[i][j]);
        ENDL;
    }
}
void solve(){
    FORD(pha,n1-1,0){
        for(auto i:v[pha]){
            int cur=cv(i.X,i.Y);
            FOR(dir,0,3){
                int nx=i.X+dx[dir],ny=i.Y+dy[dir];
                if (!check(nx,ny)||a[nx][ny]<p[pha]) continue;
                merge(cur,cv(nx,ny));
            }
            if (k%p[pha]==0){
                int rcur=root(cur);
                ll need=k/p[pha];
                if (-t[rcur]>=need){
                    printf("YES\n");
                    trace(i.X,i.Y);
                    return;
                }
            }
        }
    }
    printf("NO");
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    solve();
}