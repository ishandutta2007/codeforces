#include<bits/stdc++.h>
using namespace std;
int s[30];
int main()
{
	string a;
	int n,m;
	cin>>n>>m>>a;
	for(int i=0;i<n;i++)
	{
		s[a[i]-'A']++;
	}
	int minn=n;
	for(int i=0;i<m;i++)
	{
		if(s[i]<minn)
		{
			minn=s[i];
		}
	}
	cout<<minn*m<<endl;
	return 0;
}