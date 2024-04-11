#include<bits/stdc++.h>
using namespace std;
#define INF 50000
int n;
int t[210];
int o[210][410];
int main(){
	int _;
	cin>>_;
	while(_--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>t[i];
		sort(t+1,t+n+1);
		for(int i=0;i<=2*n+1;i++)o[n+1][i]=0;
		for(int i=n;i>=1;i--){
			for(int j=0;j<=2*n+1;j++){
				o[i][j]=INF;
				for(int k=j+1;k<=2*n+1;k++){
				    o[i][j]=min(o[i][j],o[i+1][k]+abs(k-t[i]));
			    }
			}
		}
		cout<<o[1][0]<<endl;
	}
	return 0;
}