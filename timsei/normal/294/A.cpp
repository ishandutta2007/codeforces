#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
ll a[101];
int m,x,y,n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		a[x-1]+=y-1;
		a[x+1]+=(a[x]-y);
		a[x]=0;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<endl;
	}
}