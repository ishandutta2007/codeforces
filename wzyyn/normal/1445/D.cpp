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
const int N=150005;
const int mo=998244353;
int a[N*2],n;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	scanf("%d",&n);
	For(i,1,2*n) scanf("%d",&a[i]);
	sort(a+1,a+2*n+1);
	int ans=0;
	For(i,1,n) ans=(ans+a[2*n+1-i]-a[i])%mo;
	For(i,1,n) ans=1ll*ans*(2*n+1-i)%mo*power(i,mo-2)%mo;
	cout<<ans<<endl;
}