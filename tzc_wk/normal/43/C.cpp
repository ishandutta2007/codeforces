#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,a[3]={0};
	cin>>n;
	for(int i=0;i<n;i++)
	{
	    cin>>x;
	    a[x%3]++;
	}
	int ans=a[0]/2+min(a[1],a[2]);
	cout<<ans;
}