#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define rep(i,a,n) for(int i=(a);i<=(n);++i)
#define dep(i,a,n) for(int i=(a);i>=(n);--i)
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
#define buli(x) (__builtin_popcountll(x))
#define bur0(x) (__builtin_ctzll(x))
#define bul2(x) (63-__builtin_clzll(x))
#define pw(x) ((ll(1))<<(x))
#define upmo(a,b) (((a)=((a)+(b))%mo)<0?(a)+=mo:(a))
#define mmo(a,b) (((a)=1ll*(a)*(b)%mo)<0?(a)+=mo:(a))
#define y0 y0z
#define y1 y1z
#define yn ynz
#define j0 j0z
#define j1 j1z
#define jn jnz
#define tm tmz
#ifdef LOCAL
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) 
#endif
typedef long long ll;
typedef double lf;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<lf,lf> pff;
typedef complex<double> CD;
const int inf=0x3f3f3f3f;
const int mo=1000000007;
inline void gn(long long&x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sg=-1,x=0):(x=c-'0');
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sg;
}
inline void gn(int&x){long long t;gn(t);x=t;}
inline void gn(unsigned long long&x){long long t;gn(t);x=t;}
inline void gn(double&x){double t;scanf("%lf",&t);x=t;}
inline void gn(long double&x){double t;scanf("%lf",&t);x=t;}
template<class T1,class T2>inline void gn(T1&r,T2&s){gn(r),gn(s);}
template<class T1,class T2,class T3>inline void gn(T1&r,T2&s,T3&t){gn(r),gn(s),gn(t);}
template<class T1,class T2,class T3,class T4>inline void gn(T1&r,T2&s,T3&t,T4&u){gn(r),gn(s),gn(t),gn(u);}
inline void gs(char *s){scanf("%s",s);}
inline void gc(char &c){while((c=getchar())>126 || c<33);}
inline void pc(char c){putchar(c);}
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mo;for(;b;b>>=1){if(b&1)res=res*a%mo;a=a*a%mo;}return res;}
ll powmod(ll a,ll b,ll mo) {ll res=1;a%=mo;for(;b;b>>=1){if(b&1)res=res*a%mo;a=a*a%mo;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//*******************************************

const int N=5055,M=111111;
int l,m,n,t,C,x,y,prex;
vector<int>a[N];
int dis[N][N];
void bfs(int k){
	rep(i,1,n)dis[k][i]=inf;
	dis[k][k]=0;
	queue<int>Q;
	Q.push(k);
	while(!Q.empty()){
		int p=Q.front();Q.pop();
		for(auto i:a[p]){
			if(dis[k][i]==inf){
				dis[k][i]=dis[k][p]+1;
				Q.push(i);
			}
		}
	}
}
int p[9];
void update(){
	printf("%d %d %d\n",p[0],p[1],p[2]);
	fflush(stdout);
	if(p[0]==x||p[1]==x||p[2]==x)exit(0);
	prex=x;
	scanf("%d",&x);
	if(p[0]==x||p[1]==x||p[2]==x)exit(0);
}
void go(int &x,int y){
	for(auto i:a[x])if(dis[i][y]==dis[x][y]-1){x=i;break;}
}
int main(){
#ifdef LOCAL
	//freopen("E.in","r",stdin);//freopen("E.out","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	rep(i,1,m)scanf("%d%d",&x,&y),a[x].pb(y),a[y].pb(x);
	rep(i,1,n)bfs(i);
	// rep(i,1,n){rep(j,1,n)printf("%d%c",dis[i][j],j==n?'\n':' ');}
	p[0]=p[1]=p[2]=1;x=-1;
	while(1){
		update();
		int q[9];
		int ans=inf;
		rep(i,0,SZ(a[x])-1)rep(j,0,SZ(a[x])-1)rep(k,0,SZ(a[x])-1){
			int res=dis[p[0]][a[x][i]]+dis[p[1]][a[x][j]]+dis[p[2]][a[x][k]];
			if(i!=j)res-=n;
			if(j!=k)res-=n;
			if(i!=k)res-=n;
			if(res<ans)ans=res,q[0]=a[x][i],q[1]=a[x][j],q[2]=a[x][k];
		}
		// rep(i,0,2){
		// 	q[i]=a[x][i%SZ(a[x])];
		// }
		// rep(i,1,2)if(q[i]==prex)swap(q[0],q[i]);
		rep(i,0,2)if(dis[p[i]][x]==1)q[i]=x;
		rep(i,0,2)go(p[i],q[i]);
	}
	return 0;
}