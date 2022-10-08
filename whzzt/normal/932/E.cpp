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
typedef unsigned long long ull;
typedef long long ll;
typedef long double ldb;
typedef double db;
typedef pair<int,int> pi;

const int N=5005,P=1e9+7;
int fpow(int a,int t){
	int r=1;
	for(;t;t>>=1,a=(ll)a*a%P)if(t&1)r=(ll)r*a%P;
	return r;
}

int n,k,fac[N],ifac[N],a,g[N],S[N][N];
// \sum C(n, i) (\sum f_i i^{k down})
int C(int n,int m){
	if(n<m)return 0;
	return (ll)fac[n]*ifac[m]%P*ifac[n-m]%P;
}

int main(){
	scanf("%d%d",&n,&k);
	fac[0]=ifac[0]=1;
	for(int i=1;i<=k;i++){
		fac[i]=(ll)fac[i-1]*i%P;
		ifac[i]=fpow(fac[i],P-2)%P;
	}
	S[0][0]=1;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=i;j++){
			S[i][j]=(S[i-1][j-1]+(ll)j*S[i-1][j])%P;
		}
	}
	g[0]=1;
	for(int m=1;m<=k;m++)
		g[m]=(ll)g[m-1]*(n-m+1)%P;
	for(int m=0;m<=k&&m<=n;m++){
		a=(a+(ll)fpow(2,n-m)*S[k][m]%P*g[m])%P;
	}
	cout<<a<<endl;
	return 0;
}