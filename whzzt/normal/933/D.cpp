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

const int P=1e9+7,i2=P/2+1,i6=P/6+1,N=1e6+5;

ll n,m;
int r,f1[N],f2[N],f3[N];

int main(){
	scanf("%lld",&n);
	ll g1=(n+1)%P,g3=(ll)g1*g1%P*g1%P;
	while((ll)m*m<=n)m++;m--;
	fo(i,1,m){
		ll v1=(ll)i*i%P,v2=(ll)v1*v1%P,v3=(ll)v1*v2%P;
		f1[i]=(f1[i-1]+v1)%P;
		f2[i]=(f2[i-1]+v2)%P;
		f3[i]=(f3[i-1]+v3)%P;
	}
	fo(x,0,m){
		ll s=0,v1=(ll)x*x%P,v2=(ll)v1*v1%P,v3=(ll)v1*v2%P;
		while((ll)x*x+(ll)m*m>n)m--;
		s=((g3+g1*(3*v1-3*v2-1)+v1-v2*3+v3*2)%P*(m+1)%P+(3*g1+1-(3*g1+3)*v1*2+v2*6)%P*f1[m]%P+3*(v1*2-g1-1)*f2[m]+2*f3[m])%P;
		s=(s*2-g3+g1-v1*(3*g1+1)+v2*(3*g1+3)-v3*2)%P;
		r=(r+s*(1<<(x>0)))%P;
	}
	r=(ll)r*i6%P;
	if(r<0)r+=P;
	printf("%d\n",r);
	return 0;
}