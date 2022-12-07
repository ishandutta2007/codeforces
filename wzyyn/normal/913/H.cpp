#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int V=1000000;
const int mo=998244353;
const int N=35,M=2005;
int n,top,C[N][N];
int a[N],P[M],q[M];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void init(){
	For(i,0,N-1) C[i][0]=1;
	For(i,1,N-1) For(j,1,i) C[i][j]=C[i-1][j]+C[i-1][j-1]; 
	For(i,0,N-1) For(j,0,i) For(k,j+1,i)
		C[i][j]=1ll*C[i][j]*(mo-V)%mo;
}
struct Poly{
	int a[N];
	Poly(){
		memset(a,0,sizeof(a));
	}
	Poly GF(){
		Poly ans;
		For(i,1,N-1)
			ans.a[i]=1ll*a[i-1]*power(i,mo-2)%mo;
		return ans;
	}
	int F(int x){
		int ans=0;
		Rep(i,N-1,0)
			ans=(1ll*ans*x+a[i])%mo;
		return ans;
	}
	Poly operator -(const Poly &b)const{
		Poly ans;
		For(i,0,N-1) ans.a[i]=(a[i]+mo-b.a[i])%mo;
		return ans;
	}
	Poly tr(){
		Poly ans;
		For(i,0,N-1) For(j,0,i)
			ans.a[j]=(ans.a[j]+1ll*C[i][j]*a[i])%mo;
		return ans;
	}
}f[M],g[M];
int main(){
	init();
	scanf("%d",&n);
	For(i,1,n){
		double x;
		scanf("%lf",&x);
		a[i]=(int)(x*V+0.49);
	}
	Rep(i,n-1,1) a[i]=min(a[i],a[i+1]);
	For(i,1,n) a[i]=min(a[i],a[i-1]+V);
	//For(i,1,n) cout<<a[i]<<endl;
	f[0].a[0]=0; P[0]=-(1<<30);
	f[1].a[0]=1; P[1]=0;
	f[2].a[0]=0; P[2]=min(a[1],V);
	top=2;
	For(i,2,n){
		*q=0; q[++*q]=a[i];
		For(j,1,top){
			q[++*q]=P[j];
			q[++*q]=P[j]+V;
		}
		q[++*q]=1<<30;
		sort(q+1,q+*q+1);
		*q=unique(q+1,q+*q+1)-q-1;
		for (;q[*q]!=a[i];--*q);
		//cout<<*q<<endl;
		For(j,0,top) f[j]=f[j].GF();
		For(j,1,top){
			f[j].a[0]=(f[j].a[0]+mo-f[j].F(P[j]))%mo;
			f[j].a[0]=(f[j].a[0]+f[j-1].F(P[j]))%mo;
		}
		int p1=0,p2=0;
		For(j,0,*q){
			for (;p1!=top&&P[p1+1]<q[j+1]-V;++p1);
			for (;p2!=top&&P[p2+1]<q[j+1];++p2);
			g[j]=f[p2]-f[p1].tr();
			if (j==(*q)) memset(g[j].a,0,sizeof(g[j].a));
		}
		top=*q;
		For(j,1,top) P[j]=q[j];
		For(j,1,top) f[j]=g[j];
	}
	int ans=0;
	For(i,1,top-1){
		f[i]=f[i].GF();
		ans=(ans+f[i].F(P[i+1]))%mo;
		ans=(ans+mo-f[i].F(P[i]))%mo;
	}
	ans=1ll*ans*power(V,mo-1-n)%mo;
	printf("%d\n",ans);
}