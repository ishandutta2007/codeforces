#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,a[100020];
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0,t=0;
	for(int i=1;i<=n;i++){
		if(t<=a[i]){
			ans+=1;
			t+=a[i];	
		}
	}
	cout<<ans;
	return 0;
}