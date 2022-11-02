#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define X first
#define Y second
#define mp make_pair
#define ph push
#define pb push_back
#define rep(i,a,n) for (int i = a; i <= (int)n; ++i)
#define dep(i,a,n) for (int i = a; i >= (int)n; --i)
#define re(b,a) for(a::iterator it=b.begin();it!=b.end();++it)
#define clr(a,b) memset(a,sizeof(a),b);
#define inf 0x7fffffff
#define eps 1e-8
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<lf,lf> pff;
inline void read(int &n)
{
    char c;
    for (c = getchar(); !(c >= '0' && c <= '9'); c = getchar());
    n = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';
}
const int N=1111;
int l,m,n,tot,cnt,a[N],tt,ttt;
lf t,tmp,f[N][N];
vector<lf>vec[N];
int eq(lf a,lf b){return fabs(a-b)<=1e-7;}
int find(int x){rep(i,0,a[x]-1)if(eq(vec[x][i],tmp))return 1;return 0;}
lf C(int y,int x){
    lf ans=1;rep(i,x-y+1,x)ans*=i;rep(i,1,y)ans/=i;return ans;
}
int main()
{
    scanf("%d%d",&m,&n);rep(i,1,n){
        scanf("%d",&a[i]);rep(j,1,a[i])scanf("%lf",&t),vec[i].pb(t),vec[0].pb(t),tot++;
    }vec[0].pb(-1e30);
    sort(vec[0].begin(),vec[0].end());
    tmp=(vec[0][vec[0].size()-m-1]+vec[0][vec[0].size()-m])/2;
    rep(i,0,vec[0].size()-1)if(eq(vec[0][i],tmp))tt++;else if(vec[0][i]>tmp)ttt++;
    ttt=ttt+tt-m;
    f[0][0]=1/C(ttt,tt);
    rep(i,1,n){
        cnt=0;rep(j,0,a[i]-1)if(vec[i][j]>tmp)++cnt;
        rep(j,0,tot)if(f[i-1][j]!=0)f[i][j+cnt]+=f[i-1][j]/C(cnt,a[i]);
        if(find(i)){
            rep(j,0,tot)if(f[i-1][j]!=0)f[i][j+cnt+1]+=f[i-1][j]/C(cnt+1,a[i]);
        }
    }printf("%.9lf\n",f[n][m]);
    //rep(i,1,n){rep(j,0,tot)printf("%.1lf ",f[i][j]);puts("");}
    //rep(i,1,n){rep(j,0,a[i]-1)printf("%.1lf ",vec[i][j]);puts("");}
    return 0;
}