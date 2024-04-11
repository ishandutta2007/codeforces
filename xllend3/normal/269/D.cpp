/*
Date: 2014/11/19 07:51:44 Wednesday
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
const int inf=0x3fffffff;
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
int l,m,n,t,C;
struct zcc{int h,l,r,v;}a[N];
inline bool cmph(const zcc &a,const zcc &b){return a.h<b.h;}
set<pii>S;
void upd(int x,int y){MAX(a[x].v,min(a[y].v,min(a[x].r,a[y].r)-max(a[x].l,a[y].l)));}
int main()
{
    //ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("CF269D.in","r",stdin);//freopen("CF269D.out","w",stdout);
#endif
    scanf("%d%d",&n,&m);
    rep(i,1,n)scanf("%d%d%d",&a[i].h,&a[i].l,&a[i].r);
    a[++n].h=m;a[n].l=-inf+1;a[n].r=inf-1;
    a[++n].h=0;a[n].l=-inf;a[n].r=inf;
    sort(a+1,a+1+n,cmph);a[1].v=inf*2;
    S.insert(mp(-inf,0));S.insert(mp(inf+1,0));
    S.insert(mp(a[1].r,1));
    rep(i,2,n){
        //ALL(it,S)printf("%d %d\n",it->x,it->y);
        set<pii>::iterator it=S.lower_bound(mp(a[i].l,inf));
        if(it->x>=a[i].r){
            upd(i,it->y);
        }else{
            if(a[it->y].r==it->x)upd(i,it->y);
            for(;;){
                //if(i==n)printf("orz %d %d\n",it->x,it->y);
                set<pii>::iterator tmp=it;++tmp;
                if(tmp->x>=a[i].r)break;
                if(a[tmp->y].l==it->x&&a[tmp->y].r==tmp->x)upd(i,tmp->y);
                it=tmp;
            }set<pii>::iterator tmp=it;++tmp;
            if(a[tmp->y].l==it->x)upd(i,tmp->y);
        }
        int lft=S.lower_bound(mp(a[i].l,inf))->y;
        while(it=S.lower_bound(mp(a[i].l,inf)),it->x<a[i].r){
            S.erase(it);
        }if(it->x==a[i].r)S.erase(it);
        if(S.lower_bound(mp(a[i].l,0))->x!=a[i].l)S.insert(mp(a[i].l,lft));
        S.insert(mp(a[i].r,i));
        //printf("          %d %d %d %d %d\n",i,a[i].h,a[i].l,a[i].r,a[i].v);
    }
    printf("%d\n",a[n].v);
    return 0;
}