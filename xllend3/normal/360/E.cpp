/*
Date: 2014/10/30 07:38:52 Thursday
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
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<lf,lf> pff;
typedef complex<double> CD;
const int inf=0x7fffffff;
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
int l,m,n,t,C,k,s1,s2,s3,x,y,tot=0,bo;
int b[N];
ll dis[3][N];
struct EDGE{int x,y,v1,v2,v3,nxt;}E[N];
void add(int l,int t,int x,int y){
	E[++tot].x=l;E[tot].y=t;E[tot].v1=x;E[tot].v2=y;E[tot].nxt=b[l];b[l]=tot;
}
set<pair<ll,pii> >S;
inline int c(){return bo?0:2;}
int check(){
	rep(i,1,n)dis[c()][i]=dis[1][i]=inf;
	rep(i,1,tot)E[i].v3=0;
	S.insert(mp(0,mp(c(),s1)));S.insert(mp(0,mp(1,s2)));
	while(S.size()){
		pair<ll,pii>k=*(S.begin());S.erase(S.begin());
		//printf("%d %d %d\n",k.X,k.Y.X,k.Y.Y);
		if(dis[k.Y.X][k.Y.Y]!=inf)continue;
		dis[k.Y.X][k.Y.Y]=k.X;
		for(int _=b[k.Y.Y];_;_=E[_].nxt){
			if(!E[_].v3)E[_].v3=k.Y.X==1?E[_].v2:E[_].v1;
			S.insert(mp(E[_].v3+dis[k.Y.X][k.Y.Y],mp(k.Y.X,E[_].y)));
		}
	}if(!bo)return dis[1][s3]>dis[c()][s3];
	return dis[1][s3]>=dis[c()][s3];
}
int main()
{
	//ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("CF360E.in","r",stdin);//freopen("CF360E.out","w",stdout);
#endif
	scanf("%d%d%d%d%d%d",&n,&k,&m,&s1,&s2,&s3);
	rep(i,1,k)scanf("%d%d%d",&l,&t,&x),add(l,t,x,x);
	rep(i,1,m)scanf("%d%d%d%d",&l,&t,&x,&y),add(l,t,x,y);
	if(check()){
		puts("WIN");rep(i,k+1,k+m)printf("%d%c",E[i].v3?E[i].v3:E[i].v1,i==k+m?'\n':' ');return 0;
	}bo=1;
	if(check()){
		puts("DRAW");rep(i,k+1,k+m)printf("%d%c",E[i].v3?E[i].v3:E[i].v1,i==k+m?'\n':' ');return 0;
	}puts("LOSE");
	return 0;
}