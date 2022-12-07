#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
using namespace std;

const int mo=998244353;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int n,a[200005];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if (a[n]>a[n-1]+1)
		puts("0");
	else{
		int ans=1;
		for (int i=2;i<=n;i++)
			ans=1ll*ans*i%mo;
		if (a[n]!=a[n-1]){
			int p=n-1;
			for (;a[p-1]==a[n-1];--p);
			ans=(ans+mo-1ll*ans*power(n-p+1,mo-2)%mo)%mo;
		}
		cout<<ans<<endl;
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}