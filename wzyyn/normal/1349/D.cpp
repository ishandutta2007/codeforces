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
const int N=300005;
const int mo=998244353;
int n,S;
int a[N],f[N];
int f1[N],f2[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) S+=a[i];
	f1[S]=0; f1[S-1]=1; f2[S]=0; f2[S-1]=0;
	Rep(i,S-1,1){
		int p1=1ll*i*power(S,mo-2)%mo;
		int p2=1ll*(S-i)*power(S,mo-2)%mo*(n-2)%mo*power(n-1,mo-2)%mo;
		int p3=1ll*(S-i)*power(S,mo-2)%mo*power(n-1,mo-2)%mo;
		//assert((1ll*p1+p2+p3)%mo==1);
		f1[i-1]=(f1[i]+2ll*mo  -1ll*f1[i+1]*p3%mo-1ll*f1[i]*p2%mo)*power(p1,mo-2)%mo;
		f2[i-1]=(f2[i]+3ll*mo-1-1ll*f2[i+1]*p3%mo-1ll*f2[i]*p2%mo)*power(p1,mo-2)%mo;
	}
	int ff0=(f1[0]+mo-f1[1])%mo;
	int ff1=(f2[0]+mo-f2[1])%mo;
	ff1=(ff1+mo-(n-1))%mo;
	int val=1ll*(mo-ff1)*power(ff0,mo-2)%mo;
	For(i,0,S) f[i]=(1ll*f1[i]*val+f2[i])%mo;
	//For(i,0,S) cout<<f[i]<<endl;
	int ans=0;
	For(i,1,n) ans=(ans+f[a[i]])%mo;
	For(i,1,n-1) ans=(ans+mo-f[0])%mo;
	printf("%d\n",1ll*ans*power(n,mo-2)%mo);
}
/*
f0=((n-2)f0+f1)/n-1+1
*/