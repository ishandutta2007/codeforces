#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<set>
#include<algorithm>

using namespace std;

const long long mod=1000000007;

int main()
{
	int n,m;
	string names[110];
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		cin>>names[i];
	}
	int times[110];
	memset(times,0,sizeof(times));
	for(int i=0;i<m;i++)
	{
		set<char> all;
		for(int j=0;j<n;j++)
		{
			all.insert(names[j][i]);
		}
		times[i]=all.size();
	}
	long long ans=1;
	for(int i=0;i<m;i++)
	{
		ans*=times[i];
		ans%=mod;
	}
	cout<<ans;
	return 0;
}