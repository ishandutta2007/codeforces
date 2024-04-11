#include <bits/stdc++.h>
using namespace std;
int n;
int a[101],ans[101];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)	cin>>a[i];
	sort(a,a+n);
	if(n%2==0){
		for(int i=0;i<n;i+=2)	cout<<a[i]<<" ";
		for(int i=n-1;i>=0;i-=2)	cout<<a[i]<<(i==0?"\n":" ");
	}
	else{
		for(int i=1;i<n;i+=2)	cout<<a[i]<<" ";
		for(int i=n-1;i>=0;i-=2)	cout<<a[i]<<(i==1?"\n":" ");
	}
}