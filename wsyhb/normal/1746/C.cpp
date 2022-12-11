#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int a[max_n],d[max_n],id[max_n];
inline bool cmp(int x,int y)
{
	return d[x]>d[y];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			d[i]=a[i]-a[i-1];
			id[i]=i;
		}
		sort(id+1,id+n+1,cmp);
		for(int i=1;i<=n;++i)
		{
			assert(d[id[i]]+i>=0);
			printf("%d%c",id[i]," \n"[i==n]);
		}
	}
	return 0;
}