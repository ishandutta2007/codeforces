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
const int mo=1000000007;
const int N=505;
struct Num{
	int a,b;//a+b*sqrt(5)
	/*
	ax+5by=1
	bx+ay=0
	
	(5b^2-a^2)y=b
	*/ 
	Num(){}
	Num(int _a,int _b){
		a=_a; b=_b;
	}
	Num operator +(const Num &x)const{
		return Num((a+x.a)%mo,(b+x.b)%mo);
	}
	Num operator -(const Num &x)const{
		return Num((a+mo-x.a)%mo,(b+mo-x.b)%mo);
	}
	Num operator *(const Num &x)const{
		return Num((1ll*a*x.a+5ll*b*x.b)%mo,(1ll*a*x.b+1ll*b*x.a)%mo);
	}
	Num operator *(const int &x)const{
		return Num(1ll*a*x%mo,1ll*b*x%mo);
	}
};
int K;
ll l,r;
Num pA[N],pB[N],pv[N];
int fac[N],inv[N];
int f[N],v[N];
void init(){
	fac[0]=inv[0]=inv[1]=1;
	For(i,2,N-1) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	For(i,1,N-1) inv[i]=1ll*inv[i-1]*inv[i]%mo;
	For(i,1,N-1) fac[i]=1ll*fac[i-1]*i%mo; 
}
int Binom(int x,int y){
	if (x<0||y<0||y>x) return 0;
	return 1ll*fac[x]*inv[y]%mo*inv[x-y]%mo;
}
Num power(Num a,ll b){
	Num s(1,0);
	for (;b;b/=2,a=a*a)
		if (b&1) s=s*a;
	return s;
}
Num Qsum(ll l,ll r,Num A){
	Num p1(1,0),s1(0,0),p2=A,s2(1,0);
	ll T=r-l+1;
	for (;T;){
		if (T&1){
			s1=s1+p1*s2;
			p1=p1*p2;
		}
		if (T/=2){
			s2=s2+p2*s2;
			p2=p2*p2;
		}
	}
	s1=s1*power(A,l);
	return s1;
}
int main(){
	scanf("%d%lld%lld",&K,&l,&r);
	Num B((mo+1)/2,(mo+1)/2);
	Num C((mo+1)/2,(mo-1)/2);
	Num A(0,(2*mo+1)/5);
	init();
	For(i,0,K) For(j,0,K-i){
		Num tmp=Qsum(l+2,r+2,power(B,i)*power(C,j));
		//cout<<tmp.a<<' '<<tmp.b<<' '<<i<<' '<<j<<endl;
		pv[i+j]=pv[i+j]+tmp*Binom(i+j,i)*(j&1?mo-1:1); 
	}
	//For(i,0,K) cout<<pv[i].a<<' '<<pv[i].b<<endl;
	//debug;
	For(i,0,K) v[i]=(pv[i]*power(A,i)).a;
	f[0]=1;
	For(i,1,K) Rep(j,i,1){
		f[j]=(f[j]+f[j-1])%mo;
		f[j-1]=1ll*f[j-1]*(mo+1-i)%mo;
	}
	int ans=0;
	//For(i,0,K) printf("%d ",v[i]); puts("");
	//For(i,0,K) printf("%d ",f[i]); puts("");
	For(i,0,K) ans=(ans+1ll*f[i]*v[i])%mo;
	ans=1ll*ans*inv[K]%mo;
	printf("%d\n",ans);
}
/*
a*(b^(n+2)+c^(n+2))^k
b=(sqrt(5)+1)/2 c=(1-sqrt(5))/2 a=1/sqrt(5)

(a*(b^3-c^3))^2
a^2*(b^6-2b^3c^3+c^6)
*/