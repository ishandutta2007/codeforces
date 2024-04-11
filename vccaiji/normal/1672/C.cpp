#include<bits/stdc++.h>
using namespace std;
int a[310000];
int main(){
	int _;
	cin>>_;
	while(_--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		int ans=0;
		bool r=0;
		for(int i=1;i<n;i++){
			if(a[i]==a[i+1])r=1;
		}
		if(!r)cout<<0<<endl;
		else{
			int j=0;
			for(int i=1;i<n;i++){
				if(a[i]==a[i+1])break;
				j++;
			}
			for(int i=n;i>1;i--){
				if(a[i]==a[i-1])break;
				j++; 
			}
			j=n-j;
			cout<<(j<=3 ? j-2 : j-3)<<endl;
		}
	}
	return 0;
}