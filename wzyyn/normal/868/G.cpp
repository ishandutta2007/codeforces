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
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
struct Func{
	int k,b;
	Func(){}
	Func(int _k,int _b){
		k=_k; b=_b;
	}
	Func operator +(const Func &a)const{
		return Func((k+a.k)%mo,(b+a.b)%mo);
	}
	Func operator -(const Func &a)const{
		return Func((k+mo-a.k)%mo,(b+mo-a.b)%mo);
	}
	Func operator *(const Func &a)const{
		return Func(1ll*k*a.k%mo,(1ll*b*a.k+a.b)%mo);
	}
	Func inverse(){
		int tmp=power(k,mo-2);
		return Func(tmp,1ll*(mo-tmp)*b%mo);
	}
};
Func pow1(Func x,int y){
	Func s(1,0);
	for (;y;y/=2,x=x*x)
		if (y&1) s=s*x;
	return s;
}
Func pow2(Func x,int y,Func tr){
	Func s1(0,0),s2=x,s3(1,0),s4=x;
	int adv=1ll*(y-1)*tr.b%mo;
	for (;y;){
		if (y&1) s1=s1+s2*s3,s2=s2*s4;
		if (y/=2) s3=s3+s4*s3,s4=s4*s4;
	}
	s1=s1*tr+Func(0,adv);
	return s1;
}
int exx_gcd(int n,int k,Func f1,Func f2,Func f3,Func f4){
	//cout<<n<<' '<<k<<endl;
	//cout<<f1.k<<' '<<f1.b<<' '<<f2.k<<' '<<f2.b<<endl;
	//cout<<f3.k<<' '<<f3.b<<' '<<f4.k<<' '<<f4.b<<endl;
	if (!k){
		//cout<<f3.k<<' '<<f3.b<<endl;
		//cout<<f4.k<<' '<<f4.b<<endl;
		int val=1ll*(mo-f3.b)*power(f3.k-1,mo-2)%mo;
		//cout<<val<<' '
		return (1ll*f2.k*val+f2.b)%mo;
	}
	Func F1=f1+pow2(f3,n/k,f2);
	Func F2=f1+pow2(f3,n/k-1,f2);
	Func F3=(pow1(f3,n/k-1)*f4).inverse();
	Func F4=(pow1(f3,n/k)*f4).inverse();
	return exx_gcd(k,n%k,F1,F2,F3,F4);
}
int gcd(int x,int y){
	return y?gcd(y,x%y):x; 
}
void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	Func f1(1,0),f2(1,0),f3(1,1),f4((mo+1)/2,1);
	int v=gcd(n,k); n/=v; k/=v;
	printf("%d\n",1ll*power(n,mo-2)*exx_gcd(n,k,f1,f2,f3,f4)%mo);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}