#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int a[max_n],id[max_n];
inline bool cmp(int x,int y)
{
	return a[x]<a[y];
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
			id[i]=i;
		}
		sort(id+1,id+n+1,cmp);
		printf("%d %d\n",id[1],id[n]);
	}
	return 0;
}