#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int a[max_n];
bool vis[max_n];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n-1;++i)
		scanf("%d",a+i);
	printf("%d\n",a[1]);
	int cur=n;
	for(int i=1;i<=n-1;++i)
	{
		vis[a[i]]=true;
		if(i==n-1||vis[a[i+1]])
		{
			while(vis[cur])
				--cur;
			vis[cur]=true;
			printf("%d %d\n",a[i],cur);
		}
		else
			printf("%d %d\n",a[i],a[i+1]);
	}
	return 0;
}