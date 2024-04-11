#include<bits/stdc++.h>
using namespace std;
const int max_n=100+5;
struct Node
{
	int a,b;
}p[max_n];
inline bool operator < (const Node &c,const Node &d)
{
	return c.a<d.a;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i)	
			scanf("%d",&p[i].a);
		for(int i=1;i<=n;++i)	
			scanf("%d",&p[i].b);
		sort(p+1,p+n+1);
		for(int i=1;i<=n;++i)
		{
			if(k>=p[i].a)
				k+=p[i].b;
			else
				break;
		}
		printf("%d\n",k);
	}
	return 0;
}