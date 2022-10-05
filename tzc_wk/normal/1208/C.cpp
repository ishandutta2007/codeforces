#include <bits/stdc++.h>
using namespace std;
int n,a[1005][1005],cnt;
int main(){
	cin>>n;
	for(int i=1;i<=n/2;i++){
		for(int j=1;j<=n/2;j++){
			a[i][j]=cnt++;
			a[i+n/2][j]=cnt++;
			a[i][j+n/2]=cnt++;
			a[i+n/2][j+n/2]=cnt++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)	cout<<a[i][j]<<" ";
		cout<<endl;
	}
}