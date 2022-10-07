#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,d[200005],num;
double s;
int main()
{
	scanf("%d%lf",&n,&s);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		d[u]++,d[v]++;
	}
	for(int i=1;i<=n;i++)
	  if(d[i]==1)num++;
	printf("%lf\n",s/num*2);
	return 0;
}