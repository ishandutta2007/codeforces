/*
Date: 2014/11/21 10:57:40 Friday
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

const int N=1111111,M=2222;
int l,m,n,t,C,ex;
int a[N],b[N],ans[N],tmp[N];
char s[N];
int main()
{
    //ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("CF332E.in","r",stdin);//freopen("CF332E.out","w",stdout);
#endif
    gets(s+1);n=strlen(s+1);rep(i,1,n)a[i]=s[i]-31;
    gets(s+1);m=strlen(s+1);rep(i,1,m)b[i]=s[i]-31;
    scanf("%d",&t);
    int len=n/t;
    rep(p,1,m)if(p*len<=m&&p*(len+1)>=m){
        int j=p;CLR(tmp);
        dep(i,t,1){
            if(!j)break;
            int bo=0;
            rep(k,0,len)if(a[i+k*t]!=b[j+k*p])bo=1;
            if(bo)continue;
            j--;tmp[i]=1;
        }
        if(!j){
            if(!ex){ex=1;CPY(ans,tmp);}
            else{
                int bo=0;rep(i,1,t)if(tmp[i]>ans[i]){bo=1;break;}else if(tmp[i]<ans[i]){bo=2;break;}
                if(bo==2)CPY(ans,tmp);
            }
        }
    }if(!ex)puts("0");
    else{rep(i,1,t)printf("%d",ans[i]);puts("");}
    return 0;
}