#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,l,max=0,ans=0,i,j,a[100];
	cin>>n>>l;
	for(i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>max) max=a[i];
	}
	for(i=l;i<=max;i++){
		int sum=0;
		for(j=0;j<n;j++) sum+=a[j]/i;
		if(sum*i>ans) ans=sum*i;
	}
	cout<<ans<<endl;
	return 0;
}