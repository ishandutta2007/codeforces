#include<bits/stdc++.h>
using namespace std;
int n;
int a[75];
int main(){
	int _;
	cin>>_;
	while(_--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		int ans=n-1;
		for(int j=1;j<=n;j++)for(int k=j+1;k<=n;k++){
			int u=0;
			for(int o=1;o<=n;o++){
				if((a[o]-a[j])*(k-o)!=(a[k]-a[o])*(o-j))u++;
			}
			ans=min(ans,u);
		}
		cout<<ans<<endl;
	} 
	return 0;
}