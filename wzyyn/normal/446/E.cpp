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
const int mo=1051131;
const int N=1<<25;
int a[N],n,s;
ll T;
int power(int x,ll y){
	int s=1; x%=mo;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void Func(int n,int p,int q){
	//cout<<p<<' '<<q<<' '<<n<<endl;
	if (n==0){
		a[0]=1ll*a[0]*power(p+q,T)%mo;
		return;
	}
	int m=(1<<(n-1));
	int r=(m-1)*p%mo;
	For(i,0,m-1){
		int x=a[i],y=a[i+m];
		a[i]=(x+y)%mo;
		a[i+m]=(x+mo-y)%mo;
	}
	Func(n-1,2ll*p%mo,(q+r)%mo);
	int val=power(q+mo-r,T);
	For(i,0,m-1){
		int x=a[i],y=1ll*a[i+m]*val%mo;
		a[i]=(x+y)*1ll*(mo+1)/2%mo;
		a[i+m]=(x+mo-y)*1ll*(mo+1)/2%mo;
	}
}
int main(){
	scanf("%d%lld%d",&n,&T,&s);
	For(i,0,s-1) scanf("%d",&a[i]);
	For(i,s,(1<<n)-1) a[i]=(a[i-s]*101+10007)%mo;
	Func(n,1,0);
	int ans=0;
	For(i,0,(1<<n)-1) ans^=a[i];
	printf("%d\n",ans);
}
/*
X X+rI
X+rI X


(a b) 

(2X+rI)^t+(-rI)^t (2X+rI)^t-(-rI)^t 
(2X+rI)^t-(-rI)^t (2X+rI)^t+(-rI)^t

(a+b)(2X+rI)^t+(a-b)(-rI)^t (a+b)(2X+rI)^t-(a-b)(-rI)^t

(pX+qI)^T

pX+qI pX+rI
pX+rI pX+qI


r=q+p*(2^n-1)

(2pX+(q+r)I)^T+(q-r)^TI 

 
*/