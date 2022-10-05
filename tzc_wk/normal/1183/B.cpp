#include <bits/stdc++.h>
using namespace std;
int q;
int n,k,a[101];
int main(){
	cin>>q;
	while(q--){
		cin>>n>>k;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)	cin>>a[i];
		sort(a+1,a+1+n);
		if(a[n]-a[1]>2*k)	puts("-1");
		else				cout<<a[1]+k<<endl;
	}
	return 0;
}