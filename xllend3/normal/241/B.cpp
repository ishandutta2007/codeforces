/*
Date: 2014/10/16 12:27:09 Thursday
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
const int inf=0x7fffffff;
const int mod=1000000007;
/*
template<class T> inline void read(T&x){char c;for(c=getchar();c<=32;c=getchar());for(x=0;c>32;c=getchar())x=x*10+c-'0';};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
template<class T> inline void read(T&x,T&y,T&z,T&q){read(x);read(y);read(z);read(q);}
*/
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//*******************************************

const int N=55555,M=1533333;
int l,n,t,C,a[N],c[M][2],sum[M],SUM[M][31],tot=1;
ll m;
void add(int x){
    int p=1;
    dep(i,30,0){
        int tmp=x>>i&1;
        sum[p]++;rep(j,0,i+1)if(x&(1<<j))SUM[p][j]++;
        int &t=c[p][tmp];if(!t)t=++tot;p=t;
    }sum[p]++;if(x&1)SUM[p][0]++;
}
ll check(int x){
    if(!x)return n*(n-1)/2;
    ll ans=0;
    rep(i,1,n){
        int p=1;
        dep(j,30,0){
            int tmp=x>>j&1,atmp=a[i]>>j&1;
            if(tmp==0)ans+=sum[c[p][atmp^1]];
            p=c[p][tmp^atmp];
        }ans+=sum[p];
        //printf("%d %d %lld\n",x,i,ans);
    }
    return ans/2;
}
ll calc(int x){
    ll ans=0;
    rep(i,1,n){
        int p=1;
        dep(j,30,0){
            int tmp=x>>j&1,atmp=a[i]>>j&1;
            if(tmp==0){
                int q=c[p][atmp^1];
                if(q){
                    ans+=ll((x>>j+1<<j+1))*sum[q];
                    rep(k,0,j)ans+=(ll(a[i]&(1<<k)?sum[q]-SUM[q][k]:SUM[q][k])<<k);
                }
            }
            p=c[p][tmp^atmp];
        }ans+=sum[p]*x;
        //printf("%d %d %d\n",x,i,ans);
    }
    return ans%mod;
}
#include<ctime>
char buf[1000000],*o=buf,*pt=buf;
template<class T>inline void read(T&s){
    s=0; while(*pt<'0'||*pt>'9')pt++;
    while(*pt>='0'&&*pt<='9')s=s*10+*pt++-48;
}
int pos[N];
int main()
{
    fread(buf,1,1000000,stdin);
    read(n);read(m);rep(i,1,n)read(a[i]),add(a[i]);
    if(m==0){puts("0");return 0;}
    //rep(i,0,4)printf("%d %lld %lld\n",i,calc(i),check(i));return 0;
//printf("%d\n",clock());
    int res=0;ll calm=0;rep(i,0,30)res+=(1<<i);
    rep(i,1,n)pos[i]=1;
    dep(j,30,0){
    	ll tmp=calm;rep(i,1,n)tmp+=sum[c[pos[i]][(a[i]>>j&1)^1]];
    	if(tmp>2*m){rep(i,1,n)pos[i]=c[pos[i]][(a[i]>>j&1)^1];}
    	else{res-=(1<<j);calm=tmp;rep(i,1,n)pos[i]=c[pos[i]][a[i]>>j&1];}
	}
	//printf("%d\n",res);
	if(check(res)<m)--res;
	//printf("%d\n",res);
//printf("%d\n",clock());
    printf("%d\n",(calc(res+1)*powmod(2,mod-2)+(m-check(res+1))*res)%mod);
//printf("%d\n",clock());
    return 0;
}