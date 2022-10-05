#include<bits/stdc++.h>
using namespace std;
int ans[40000];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<32768;i++){
		ans[i]=100;
		for(int j=0;j<=15;j++){
			ans[i]=min(ans[i],15-j+((((i-1)>>j)+1)<<j)-i);
		}
	}
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		cout<<ans[a]<<' ';
	} 
	return 0;
}