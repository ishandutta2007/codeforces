#include<bits/stdc++.h>

#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-funroll-loops")
#pragma GCC target("sse4")

#define mms(a,n) memset(a,0,sizeof((a)[0])*(n))
#define mmp(a,b,n) memcpy(a,b,sizeof((b)[0])*(n))
#define lowbit(x) ((x)&-(x))
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define fo(i,l,r) for(register int i=l,_lim_=r;i<=_lim_;i++)
#define fd(i,r,l) for(register int i=r,_lim_=l;i>=_lim_;i--)
#define fos(i,l,r,d) for(register int i=l,_lim_=r;i<=r;i+=d)
#define fol(i,l,r) for(register ll i=l,_lim_=r;i<=_lim_;i++)
#define fdl(i,r,l) for(register ll i=r,_lim_=l;i>=_lim_;i--)
#define fosl(i,l,r,d) for(register ll i=l,_lim_=r;i<=r;i+=d)
#define Clear(a) memset(a,0,sizeof(a))
#define Copy(a,b) memcpy(a,b,sizeof(b))
#define ALL(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())
#define sqr(x) ((x)*(x))
#define GCD __gcd

using namespace std;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ldb;
typedef double db;
typedef pair<int,int> pi;
typedef vector<int> VI;
typedef vector<VI> VII;

const int N=65,M=100005,P=1e9+7;
int fac[M],x[N],y[N],val[N],n,k,p1[M],p2[M],dx[N],dy[N],c1=0,c2=0,e[N][N],ret;
unordered_map<ll,int>dp[N][N];
ll suf[N];
vector<int>vec[N];

inline void upd(int&x,int y){(x+=y)<P?:x-=P;}

int main(){
	srand(time(0)^size_t(new char));
	scanf("%d%d",&n,&k);
	fo(i,fac[0]=1,n)fac[i]=(ll)fac[i-1]*i%P,p1[i]=p2[i]=i;
	random_shuffle(p1+1,p1+n+1);random_shuffle(p2+1,p2+n+1);
	fo(i,1,k)scanf("%d%d%d",x+i,y+i,val+i),x[i]=p1[x[i]],y[i]=p2[y[i]],dx[++c1]=x[i],dy[++c2]=y[i],val[i]--;
	sort(dx+1,dx+c1+1);c1=unique(dx+1,dx+c1+1)-dx-1;sort(dy+1,dy+c2+1);c2=unique(dy+1,dy+c2+1)-dy-1;
	fo(i,1,k)x[i]=lower_bound(dx+1,dx+c1+1,x[i])-dx,y[i]=lower_bound(dy+1,dy+c2+1,y[i])-dy,e[x[i]][y[i]]=val[i],vec[x[i]].pb(y[i]);	
	suf[c1+1]=0;
	fd(i,c1,1){
		suf[i]=suf[i+1];
		for(int v:vec[i])suf[i]|=1ll<<v;
	}
	dp[0][0][0]=1;
	fo(i,1,c1)fo(j,0,i){
		for(auto&s:dp[i-1][j])upd(dp[i][j][s.fi&suf[i]],s.se);
		if(!j)continue;
		for(auto&s:dp[i-1][j-1])for(int v:vec[i]){
			if(s.fi>>v&1)continue;
			upd(dp[i][j][(s.fi|1ll<<v)&suf[i]],(ll)e[i][v]*s.se%P);
		}
	}
	fo(i,0,c1)for(auto&s:dp[c1][i])upd(ret,(ll)fac[n-i]*s.se%P);
	printf("%d\n",ret);
	return 0;
}