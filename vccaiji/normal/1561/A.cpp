#include<bits/stdc++.h>
using namespace std;
int a[1200];
int main(){
	int _;
	cin>>_;
	while(_--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;;i++){
			bool r=1;
			for(int i=1;i<=n;i++)if(a[i]!=i)r=0;
			if(r){
				cout<<i-1<<endl;
				break;
			}
			if(i&1){
				for(int j=1;j<=n-2;j+=2)if(a[j]>a[j+1])swap(a[j],a[j+1]);
			}
			else{
				for(int j=2;j<=n-1;j+=2)if(a[j]>a[j+1])swap(a[j],a[j+1]);
			} 
		}
	}
	return 0;
}