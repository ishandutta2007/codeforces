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
const int N=1000005;
const int mo=1000000007;
int n,x;
int a[N],b[N],c[N];
void UPD(int &x,int y){
	(x+=y)>=mo?x-=mo:233;
}
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&x),++a[x];
	For(i,0,999999) b[i]=1ll*i*a[i]%mo,c[i]=1ll*i*i*a[i]%mo;
	for (int i=1;i<1000000;i*=10)
		for (int j=0;j<1000000;j+=10*i)
			Rep(k,j+9*i-1,j){
				UPD(a[k],a[k+i]);
				UPD(b[k],b[k+i]);
				UPD(c[k],c[k+i]);
			}
	For(i,0,999999) if (a[i]){
		int v1=1ll*c[i]*power(2,a[i]-1)%mo;
		int v2=(1ll*b[i]*b[i]+mo-c[i])%mo*power(2,a[i]-2)%mo;
		//cout<<i<<' '<<v1<<' '<<v2<<endl;
		a[i]=(v1+v2)%mo;
	}
	for (int i=1;i<1000000;i*=10)
		for (int j=0;j<1000000;j+=10*i)
			For(k,j,j+9*i-1) UPD(a[k],mo-a[k+i]);
	ll ans=0;
	For(i,0,999999)
		ans^=1ll*i*a[i];
	printf("%lld\n",ans);
}