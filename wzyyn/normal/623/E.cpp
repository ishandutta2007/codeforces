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
const int N=30005;
const int mo=1000000007;
int fac[N],inv[N],k;
ll n;
struct node{
	int len,a[N*2];
};
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void init(){
	fac[0]=inv[0]=inv[1]=1;
	For(i,2,N-1) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	For(i,1,N-1) inv[i]=1ll*inv[i-1]*inv[i]%mo;
	For(i,1,N-1) fac[i]=1ll*fac[i-1]*i%mo;
}
int C(int x,int y){
	return 1ll*fac[x]*inv[y]%mo*inv[x-y]%mo;
}
void Multiply(int *a,int *b,int n,int *c){
	//cout<<n<<endl;
	if (n<=30){
		For(i,0,2*n) c[i]=0;
		For(i,0,n-1) For(j,0,n-1)
			c[i+j]=(c[i+j]+1ll*a[i]*b[j])%mo;
		return;
	}
	int nn=n/2;
	int *res1=new int[n+3];
	int *res2=new int[n+3];
	int *res3=new int[n+3];
	int *sa=new int[n+1];
	int *sb=new int[n+1];
	For(i,nn,n-1){
		sa[i-nn]=a[i];
		sb[i-nn]=b[i];
	}
	For(i,0,nn-1){
		sa[i]=(sa[i]+a[i])%mo;
		sb[i]=(sb[i]+b[i])%mo;
	}
	Multiply(a,b,nn,res1);
	Multiply(a+nn,b+nn,n-nn,res2);
	Multiply(sa,sb,n-nn,res3);
	For(i,0,2*n) c[i]=0;
	For(i,0,2*(nn-1)) c[i]=res1[i];
	For(i,0,2*(n-1-nn)) c[i+nn*2]=res2[i];
	For(i,0,2*(n-1-nn)){
		res3[i]=(res3[i]+2ll*mo-res1[i]-res2[i])%mo;
		c[i+nn]=(c[i+nn]+res3[i])%mo;
	}
	delete[] res1;
	delete[] res2;
	delete[] res3;
	delete[] sa;
	delete[] sb;
}
node merge(node a,node b){
	node c;
	memset(c.a,0,sizeof(c.a));
	c.len=a.len+b.len;
	For(i,0,k) a.a[i]=1ll*a.a[i]*power(2,b.len*(i+a.len))%mo;
	For(i,0,k) a.a[i]=1ll*a.a[i]*inv[i+a.len]%mo;
	For(i,0,k) b.a[i]=1ll*b.a[i]*inv[i+b.len]%mo;
	Multiply(a.a,b.a,k+1,c.a);
	For(i,0,k) c.a[i]=1ll*c.a[i]*fac[i+c.len]%mo;
	For(i,k+1,2*k) c.a[i]=0;
	return c;
}
node power(node a,int n){
	node s; s.len=0; s.a[0]=1;
	for (;n;n/=2,a=merge(a,a))
		if (n&1) s=merge(s,a);
	return s;
}
int main(){
	init();
	scanf("%lld%d",&n,&k);
	if (n>k) return puts("0"),0;
	node tmp; tmp.len=1; k-=n;
	For(i,0,k) tmp.a[i]=1;
	tmp=power(tmp,n);
	int ans=0;
	For(i,0,k) ans=(ans+1ll*C(k+n,i+n)*tmp.a[i])%mo;
	printf("%d\n",ans);
}
/*
5 10
255704347
*/