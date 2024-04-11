#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int ans=0;
	while(isdigit(ch))
	{
		ans=ans*10+ch-48;
		ch=getchar();
	}
	return ans;
}
#define N 100005
int dgr[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int n;
	cin>>n;
	int u,v;
	for(int i=1;i<n;i++)
	{
		u=read(),v=read();
		dgr[u]++,dgr[v]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(dgr[i]==2)
		{
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	return 0;
}