#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[3002]={0};
	for(int i=0;i<n;i++) {int t; cin>>t;a[t]=1;}
	for(int i=1;i<=3001;i++) if(a[i]==0){cout<<i; return 0;}	

}