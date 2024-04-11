#include<bits/stdc++.h>

using namespace std;

int n,a[105],b[105];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int ans=1;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++){
			int s=0;
			for (int k=1;k<=n;k++)
				if ((k-i)*(a[j]-a[i])==(j-i)*(a[k]-a[i]))
					++s;
			ans=max(ans,s);
		}
	cout<<n-ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}