/*
Date: 2015/01/06 11:55:49 Tuesday
Author: xllend3
*/
#include<bits/stdc++.h>
using namespace std;
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

const int N=111111,M=11111111;
int l,m,n,t,C,r;
char s[N];
struct Node{
int lc,rc,v,bj;
}T[M];
int root[99],tot;
void cov(int &x,int l,int r,int p){if(!x)x=++tot;T[x].v=(r-l+1)*p;T[x].bj=p+1;}
void push(int x,int l,int r){
	int mid=l+r>>1;if(T[x].bj)cov(T[x].lc,l,mid,T[x].bj-1),cov(T[x].rc,mid+1,r,T[x].bj-1),T[x].bj=0;
}
void modi(int &x,int l,int r,int L,int R,int p){
	//printf("%d %d %d %d %d %d\n",x,l,r,L,R,p);
	if(!x)x=++tot;if(l==L&&r==R){cov(x,l,r,p);return;}int mid=l+r>>1;push(x,l,r);
	if(L<=mid)modi(T[x].lc,l,mid,L,min(mid,R),p);
	if(R>mid)modi(T[x].rc,mid+1,r,max(mid+1,L),R,p);
	T[x].v=T[T[x].lc].v+T[T[x].rc].v;
}
int que(int x,int l,int r,int L,int R){
	if(!x)return 0;push(x,l,r);if(l==L&&r==R)return T[x].v;int mid=l+r>>1,ans=0;
	if(L<=mid)ans+=que(T[x].lc,l,mid,L,min(mid,R));
	if(R>mid)ans+=que(T[x].rc,mid+1,r,max(mid+1,L),R);
	return ans;
}
int v[99];
int main(){
	//ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("CF240F.in","r",stdin);//freopen("CF240F.out","w",stdout);
#else
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	scanf("%d%d",&n,&C);scanf("%s",s+1);rep(i,1,n)modi(root[s[i]-'a'],1,n,i,i,1);
	rep(_,1,C){
		scanf("%d%d",&l,&r);int cnt=0;
		rep(i,0,25)if((v[i]=que(root[i],1,n,l,r))&1)++cnt;if(cnt>1)continue;
		rep(i,0,25)if(v[i])modi(root[i],1,n,l,r,0);
		rep(i,0,25)if(v[i]){
			modi(root[i],1,n,l,l+v[i]/2-1,1);l+=v[i]/2;
			modi(root[i],1,n,r-v[i]/2+1,r,1);r-=v[i]/2;
		}if(cnt)rep(i,0,25)if(v[i]&1)modi(root[i],1,n,l,r,1);
	}rep(i,1,n)rep(j,0,25)if(que(root[j],1,n,i,i)==1)putchar(j+'a');
	return 0;
}