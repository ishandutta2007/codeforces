/*
Date: 2014/09/28 09:43:17 Sunday
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
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//*******************************************

const int N=111,M=1111;
int l,m,n,t,C;
char a[N][N],s[N];
pii pt[N],pos[M];
int find(int d,int i){
    pii p=pos[i];while(a[p.X][p.Y]!='#'){
        p.X+=DX[d];p.Y+=DY[d];if(p==pos[i+1])return 1;
    }return 0;
}
int calc(char x){if(x>='0'&&x<='9')return x-'0';return 1;}
int main()
{
    scanf("%d%d%d",&m,&n,&l);
    rep(i,1,m)rep(j,1,n){
        for(a[i][j]=getchar();a[i][j]!='#'
            &&(a[i][j]<'0'||a[i][j]>'9')&&(a[i][j]<'a'||a[i][j]>'z');a[i][j]=getchar());
        if(a[i][j]>='a'&&a[i][j]<='z')pt[a[i][j]-'a'].X=i,pt[a[i][j]-'a'].Y=j;
    }
    scanf("%d%d%s",&pos[0].X,&pos[0].Y,s+1);n=strlen(s+1);
    rep(i,1,n)pos[i]=pt[s[i]-'a'];scanf("%d%d",&pos[n+1].X,&pos[n+1].Y);
    rep(i,0,n){
        rep(k,0,3)if(find(k,i)){
            pii p=pos[i];
            while(1){
                if(p==pos[i+1])break;
                l-=calc(a[p.X][p.Y]);
                if(l<0){printf("%d %d\n",p.X,p.Y);return 0;}
                p.X+=DX[k];p.Y+=DY[k];
            }
        }//printf("%d %d\n",i,l);
    }printf("%d %d\n",pos[n+1].X,pos[n+1].Y);
    return 0;
}