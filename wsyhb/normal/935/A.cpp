#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,ans=0,i;
	cin>>n;
	for(i=1;i<n;i++)
		if(n%i==0) ans++;
	cout<<ans;
	return 0;
}