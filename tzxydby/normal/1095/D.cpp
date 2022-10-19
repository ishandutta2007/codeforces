#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],b[N],vis[N];
int main()
{
	int n,last=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&b[i]);
	printf("1 ");
	for(int i=2;i<=n;i++)
	{
		vis[last]=1;
		int x=a[last],y=b[last];
		if((a[x]==y||b[x]==y)&&!vis[x])
		{
			printf("%d ",x);
			last=x;
		}
		else
		{
			printf("%d ",y);
			last=y; 
		}
	}
	puts("");
	return 0;
}