#include<bits/stdc++.h>
using namespace std;
char a[100005];
int sum[30];
int main()
{
	int m;
	cin>>m;
	scanf("\n%s",a);
	if(m==1)
	{
		cout<<"Yes\n";
		return 0;
	}
	for(int i=0;i<m;i++)
	{
		sum[a[i]-'a']++;
	}
	for(int i=0;i<26;i++)
	{
		if(sum[i]>=2)
		{
			cout<<"Yes\n";
			return 0;
		}
	}
	cout<<"No\n";
	return 0;
}