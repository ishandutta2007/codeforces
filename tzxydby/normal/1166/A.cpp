#include<bits/stdc++.h>
using namespace std;
int a[30];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		a[s[0]-'a']++;
	}
	int ans=0;
	for(int i=0;i<26;i++)
	{
		if(a[i]<=2)
			continue;
		int x=a[i]/2,y=a[i]-x;
		ans+=x*(x-1)/2+y*(y-1)/2;
	}
	cout<<ans<<endl;
	return 0;
}