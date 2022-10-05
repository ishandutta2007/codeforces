#include <bits/stdc++.h>
using namespace std;
int n;
bool did,vis[105];
long long a[105];
queue <long long> fro;
stack <long long> bac;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	long long now=a[1];
	vis[1]=true;
	did=true;
		while(did==true)
		{
			did=false;
			for(int j=1;j<=n;j++)
			{	
				if(a[j]==now*2&&!vis[j])
				{
					vis[j]=true;
					fro.push(a[j]);
					did=true;
					now*=2;
				}
					if(a[j]==now/3.0&&!vis[j])
				{
					vis[j]=true;
					fro.push(a[j]);
					did=true;
					now/=3;
				}
			}
		}
		did=true;
		now=a[1];
		while(did==true)
		{
			did=false;
			for(int j=1;j<=n;j++)
			{	
				if(a[j]==now/2.0&&!vis[j])
				{
					vis[j]=true;
					bac.push(a[j]);
					did=true;
					now/=2;
				}
				if(a[j]==now*3&&!vis[j])
				{
					vis[j]=true;
					bac.push(a[j]);
					did=true;
					now*=3;
				}
			}
		}
		while(!bac.empty()) printf("%I64d ",bac.top()),bac.pop();
		printf("%I64d ",a[1]);
		while(!fro.empty()) printf("%I64d ",fro.front()),fro.pop();
		return 0;
	}