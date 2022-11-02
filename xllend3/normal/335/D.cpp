/*
Date: 2014/11/25 13:39:12 Tuesday
Author: xllend3
*/
#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define ph push
#define pb push_back
#define REP(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define DEP(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
#define rep(i,a,n) for(int i=(a);i<=(n);++i)
#define dep(i,a,n) for(int i=(a);i>=(n);--i)
#define ALL(x,S) for(__typeof((S).end()) x=S.begin();x!=S.end();x++)
#define eps 1e-8
#define pi 3.1415926535897
#define sqr(x) ((x)*(x))
#define MAX(a,b) a=max(a,b)
#define MIN(a,b) a=min(a,b)
#define SZ(x) ((int)(x).size())
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define POSIN(x,y) (1<=(x)&&(x)<=n&&1<=(y)&&(y)<=m)
#define all(x) (x).begin(),(x).end()
#define COUT(S,x) cout<<fixed<<setprecision(x)<<S<<endl
typedef long long ll;
typedef double lf;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<lf,lf> pff;
typedef complex<double> CD;
const int inf=0x20202020;
const int mod=1000000007;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
template<class T> inline void read(T&x,T&y,T&z,T&q){read(x);read(y);read(z);read(q);}
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//*******************************************
#define y1 youginzi
const int N=3333,M=3010,NN=111111;
int l,m,n,t,C,tot,x1,y1,x2,y2;
pii fi[NN];
pair<pii,pii>a[NN];
vector<int>ans;
int row[N][N],col[N][N],vis[N][N];
int main(){
    //ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("CF335D.in","r",stdin);//freopen("CF335D.out","w",stdout);
#endif
    scanf("%d",&n);rep(i,1,n){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        fi[++tot]=mp(x1,y1);//fi[++tot]=mp(x2,y1);fi[++tot]=mp(x1,y2);fi[++tot]=mp(x2,y2);
        rep(i,x1+1,x2)rep(j,y1+1,y2)vis[i][j]=1;
        rep(i,x1+1,x2)col[i][y1]=col[i][y2]=1;
        rep(i,y1+1,y2)row[x1][i]=row[x2][i]=1;
        a[i]=mp(mp(x1,y1),mp(x2,y2));
    }
#ifdef LOCAL
    rep(i,0,10){rep(j,0,10)printf("%d ",vis[i][j]);puts("");}puts("");
    rep(i,0,10){rep(j,0,10)printf("%d ",row[i][j]);puts("");}puts("");
    rep(i,0,10){rep(j,0,10)printf("%d ",col[i][j]);puts("");}puts("");
#endif
    rep(i,1,M)rep(j,1,M)vis[i][j]+=vis[i-1][j]+vis[i][j-1]-vis[i-1][j-1];
    rep(i,0,M)rep(j,0,M){if(i)col[i][j]+=col[i-1][j];if(j)row[i][j]+=row[i][j-1];}
    rep(i,1,tot){
        int x=fi[i].x,y=fi[i].y;
        rep(j,1,M){
            //printf("%d %d %d\n",x,y,j);
            if(vis[x+j][y+j]-vis[x][y+j]-vis[x+j][y]+vis[x][y]!=j*j)break;
            //printf("%d %d %d\n",x,y,j);
            if(col[x+j][y]-col[x][y]!=j)break;
            //printf("%d %d %d\n",x,y,j);
            if(row[x][y+j]-row[x][y]!=j)break;
            //printf("%d %d %d\n",x,y,j);
            if(col[x+j][y+j]-col[x][y+j]==j&&row[x+j][y+j]-row[x+j][y]==j){
                rep(i,1,n)if(a[i].x.x>=x&&a[i].x.y>=y&&a[i].y.x<=x+j&&a[i].y.y<=y+j)ans.pb(i);
                printf("YES %d\n",SZ(ans));
                rep(i,0,SZ(ans)-1)printf("%d ",ans[i]);puts("");
                //if(ans[0]==49)printf("%d %d %d\n",x,y,j);
                return 0;
            }
        }
    }puts("NO");
    return 0;
}