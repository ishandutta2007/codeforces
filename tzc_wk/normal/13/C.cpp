#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
const int maxn=5000+50;
long long n,a[maxn],s[maxn],m[maxn];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		s[i]=a[i];
	}
	m[0]=1e14;
	sort(s,s+n);
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			m[j]=min(m[j-1],m[j]+abs(a[i]-s[j]));
		}
	}
	if(n==1)
	{
		cout<<0<<endl;
		return 0;
	}
	cout<<m[n-1]<<endl;
	return 0;
}