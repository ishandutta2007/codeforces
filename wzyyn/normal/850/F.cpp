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
const int N=100005;
int n,ans,s,a[N],f[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]),s+=a[i];
	f[1]=1ll*(s-1)*(s-1)%mo*power(s,mo-2)%mo;
	//cout<<f[1]<<' '<<f[2]<<' '<<f[3]<<endl;
	For(i,1,N-2) f[i+1]=(2ll*f[i]+2ll*mo-f[i-1]-1ll*(s-1)*power(s-i+mo,mo-2)%mo)%mo;
	For(i,1,n) ans=(ans+f[a[i]])%mo;
	printf("%d\n",ans);
}