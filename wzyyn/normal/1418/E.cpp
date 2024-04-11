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
const int mo=998244353;
const int N=500005;
int n,m,a[N],s[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	For(i,1,n) s[i]=(s[i-1]+a[i])%mo;
	while (m--){
		int x,y;
		scanf("%d%d",&x,&y);
		int p=lower_bound(a+1,a+n+1,y)-a;
		int ans=0,l=(n-p+1); 
		if (l>=x) ans=(ans+1ll*s[p-1]*power(l+1,mo-2)%mo*(l+1-x))%mo;
		if (l>x) ans=(ans+1ll*(s[n]-s[p-1]+mo)*power(l,mo-2)%mo*(l-x))%mo;
		cout<<ans<<endl;
	}
}