/*
Date: 2014/10/30 09:36:20 Thursday
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

const int N=1111,M=111111;
int l,m,n,t,C,x,y,tot,cnt;
int a[N][N],dis[N][N],num[N][N],f1[N],g[N][N],h[N][N];
vector<pii>vec,b[N];
queue<pii>Q;
void bfs(int x,int y){
	Q.push(mp(x,y));dis[x][y]=t;vec.clear();
	while(Q.size()){
		pii k=Q.front();Q.pop();vec.pb(k);
		if(dis[k.X][k.Y]==0)continue;
		rep(i,0,3)if(a[k.X+DX[i]][k.Y+DY[i]]!=2&&!dis[k.X+DX[i]][k.Y+DY[i]]){
			dis[k.X+DX[i]][k.Y+DY[i]]=dis[k.X][k.Y]-1;
			Q.push(mp(k.X+DX[i],k.Y+DY[i]));
		}
	}rep(i,0,SZ(vec)-1)dis[vec[i].X][vec[i].Y]=0;
}
int main()
{
	//ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("CF254D.in","r",stdin);//freopen("CF254D.out","w",stdout);
#else
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	scanf("%d%d%d",&m,&n,&t);rep(i,1,m)rep(j,1,n){
		for(l=getchar();l!='X'&&l!='R'&&l!='.';l=getchar());
		a[i][j]=l=='.'?0:l=='R'?1:2;
	}
	rep(i,1,m)rep(j,1,n){
		if(a[i][j]==1)num[i][j]=++tot,bfs(i,j),b[tot]=vec;
		if(tot>300){puts("-1");return 0;}
	}
	rep(i,1,m)rep(j,1,n)g[i][j]=-1;
	rep(i,1,tot)f1[i]=-1;
	rep(_,0,SZ(b[1])-1){
		pii p1=b[1][_];
		bfs(p1.X,p1.Y);
		rep(i,0,SZ(vec)-1)g[vec[i].X][vec[i].Y]=_;
		int tmp=1;
		rep(j,2,tot)if(g[b[j][0].X][b[j][0].Y]==_)f1[j]=_;else tmp=j;
		if(tmp==1){
			rep(i,1,m)rep(j,1,n)if(a[i][j]!=2){printf("%d %d %d %d\n",p1.X,p1.Y,i,j);return 0;}
		}
		rep(i,0,SZ(b[tmp])-1){
			pii p2=b[tmp][i];
			//printf("%d %d %d %d\n",p1.X,p1.Y,p2.X,p2.Y);
			bfs(p2.X,p2.Y);
			++cnt;
			rep(i,0,SZ(vec)-1)h[vec[i].X][vec[i].Y]=cnt;
			int tmp=1;
			rep(j,2,tot)if(h[b[j][0].X][b[j][0].Y]!=cnt&&f1[j]!=_)tmp=j;
			if(tmp==1){
				printf("%d %d %d %d\n",p1.X,p1.Y,p2.X,p2.Y);return 0;
			}
		}
	}puts("-1");
	return 0;
}