/*
Date: 2014/10/27 12:59:13 Monday
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

const int N=111111,M=111111,INF=314000000;
int l,m,n,t,C,x,v[N],c[N],num[N],Min[N],Max[N],vis[N],d[N];
vector<int>a[N],b[N],e[N];
set<pii>S;
int dfs(int x){
	//printf("%d\n",x);
	if(vis[x])return Max[x]=-2;
	if(Max[x]!=0)return Max[x];
	vis[x]=1;
	rep(__,0,SZ(b[x])-1){
		int i=b[x][__],s=v[i];
		int bo=0;rep(_,0,SZ(a[i])-1)if(Max[a[i][_]]==-1)bo=1;if(bo)continue;
		rep(_,0,SZ(a[i])-1){
			int tmp=dfs(a[i][_]);
			if(tmp==-2){vis[x]=0;return Max[x]=-2;}
			s+=tmp;MIN(s,INF);
		}MAX(Max[x],s);
	}
	vis[x]=0;
	return Max[x];
}
int main()
{
	//ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("CF325C.in","r",stdin);//freopen("CF325C.out","w",stdout);
#endif
	scanf("%d%d",&m,&n);
	rep(_,1,m){
		scanf("%d%d",&l,&t);
		rep(i,1,t){scanf("%d",&x);if(x==-1)v[_]++;else a[_].pb(x),e[x].pb(_),num[_]++;}
		b[l].pb(_);c[_]=l;d[_]=v[_];
		if(!num[_]){if(!Min[l])Min[l]=d[_];MIN(Min[l],d[_]);}
	}
	rep(i,1,n)if(Min[i])S.insert(mp(Min[i],i));
	while(S.size()){
		pii k=*(S.begin());S.erase(S.begin());if(vis[k.Y])continue;
		vis[k.Y]=1;Min[k.Y]=k.X;
		//printf("%d\n",k.Y);
		rep(i,0,SZ(e[k.Y])-1){
			d[e[k.Y][i]]+=Min[k.Y];MIN(d[e[k.Y][i]],INF);
			if(--num[e[k.Y][i]]==0&&!vis[c[e[k.Y][i]]]){
				//Min[c[e[k.Y][i]]]=d[e[k.Y][i]];
				S.insert(mp(d[e[k.Y][i]],c[e[k.Y][i]]));
			}
		}
	}
	rep(i,1,n)if(!vis[i])Min[i]=Max[i]=-1;
	//rep(i,1,n)printf("%d %d\n",Min[i],Max[i]);
	//rep(i,1,n)if(Max[i]==0)Max[i]=314000000;
	CLR(vis);rep(i,1,n)dfs(i);
	rep(i,1,n)printf("%d %d\n",Min[i],Max[i]);
	return 0;
}