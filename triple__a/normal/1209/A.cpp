#include<bits/stdc++.h>
using namespace std;

int n;
int a[107];
bool vis[107];
int main(){
	cin>>n;
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	for (int i=1;i<=n;++i){
		if (!vis[i]){
			++ans;
			vis[i]=1;
			for (int j=i+1;j<=n;++j){
				if (a[j]%a[i]==0) vis[j]=1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}