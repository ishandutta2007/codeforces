#include <bits/stdc++.h>
using namespace std;
int n,x,num[100005],vis[100005];
int main()
{
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		vis[num[i]]++;
	}
	for(int i=0;i<=100000;i++)
		if(vis[i]>1){printf("0");return 0;}
	for(int i=1;i<=n;i++)
	{
		if(vis[num[i]&x]&&num[i]!=(num[i]&x)){printf("1");return 0;}
		if(vis[num[i]&x]>=2&&num[i]==(num[i]&x)){printf("1");return 0;}
	}
	for(int i=1;i<=n;i++)
	{
		if((num[i]&x)!=num[i])
			vis[num[i]&x]++;
	}
	for(int i=0;i<=100000;i++)
		if(vis[i]>=2){printf("2");return 0;}
	printf("-1");
	return 0;
}