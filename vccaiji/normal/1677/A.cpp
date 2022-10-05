//#pragma optimize("offast")
#include<bits/stdc++.h>
using namespace std;
int _,n;
int p[5100];
int o[5100][5100];
int oo[5100];
int main(){
	cin>>_;
	while(_--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>p[i];
		long long ans=0;
		for(int j=2;j<=n-1;j++){
			o[j][j]=0;
			for(int i=j-1;i>=1;i--){
				if(p[i]>p[j+1])o[i][j]=o[i+1][j]+1;
				else o[i][j]=o[i+1][j];
			}
		}
		for(int i=1;i<=n;i++){
			oo[i]=0;
			for(int j=i+2;j<=n;j++)if(p[i]>p[j])oo[i]++;
		}
		for(int i=1;i<=n;i++){
			int t=0;
			for(int j=i+1;j<n;j++){
				if(p[i]<p[j])ans+=t;
				t-=o[i+1][j];
				t+=oo[j];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}