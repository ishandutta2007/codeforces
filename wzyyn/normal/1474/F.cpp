#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

const int mo=998244353;
const int N=55;
int n,ans;
int C[N][N],tr[N][N+5];
ll d[N],q[N*N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void init(){
	For(i,0,N-1) C[i][0]=1;
	For(i,1,N-1) For(j,1,i) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
	For(i,0,N-1){
		static int f[N+5];
		static int g[N+5];
		memset(f,0,sizeof(f));
		f[0]=1;
		For(j,0,i+1) Rep(k,j,0){
			f[k+1]=(f[k+1]+f[k])%mo;
			f[k]=1ll*(mo-j)*f[k]%mo;
		}
		int S=0;
		For(j,0,i+1){
			S=(S+power(j,i))%mo;
			memcpy(g,f,sizeof(g));
			Rep(k,i+2,1) g[k-1]=(g[k-1]+1ll*j*g[k])%mo;
			int fac=1;
			For(k,0,i+1) if (k!=j) fac=1ll*fac*(j+mo-k)%mo;
			int vtr=1ll*S*power(fac,mo-2)%mo;
			For(k,1,i+2) tr[i][k-1]=(tr[i][k-1]+1ll*vtr*g[k])%mo;
		}
	}
}
struct Func{
	int a[N];
	Func(){
		memset(a,0,sizeof(a));
	}
	Func(int v){
		memset(a,0,sizeof(a));
		a[0]=v;
	}
	Func operator +(const Func &b)const{
		Func re;
		For(i,0,N-1) re.a[i]=(a[i]+b.a[i])%mo;
		return re;
	}
	int F(ll v){
		int re=0; v%=mo;
		Rep(i,N-1,0) re=(1ll*re*v+a[i])%mo;
		return re;
	}
	Func dec(){
		Func re;
		For(i,0,N-1) Rep(j,i,0)
			re.a[j]=(re.a[j]+1ll*a[i]*((i-j)&1?mo-C[i][j]:C[i][j]))%mo;
		return re;
	}
	Func Integeral(){
		Func re;
		For(i,0,N-2) For(j,0,i+1)
			re.a[j]=(re.a[j]+1ll*a[i]*tr[i][j])%mo;
		return re;
	}
}f[N*N];
void UPD(int l,int r){
	//cout<<l<<' '<<r<<' '<<ans<<endl;
	*q=0;
	For(i,l,r) For(j,-1,25) q[++*q]=d[i]+j;
	q[++*q]=-(1ll<<40); q[++*q]=(1ll<<40);
	sort(q+1,q+*q+1);
	*q=unique(q+1,q+*q+1)-q-1;
	For(i,1,*q) f[i]=Func(0);
	int x=lower_bound(q+1,q+*q+1,d[l])-q;
	f[x]=Func(1);
	For(i,l+1,r){
		if (d[i-1]==d[i]) continue;
		int y=lower_bound(q+1,q+*q+1,d[i])-q;
		for (;x<y;){
			int v=(f[x].F(q[x])+f[x+1].F(q[x]+1))%mo;
			f[x+1]=f[x+1].Integeral();
			f[x+1].a[0]=(f[x+1].a[0]+1ll*mo-f[x+1].F(q[x]+1)+v)%mo;
			++x;
		}
		for (;x>y;){
			--x;
			if (q[x]-1==q[x-1])
				f[x]=f[x]+f[x-1].dec();
			else
				f[x]=f[x]+f[x].dec();
		}
		if (d[i]==d[l]) f[x].a[0]=(f[x].a[0]+1)%mo;
	}
	ans=(ans+f[x].F(q[x]))%mo;
}
int main(){
	init();
	scanf("%d",&n);
	scanf("%lld",&d[0]);
	For(i,1,n) scanf("%lld",&d[i]);
	For(i,1,n) d[i]+=d[i-1];
	ll val=0;
	For(i,0,n) For(j,i,n) val=max(val,d[j]-d[i]);
	if (val==0){
		printf("1 %d\n",(d[0]-d[n]+1)%mo);
		return 0;
	}
	For(i,0,n) if (d[i]!=-(1ll<<40)){
		int p=-1;
		For(j,i+1,n) if (d[j]-d[i]==val) p=j;
		if (p!=-1){
			UPD(i,p);
			For(j,i,p) d[j]=-(1ll<<40); 
		}
	}
	printf("%lld %d\n",val+1,ans); 
}
/*
ST ED
:f[i]=f[i]+f[i-1]
:f[i]=f[i] 
*/