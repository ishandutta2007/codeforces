#include<bits/stdc++.h>

#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-funroll-loops")
#pragma GCC target("avx,sse4")

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

using namespace std;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ldb;
typedef double db;
typedef pair<int,int> pi;
typedef vector<int> VI;
typedef vector<VI> VII;

const int N=75;
const ll inf=1e18;

int D;
struct num{
	ll w;
	num(ll w=inf):w(w){}
	num operator+(num a){return num(min(w,a.w));}
	num operator*(num a){return num(w+a.w);}
};
struct mat{
	num v[N][N];
	num*operator[](int i){return v[i];}
	// addition : integer min
	// multiply : integer addition
	friend mat operator*(mat a,mat b){
		mat c;
		fo(i,1,D)fo(j,1,D)fo(k,1,D)c[i][j]=(c[i][j]+a[i][k]*b[k][j]);
		return c;
	}
	void print(){
		fo(i,1,D)fo(j,1,D){
			if(v[i][j].w!=inf)debug("%lld%c",v[i][j].w," \n"[j==D]);
			else debug("inf%c"," \n"[j==D]);
		}
		debug("\n");
	}
};
inline mat fpow(mat a,int t){
	mat r;
	fo(i,1,D)r[i][i]=num(0);
	for(;t;t>>=1,a=a*a)if(t&1)r=r*a;
	return r;
}

map<int,mat> dat;
mat base,ret;
int m,n,len,Q,cst[10],id[256],U,L;
bool mark[256];

int main(){
	scanf("%d%d%d%d",&m,&n,&len,&Q);len=len-m;
	fo(i,1,n)scanf("%d",&cst[i]);
	fo(i,0,U=(1<<n)-1)if(__builtin_popcount(i)==m)mark[i]=true;
	fo(i,0,U)if(mark[i])id[i]=++D;
	fo(i,0,U)if(mark[i]){
		if(i&1){
			fo(j,1,n)if(~i>>j&1)base[id[i]][id[(i+(1<<j)-1)>>1]]=num(cst[j]);
		}else{
			base[id[i]][id[i>>1]]=num(0);
		}
	}
	while(Q--){
		int p,w;
		scanf("%d%d",&p,&w);
		fo(k,1,n){
			if(p-k<1||p-k>len)continue;
			if(!dat.count(p-k))dat[p-k]=base;
			mat &cur=dat[p-k];
			fo(i,0,U)if(mark[i]&&(i&1)&&(~i>>k&1)){
				cur[id[i]][id[(i+(1<<k)-1)>>1]].w+=w;
			}
		}
	}
	fo(i,1,n)ret[i][i]=num(0);
	for(auto&e:dat){
		if(e.fi>L+1)ret=ret*fpow(base,e.fi-1-L);
		ret=ret*e.se;
		L=e.fi;
	}
	if(L<len)ret=ret*fpow(base,len-L);
	printf("%lld\n",ret[1][1].w);
	return 0;
}