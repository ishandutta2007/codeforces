#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=200005;
const int mo=998244353;
int n,x[N],y[N],s[N],f[N],a[N];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d%d",&x[i],&y[i],&s[i]);
	int ans=(x[n]+1)%mo;
	for (int i=1;i<=n;i++){
		int p=lower_bound(x+1,x+n+1,y[i])-x;
		f[i]=((a[i-1]+mo-a[p-1])%mo+1ll*(x[i]-y[i]))%mo;
		a[i]=(a[i-1]+f[i])%mo;
		if (s[i]) ans=(ans+f[i])%mo;
		//cout<<f[i]<<' '; cout<<endl;
	}
	cout<<ans<<endl;
}