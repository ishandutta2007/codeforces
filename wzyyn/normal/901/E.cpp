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
const int N=400005;
ll b[N],c[N],da[N];
ll A[N],B[N],p[N];
ll g,moo;
int n,FFTN;
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
ll mul(ll x,ll y){
	ll t=x*y-(ll)((long double)x/moo*y)*moo;
	return (t%moo+moo)%moo;
}
ll power(ll x,ll y){
	ll s=1;
	for (;y;y/=2,x=mul(x,x))
		if (y&1) s=mul(s,x);
	return s;
}
void init_root(){
	FFTN=4;
	for (;FFTN<=n*2;FFTN<<=1);
	ll dif=FFTN/gcd(FFTN,n)*1ll*n;
	moo=(100000000/dif+1)*dif+1;
	for (;;moo+=dif){
		bool flag=0;
		for (int i=2;1ll*i*i<=moo&&!flag;i++)
			if (moo%i==0) flag=1;
		if (!flag) break;
	}
	static ll di[50];
	ll x=moo-1;
	for (int i=2;1ll*i*i<=x;i++)
		if (x%i==0){
			di[++*di]=i;
			for (;x%i==0;x/=i);
		}
	if (x!=1) di[++*di]=x;
	//cout<<*di<<' '<<moo<<' '<<di[1]<<' '<<di[4]<<endl;
	for (g=1;;++g){
		bool flag=0;
		//cout<<g<<endl;
		For(i,1,*di)
			if (power(g,(moo-1)/di[i])==1){
				flag=1; break;
			}
		//cout<<g<<endl;
		if (!flag) break;
	}
	//cout<<"ROOT "<<g<<' '<<moo<<endl;
	p[0]=1;
	p[1]=power(g,(moo-1)/n);
	For(i,2,n-1) p[i]=mul(p[i-1],p[1]);
}
int R[N];
int FFT_init(int n){
	int L=1;
	for (;L<=n;L<<=1);
	For(i,0,L-1) R[i]=(R[i>>1]>>1)|((i&1)?(L>>1):0);
	return L;
}
void _DFT(ll *a,int n,int f){
	For(i,0,n-1) if (i<R[i]) swap(a[i],a[R[i]]);
	for (int d=1;d<n;d<<=1){
		ll w=power(g,(moo-1)/(d<<1));
		if (f==-1) w=power(w,moo-2);
		for (int i=0;i<n;i+=(d<<1)){
			ll wn=1;
			for (int j=0;j<d;j++){
				ll y=mul(a[i+j+d],wn);
				a[i+j+d]=(a[i+j]+moo-y)%moo;
				a[i+j]=(a[i+j]+y)%moo;
				wn=mul(wn,w);
			}
			//cout<<wn<<endl;
		}
	}
	if (f==-1){
		ll val=power(n,moo-2);
		For(i,0,n-1) a[i]=mul(a[i],val);
	}
}
void DFT(ll *a,int f=1){
	int L=FFT_init(2*n);
	static ll A[N],B[N];
	For(i,0,L-1) A[i]=B[i]=0; 
	//For(i,0,n-1) A[i]=a[i],a[i]=0;
	//For(i,0,n-1) For(j,0,n-1) a[j]=(a[j]+mul(A[i],p[(n+1ll*f*i*j%n)%n]))%moo;
	For(i,0,2*n) A[i]=p[(n+1ll*i*(i+1)/2*f%n)%n];
	For(i,0,n) B[n-i]=mul(a[i],p[(n-1ll*i*(i+1)/2*f%n)%n]);
	_DFT(A,L,1); _DFT(B,L,1);
	For(i,0,L-1) A[i]=mul(A[i],B[i]);
	_DFT(A,L,-1);
	For(i,0,n) a[i]=mul(A[i+n],p[(n-1ll*i*(i+1)/2*f%n)%n]);
	if (f==-1){
		ll val=power(n,moo-2);
		For(i,0,n-1) a[i]=mul(a[i],val);
	}
}
set<ll> S;
void calc_root(ll a,ll b,ll c){
	ll delta=b*b-4*a*c;
	if (delta<0) return;
	ll v=(ll)(sqrt(delta)-0.5);
	for (;v*v<delta;++v);
	//cout<<"EQ "<<delta<<' '<<v<<endl;
	if (v*v!=delta) return;
	if ((-b+v)%(2*a)==0) S.insert((-b+v)/(2*a));
	if ((-b-v)%(2*a)==0) S.insert((-b-v)/(2*a));
}
/*
ax^2+bx+a=0
*/
void GG(){
	puts("0");
	exit(0);
}
int main(){
	#ifdef zyy
		freopen("1.in","r",stdin);
	#endif
	scanf("%d",&n);
	init_root();
	For(i,0,n-1) scanf("%lld",&b[i]);
	For(i,0,n-1) scanf("%lld",&c[i]);
	For(i,0,n-1) if ((c[i]+c[0])&1) GG();
	For(i,0,n-1) A[i]=((c[(i+1)%n]-c[i])/2+moo)%moo,B[(n-i)%n]=b[i];
	//For(i,0,n-1) cout<<A[i]<<' '; cout<<endl;
	DFT(A); DFT(B);
	//cout<<moo<<' '<<power(3,moo-2)<<endl;
	//For(i,0,n-1) cout<<A[i]<<' '; cout<<endl;
	//For(i,0,n-1) cout<<B[i]<<' '; cout<<endl;
	For(i,0,n-1) A[i]=mul(A[i],power(B[i],moo-2));
	//For(i,0,n-1) cout<<A[i]<<' '; cout<<endl;
	DFT(A,-1);
	//For(i,0,n-1) cout<<A[i]<<' '; cout<<endl;
	For(i,0,n-1){
		if (A[i]<10000) da[i]=A[i];
		else if (A[i]>=moo-10000) da[i]=A[i]-moo;
		else GG();
	}
	//For(i,0,n-1) cout<<da[i]<<' '; cout<<endl;
	ll dsum=0,va=0,vb=0,vc=0;
	For(i,0,n-1){
		//cout<<b[i]<<' '<<dsum<<endl;
		ll v=b[i]-dsum;
		va+=v*v; vb-=2*v; vc++;
		dsum-=da[i];
	}
	//cout<<dsum<<' '<<va-c[0]<<' '<<vb<<' '<<vc<<endl;
	if (dsum) GG();
	calc_root(vc,vb,va-c[0]);
	printf("%d\n",S.size());
	for (auto i:S){
		ll val=i;
		For(j,0,n-1){
			printf("%lld ",val);
			val-=da[j];
		}
		puts("");
	}
}
/*
C[i]=sigma((B[j]-A[i+j]))^2
C[i]-C[i+1]=2B[j](A[i+j]-A[i][j+1])%mo


*/