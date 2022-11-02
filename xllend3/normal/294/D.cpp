/*
Date: 2014/11/18 09:05:34 Tuesday
Author: xllend3
*/
/*
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

const int N=111111,M=111111;
int l,m,n,t,C,x,y,dir,ml,mr,nl,nr;//0DR 1UR 2DL 3UL
ll ans=1;
int vis[N][4],cnt[4];//0L 1R 2U 3D
char s[9];
void put(int x,int y){if(!vis[x][y])cnt[y]++;else if(vis[x][y]>3){puts("-1");exit(0);}vis[x][y]++;}
int cng(int x){return x?1:-1;}
int main()
{
    //ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("CF294D.in","r",stdin);//freopen("CF294D.out","w",stdout);
#endif
    scanf("%d%d%d%d%s",&m,&n,&x,&y,s);
    ml=mr=m/2;if(m&1){if(!((x+y)&1))ml++;if(((x+y+n)&1))mr++;}
    nl=nr=n/2;if(n&1){if(!((x+y)&1))nl++;if(((x+y+m)&1))nr++;}
    dir|=s[0]=='U'?1:0;dir|=s[1]=='L'?2:0;
    if(x==1)put(y,2);if(x==m)put(y,3);if(y==1)put(x,0);if(y==n)put(x,1);
    while(cnt[0]<ml||cnt[1]<mr||cnt[2]<nl||cnt[3]<nr){
        //printf("%d %d %d\n",x,y,ans);
        int D=inf,U=inf,L=inf,R=inf;
        if(dir&1)MIN(U,x-1);else MIN(D,m-x);
        if(dir&2)MIN(L,y-1);else MIN(R,n-y);
        ans+=min(min(D,U),min(L,R));
        if(D<=U&&D<=L&&D<=R){
            dir^=1;y+=D*(-cng(dir&2));x=m;
        }else if(U<=D&&U<=L&&U<=R){
            dir^=1;y+=U*(-cng(dir&2));x=1;
        }else if(L<=D&&L<=U&&L<=R){
            dir^=2;x+=L*(-cng(dir&1));y=1;
        }else{
            dir^=2;x+=R*(-cng(dir&1));y=n;
        }
        if(x==1)put(y,2);if(x==m)put(y,3);if(y==1)put(x,0);if(y==n)put(x,1);
    }printf("%I64d\n",ans);
    return 0;
}