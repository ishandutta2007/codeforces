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
int a[N];
bool prim[N];
int main()
{
	int n;
	cin>>n;
	int ans=0;
	for(int i=2;i<=n;i++)
	{
		if(prim[i]==false)
		{
			a[i]=++ans;
			for(int j=1;i*j<=n;j++)
			{
				a[i*j]=a[i];
				prim[i*j]=true;
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}