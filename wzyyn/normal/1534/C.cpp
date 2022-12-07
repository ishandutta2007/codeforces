#include<bits/stdc++.h>

using namespace std;

const int N=400005;
int a[N],b[N],nx[N],vis[N],n,ans;

void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for (int i=1;i<=n;i++){
		nx[a[i]]=b[i];
		vis[i]=0;
	}
	ans=1;
	for (int i=1;i<=n;i++)
		if (!vis[i]){
			ans=2*ans%1000000007;
			for (int j=i;!vis[j];){
				vis[j]=1;
				j=nx[j];
			}
		}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}