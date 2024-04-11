#include <iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int a[n],cnt=0,s=0;
	for(int x=0; x<n; x++){
		cin>>a[x];
		if(a[x]<a[x-1]&&x)cnt++,s=x;
	}
	if(!cnt)cout<<"0";
	else if(cnt==1 && a[0]>=a[n-1])cout<<n-s;
	else cout<<"-1";
}