#include<bits/stdc++.h>
using namespace std;
int a[150];
int main()
{
	int n;
	cin>>n;
	string x;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		a[x[0]]++;
	}
	int ans=0;
	for(int i='a';i<='z';i++)
	{
		int u=a[i]/2;
		int v=a[i]/2+a[i]%2;
		ans=ans+u*(u-1)/2+v*(v-1)/2;
	}
	cout<<ans<<endl;
	return 0;
}