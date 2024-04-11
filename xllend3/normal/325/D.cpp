/*
Date: 2014/09/26 13:31:44 Friday
Author: xllend3
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<complex>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<map>
#include<set>
#define X first
#define Y second
#define mp make_pair
#define ph push
#define pb push_back
#define rep(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define dep(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
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
using namespace std;
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
const int DX[]={1,0,-1,0,-1,-1,1,1,0},DY[]={0,1,0,-1,-1,1,-1,1,0};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//*******************************************

const int N=18999999,M=3333;
int l,m,n,t,C,f[N],x,y,vis[M][2*M],nn;
inline int cal(const int &x){if(x>=n)return x-n;if(x<0)return x+n;return x;}
#define pt(x,y) ((x)*(n+2)+cal(y-1))
int getf(int x){if(x==f[x])return x;return f[x]=getf(f[x]);}
void modi(int x,int y){
    rep(k,0,7)if(vis[x+DX[k]][cal(y+DY[k]-1)])f[getf(pt(x+DX[k],y+DY[k]))]=getf(pt(x,y));vis[x][cal(y-1)]=1;
}
set<int>S;
int main()
{
    read(m,n,C);nn=n;n*=2;
    if(nn==1){puts("0");return 0;}
    rep(i,0,m+1)rep(j,0,n+1)f[pt(i,j)]=pt(i,j);//,printf("%d %d %d\n",i,j,pt(i,j));
    int ans=0;
    rep(_,1,C){
        read(x,y);
        int bo2=0;
        int tmp1[9],tmp2[9],t1=0,t2=0;
        rep(u,0,7)if(vis[x+DX[u]][cal(y+DY[u]-1)])tmp1[++t1]=getf(pt(x+DX[u],y+DY[u]));
        rep(v,0,7)if(vis[x+DX[v]][cal(y+DY[v]+nn-1)])tmp2[++t2]=getf(pt(x+DX[v],y+DY[v]+nn));
        S.clear();rep(i,1,t1)S.insert(tmp1[i]);
        rep(i,1,t2)if(S.find(tmp2[i])!=S.end()){bo2=1;break;}
        if(bo2)continue;
        modi(x,y);modi(x,y+nn);
        ++ans;
        //printf("success %d\n",_);
    }printf("%d\n",ans);
    return 0;
}