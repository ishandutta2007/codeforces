#include<bits/stdc++.h>
using namespace std;
namespace jyy{
	const int mod=998244353,N=200010;
	const double eps=1e-8;
	#define ll long long
	inline int read(){
		static int x=0,f=1;x=0,f=1;
		static char ch=getchar();
		while(ch<'0'||ch>'9'){(ch=='-')?f*=-1:f;ch=getchar();}
		while(ch>='0'&&ch<='9')x=x*10+int(ch-48),ch=getchar();
		return x*f;
	}
	inline void fw(int x){if(x<0)putchar('-'),x=-x;x>=10?fw(x/10),1:0;putchar(char(x%10+48));}
	int qmo(int x){return x+((x>>31)&mod);}
	int ksm(int x,int y){int tmp=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)tmp=1ll*tmp*x%mod;return tmp;}
	int inv(int x){return ksm(x,mod-2);}
	int tot,head[N],fa[N];
	struct edge{int to,next;}dat[N*2];
	void add_edge(int x,int y){dat[++tot]=(edge){y,head[x]},head[x]=tot;}
	int find(int x){return fa[x]?fa[x]=find(fa[x]):x;}
	void merge(int x,int y){find(x)!=find(y)?fa[find(x)]=find(y):0;}
	int low(int x){return x&-x;}
	int ifac[N],fac[N];
	void init(int x){fac[0]=ifac[0]=1;for(int i=1;i<=x;i++)fac[i]=1ll*fac[i-1]*i%mod;ifac[x]=inv(fac[x]);for(int i=x-1;i>=1;i--)ifac[i]=1ll*ifac[i+1]*(i+1)%mod;}
	int c(int x,int y){return (x<y||y<0||x<0)?0:1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;}
}
using namespace jyy;
double p,n;
int main(){
	scanf("%lf%lf",&n,&p);
	for(double i=0;i<=n;i++){
		double A1=i*(i-1)*(i-2)/6+(i-1)*i/2*(n-i)+i*(n-i)*(n-i-1)/2/2.0;
//		cout<<"check "<<i<<' '<<A1<<' '<<A1/<<endl;
		if(A1>=p*n*(n-1)*(n-2)/6-eps)cout<<i,exit(0);
	}
}