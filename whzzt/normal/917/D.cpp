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

const int P=1e9+7,N=105;

bool e[N][N];
int A[N][N],n,u,v,g[N];

int Inv(int a){
	if(a<=1)return a;
	return P-(ll)(P/a)*Inv(P%a)%P;
}
int gauss(){
	int ret=1,D=n-1,l;
	fo(i,1,D){
		for(l=i;!A[l][i]&&l<=D;l++);
		if(l>D)return 0;
		if(l!=i){
			ret=P-ret;
			fo(j,i,n)swap(A[i][j],A[l][j]); 
		}
		int t=Inv(A[i][i]);ret=(ll)ret*A[i][i]%P;
		fo(j,i,D)A[i][j]=(ll)A[i][j]*t%P;
		fo(j,i+1,D)if(A[j][i]){
			int t=A[j][i];
			fo(k,i,D)A[j][k]=(A[j][k]-(ll)A[i][k]*t%P+P)%P;
		}
	}
	return ret;
}

struct poly:VI{
	poly(){}
	poly(int n,...){
		va_list scan;va_start(scan,n);
		resize(n+1);fd(i,n,0)(*this)[i]=va_arg(scan,int);
		va_end(scan);
	}
	friend poly operator+(const poly&a,const poly&b){
		poly c;
		c.resize(max(SZ(a),SZ(b)));
		fo(i,0,SZ(a)-1)c[i]+=a[i];
		fo(i,0,SZ(b)-1)c[i]+=b[i];
		fo(i,0,SZ(c)-1)if(c[i]>=P)c[i]-=P;
		while(SZ(c)&&c[SZ(c)-1]==0)c.pop_back();
		return c;
	}
	friend poly operator*(const poly&a,const poly&b){
		poly c;
		c.resize(SZ(a)+SZ(b)-1);
		fo(i,0,SZ(a)-1)fo(j,0,SZ(b)-1)c[i+j]=(c[i+j]+(ll)a[i]*b[j])%P;
		while(SZ(c)&&c[SZ(c)-1]==0)c.pop_back();
		return c;
	}
}ans;

int main(){
	scanf("%d",&n);
	fo(i,2,n)scanf("%d%d",&u,&v),e[u][v]=e[v][u]=true;
	fo(w,1,n){
		memset(A,0,sizeof(A));
		fo(i,1,n)fo(j,1,n)if(i!=j)A[i][j]-=e[i][j]?w:1,A[i][i]+=e[i][j]?w:1;
		g[w]=gauss();
	}
	fo(i,1,n){
		poly cur(0,1);
		int mul=1;
		fo(j,1,n)if(i!=j)cur=cur*poly(1,1,P-j),mul=(ll)mul*(i-j)%P;
		if(mul<0)mul+=P;
		cur=cur*poly(0,(ll)Inv(mul)*g[i]%P);
		ans=ans+cur;
	}
	ans.resize(n);
	fo(i,0,n-1)printf("%d ",ans[i]);
	return 0;
}