#include<bits/stdc++.h>
using namespace std;
const int max_n=1e4+5;
int ans[max_n];
queue<int> q;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) q.push(i);
	while(q.size()>1)
	{
		int x=q.front();
		q.pop();
		int y=q.front();
		q.pop();
		printf("? %d %d\n",x,y);
		fflush(stdout);
		int a;
		scanf("%d",&a);
		printf("? %d %d\n",y,x);
		fflush(stdout);
		int b;
		scanf("%d",&b);
		if(a>b)
		{
			ans[x]=a;
			q.push(y);
		}
		else
		{
			ans[y]=b;
			q.push(x);
		}
	}
	int x=q.front();
	ans[x]=n*(n+1)>>1;
	for(int i=1;i<=n;++i)
		if(i!=x) ans[x]-=ans[i];
	printf("! ");
	for(int i=1;i<=n;++i)
		printf("%d%c",ans[i],i<n?' ':'\n');
	fflush(stdout);
	return 0;
}