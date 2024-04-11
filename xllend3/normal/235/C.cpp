/*
Date: 2014/09/25 07:16:18 Thursday
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

const int N=2222222,M=111111;
int m,n,t,f[N],c[N][26],l[N],tail=1,head=1,tot=1,cnt[N],vis[N];
char s[N];
void add(char x){
    int p=tail,np=++tot,r,q;l[np]=l[p]+1;tail=np;cnt[np]=1;
    for(;p&&!c[p][x];p=f[p])c[p][x]=np;
    if(!p)f[np]=head;
    else if(l[p]+1==l[q=c[p][x]])f[np]=q;
    else{
        f[r=++tot]=f[q];memcpy(c[r],c[q],sizeof(c[r]));
        l[r]=l[p]+1;f[q]=f[np]=r;for(;p&&c[p][x]==q;p=f[p])c[p][x]=r;
    }
}
vector<int>vec[N];
int main()
{
    scanf("%s",s+1);n=strlen(s+1);rep(i,1,n)add(s[i]-'a');
    rep(i,1,tot)vec[l[i]].pb(i);
    //rep(i,1,tot)cnt[i]=1;
    dep(i,n,1)rep(j,0,SZ(vec[i])-1)cnt[f[vec[i][j]]]+=cnt[vec[i][j]];
    //rep(i,1,tot)printf("%d %d %d %d %d %d\n",i,f[i],l[i],c[i][0],c[i][1],cnt[i]);
    scanf("%d",&m);
    rep(_,1,m){
        scanf("%s",s+1);n=strlen(s+1);int pt=1,len=0,ans=0;
        rep(i,1,n){
            while(pt&&!c[pt][s[i]-'a'])pt=f[pt],len=l[pt];
            if(!pt)pt=1,len=0;
            else pt=c[pt][s[i]-'a'],len++;
        }
        rep(i,1,n){
            while(l[f[pt]]>=n)pt=f[pt],len=l[pt];
            if(len>=n&&vis[pt]!=_)ans+=cnt[pt],vis[pt]=_;
            while(pt&&!c[pt][s[i]-'a'])pt=f[pt],len=l[pt];
            if(!pt)pt=1,len=0;
            else pt=c[pt][s[i]-'a'],len++;
            //printf(" %d\n",pt);
        }printf("%d\n",ans);
    }
    return 0;
}