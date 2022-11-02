/*
Date: 2014/11/26 15:58:47 Wednesday
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

const int N=111111,M=1111111;
int r,m,n,t,C,tot=1,tail=1,head=1;
ll ans;
int c[M][27],l[M],f[M],g[M][12],L[N],R[N],rd[M];
char s[12][N];
void add(char x,int y){
    int p=tail,np=++tot,r,q;l[np]=l[p]+1;tail=np;if(x)g[np][y]++;
    for(;p&&!c[p][x];p=f[p])c[p][x]=np;
    if(!p)f[np]=head;
    else if(l[p]+1==l[q=c[p][x]])f[np]=q;
    else{
        f[r=++tot]=f[q];memcpy(c[r],c[q],sizeof(c[r]));
        l[r]=l[p]+1;f[q]=f[np]=r;for(;p&&c[p][x]==q;p=f[p])c[p][x]=r;
    }
}
queue<int>Q;
int main(){
    //ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("CF316G3.in","r",stdin);//freopen("CF316G3.out","w",stdout);
#endif
    scanf("%s",s[0]+1);
    scanf("%d",&n);rep(i,1,n)scanf("%s%d%d",s[i]+1,&L[i],&R[i]);
    rep(i,0,n){
        int m=strlen(s[i]+1);rep(j,1,m)add(s[i][j]-'a'+1,i);if(i!=n)add(0,i);
    }
    rep(i,1,tot)++rd[f[i]];
    rep(i,1,tot)if(!rd[i])Q.push(i);
    while(Q.size()){
        int k=Q.front();Q.pop();
        int bo=1;if(!g[k][0])bo=0;
        rep(i,1,n)if(L[i]>g[k][i]||g[k][i]>R[i])bo=0;
        ans+=bo*(l[k]-l[f[k]]);
        rep(i,0,n)g[f[k]][i]+=g[k][i];
        if(--rd[f[k]]==0)Q.push(f[k]);
    }printf("%I64d\n",ans);
    //rep(i,1,tot){rep(j,0,n)printf("%d ",g[i][j]);puts("");}
    return 0;
}