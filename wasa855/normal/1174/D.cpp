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
int a[1<<19];
bool used[1<<19];
int main()
{
	int n,x;
	cin>>n>>x;
	used[0]=used[x]=true;
	int lim=1<<n;
	int res=0;
	for(int i=1;i<lim;i++)
	{
		if(!used[i]&&!used[i^x])
		{
			a[++res]=i;
//			cout<<i<<endl;
			used[i]=used[i^x]=true;
		}
	}
	for(int i=res;i>=2;i--)
	{
		a[i]^=a[i-1];
	}
	cout<<res<<endl;
	for(int i=1;i<=res;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}