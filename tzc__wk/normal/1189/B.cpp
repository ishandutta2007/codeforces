#include <bits/stdc++.h>
using namespace std;
int n,a[100001];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+1+n);
	if(a[n]>=a[n-1]+a[n-2])	return puts("NO"),0;
	puts("YES");
	for(int i=1;i<n-1;i++)	cout<<a[i]<<" ";
	cout<<a[n]<<" "<<a[n-1]<<endl;
	return 0;
}