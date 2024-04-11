#include<bits/stdc++.h>
using namespace std;
int n,m,a[510][510];
int main(){
	cin>>n;
	if(n<3){
		cout<<-1;
		return 0;
	}
	a[1][n-1]=n*n,a[n][n]=n*n-1;
	for(int i=1;i<n;i++)a[i][n]=n*n-i-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
		if(!a[i][j])a[i][j]=++m;
		cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}