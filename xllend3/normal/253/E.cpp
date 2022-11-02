/*
Date: 2014/09/28 12:15:28 Sunday
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

const int N=111111,M=111111;
int l,n,t,C,pt;
ll m;
struct zcc{int r,p,x;ll l,ans;}a[N],b[N];
inline bool cmp(const zcc &a,const zcc &b){return a.l<b.l;}
inline bool cmpx(const zcc &a,const zcc &b){return a.x<b.x;}
multiset<pii>S;
void print(){
    sort(b+1,b+1+n,cmpx);
    rep(i,1,n-1)printf("%lld ",b[i].ans);printf("%lld\n",b[n].ans);
}
ll calc(int x){
    rep(i,1,n)b[i]=a[i];
    b[pt].p=x;
    S.clear();
    b[++n].l=(1ll<<60);
    rep(i,1,n){
        ll t=b[i].l-b[i-1].l;
        while(S.size()){
            int p=S.begin()->Y;
            if(b[p].r>t){
                b[p].r-=t;
                break;
            }else{
                t-=b[p].r;
                b[p].ans=b[i].l-t;
                S.erase(S.begin());
            }
        }
        S.insert(mp(-b[i].p,i));
    }--n;
    return b[pt].ans;
}
int main()
{
    //ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    read(n);rep(i,1,n)read(a[i].l),read(a[i].r),read(a[i].p),a[i].x=i;
    sort(a+1,a+1+n,cmp);rep(i,1,n)if(a[i].p==-1)pt=i;
    read(m);
    int Min=0,Max=mod;
    while(Min+1<Max){
        int mid=Min+Max>>1;ll t=calc(mid);
        //printf("%d %d\n",mid,t);_sleep(100);
        if(t<m)Max=mid;
        else if(t>m)Min=mid;
        else {printf("%d\n",mid);print();return 0;}
    }if((t=calc(Max))==m){printf("%d\n",Max);print();return 0;}
    if((t=calc(Min))==m){printf("%d\n",Min);print();return 0;}
    printf("%d %lld %lld\n",Min,calc(Min),m);
    puts("orz");
    return 0;
}