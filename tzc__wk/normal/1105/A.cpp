#include <bits/stdc++.h>
using namespace std;
int n,m,a[1001]; 
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	pair<int,int> ans=pair<int,int>(0,INT_MAX);
	for(int t=1;t<=101;t++){
		int cost=0;
		for(int i=0;i<n;i++){
			int add=min(abs(a[i]-t-1),min(abs(a[i]-t+1),abs(a[i]-t)));
			cost+=add;
		}
		if(ans.second>cost)	ans.second=cost,ans.first=t;
	}
	cout<<ans.first<<" "<<ans.second;
	return 0;
}