#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int a[n],b[n];
	for(int i=0;i<n;i++)cin>>a[i];
	int s1=0,s2=0;
	for(int i=n-1;i>=0;i--){
		if(i%2==1)b[i]=a[i]+s2-s1,s1+=b[i];
		else b[i]=a[i]+s1-s2,s2+=b[i];
	}
	for(int i=0;i<n;i++)cout<<b[i]<<" ";
	return 0;	
}