#include<bits/stdc++.h>
using namespace std;

const int N=23;
const int M=50005;
const int mo=998244353;
int n,m,ans;
int a[N][M],f[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void solve(int id){
	for (int i=1;i<=n+1;i++) f[i]=0;
	for (int i=1;i<=n+1;i++) f[a[i][id]]++;
	int rem=f[n+1],way=1;
	for (int i=n;i>=1;i--){
		way=1ll*way*(rem--)%mo;
		rem+=f[i];
	}
	ans=(ans+way)%mo;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for (int i=1;i<=m;i++)
		solve(i);
	for (int i=1;i<=n;i++)
		ans=1ll*ans*power(i,mo-2)%mo;
	ans=(m+mo-ans)%mo;
	cout<<ans<<endl;
}