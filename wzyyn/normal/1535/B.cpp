#include<bits/stdc++.h>
using namespace std;
int n,ans,a[2005];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ans=0;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (gcd(a[i],a[j])!=1) ++ans;
			else if (a[i]%2==0||a[j]%2==0) ++ans;
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}