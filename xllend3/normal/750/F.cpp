/*
Date: 2016/12/30 21:49:30 Friday
*/
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

const int N=111111,M=111111;
int l,m,n,t,C,num,ok=0,mans;
int vis[N],du[N],dep[N],pai[N],rtn[N];
vector<int>ans[N];
void doit(int x){
	int p=pai[x];
	if((p>>1)>=1)ans[x].pb(rtn[p>>1]);
	if((p<<1)<=m)ans[x].pb(rtn[p<<1]);
	if((p<<1)+1<=m)ans[x].pb(rtn[(p<<1)+1]);
	random_shuffle(ans[x].begin(),ans[x].end());
	printf("%d ",SZ(ans[x]));for(auto i:ans[x])printf("%d ",i);puts("");
}
void que(int x){
	if(vis[x]||ok)return;
	if(num==16){
		printf("! %d\n",x);ok=1;
		fflush(stdout);
		return;
	}
	printf("? %d\n",x);fflush(stdout);
	int n,t;
#ifdef LOCAL
	doit(x);n=SZ(ans[x]);
#else
	scanf("%d",&n);rep(i,1,n)scanf("%d",&t),ans[x].pb(t);
#endif
	du[x]=n;vis[x]=1;
	++num;
	if(n==2){
		printf("! %d\n",x);ok=1;
		fflush(stdout);
#ifdef LOCAL
		MAX(mans,num);printf("[%d,%d]\n",num,mans);
#endif
	}
}
vector<int>tmp;
void work(int x,int f){
	tmp.pb(x);
	que(x);
	int bo=0;
	for(auto i:ans[x])if(i!=f){work(i,x);break;}
}
int main(){
#ifdef LOCAL
	freopen("F.in","r",stdin);//freopen("F.out","w",stdout);
	//srand(unsigned(time(NULL)));
#endif
	int T;
	scanf("%d",&T);rep(_,1,T){
		ok=0;num=0;
		scanf("%d",&n);m=(1<<n)-1;
#ifdef LOCAL
		rep(i,1,m)pai[i]=i;random_shuffle(pai+1,pai+1+m);
		rep(i,1,m)rtn[pai[i]]=i;
#endif
		rep(i,1,m)vis[i]=du[i]=dep[i]=0,ans[i].clear();
		que(1);
		work(ans[1][0],1);
		if(SZ(ans[1])>1)work(ans[1][1],1);
		if(ok)continue;
		int pt,f=0;
		rep(i,1,m)if(du[i]==1)pt=i;
		dep[pt]=n;
		rep(i,1,num/2){
			for(auto i:ans[pt])if(vis[i]&&i!=f){dep[i]=dep[pt]-1,f=pt,pt=i;break;}
		}int qt=pt;
		rep(i,num/2+1,num-1){
			for(auto i:ans[pt])if(vis[i]&&i!=f){dep[i]=dep[pt]+1,f=pt,pt=i;break;}
		}
		while(1){
			if(ok)break;
			int mx=9,p=0;
			rep(i,1,m)if(dep[i]&&dep[i]<mx)mx=dep[i],p=i;
			//printf("{%d %d %d}\n",mx,p,_);
			if(mx<=4){
				queue<int>Q;
				for(auto x:ans[p])if(!vis[x])Q.push(x),que(x);
				while(1){
					int k=Q.front();Q.pop();
					for(auto x:ans[k]){
						if(vis[x])continue;
						Q.push(x);
						que(x);
						if(ok)break;
					}
					if(ok)break;
				}
			}else{
				for(auto x:ans[p])if(dep[x]!=dep[p]+1){
					tmp.clear();
					dep[x]=dep[p]-1;que(x);tmp.pb(x);
					for(auto i:ans[x])if(!vis[i]){
						work(i,x);
						dep(i,n,mx)if(SZ(tmp))dep[tmp.back()]=i,tmp.pop_back();
						//printf("()%d %d\n",SZ(tmp),tmp[0]);
						if(SZ(tmp)){rep(i,0,SZ(tmp)/2)dep[tmp[i]]=--mx;}
						break;
					}
				}
			}
		}
		if(mans>17)return 0;
	}
	return 0;
}