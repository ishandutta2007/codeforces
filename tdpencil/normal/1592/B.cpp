// not my code just so i can pass idk
#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005],f;
int main(){
	int t,n,i,x;
	cin>>t;
	while(t--){
		cin>>n>>x;f=1;
		for(i=0;i<n;i++){cin>>a[i];b[i]=a[i];}
	    sort(b,b+n);
	    for(i=n-x;i<x;i++){if(b[i]!=a[i]){f=0;}}
	    f?cout<<"YES"<<endl:cout<<"NO"<<endl;
	}
}