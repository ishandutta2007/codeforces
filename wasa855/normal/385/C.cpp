#include<bits/stdc++.h>
using namespace std;
#define N 10000000
int prim[10000005];
bool mark[10000005];
int a[1000005];
int cnt=0;
int sum[10000005];
int res[10000005];
void init()
{
	for(int i=2;i<=N;i++)
	{
		if(mark[i]==false)
		{
			prim[++cnt]=i;
		}
		for(int j=1;j<=cnt;j++)
		{
			if(i*prim[j]>N)
			{
				break;
			}
			mark[i*prim[j]]=true;
			if(i%prim[j]==0)
			{
				break;
			}
		}
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[a[i]]++;
	}
	init();
	for(int i=1;i<=cnt;i++)
	{
		for(int j=1;prim[i]*j<=N;j++)
		{
			res[prim[i]]+=sum[prim[i]*j];
		}
	}
	for(int i=1;i<=N;i++)
	{
		res[i]+=res[i-1];
	}
	int m;
	cin>>m;
	int l,r;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&l,&r);
		if(l>=N)
		{
			printf("0\n");
			continue;
		}
		if(r>=N)
		{
			r=N;
		}
		printf("%d\n",res[r]-res[l-1]);
	}
	return 0;
}