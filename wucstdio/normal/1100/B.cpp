#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[100005],num[100005],rest;
int main()
{
	scanf("%d%d",&m,&n);
	rest=m;
	while(n--)
	{
		int v;
		scanf("%d",&v);
		if(num[v]==0)rest--;
		num[v]++;
		if(rest==0)
		{
			for(int i=1;i<=m;i++)
			{
				num[i]--;
				if(num[i]==0)rest++;
			}
			printf("1");
		}
		else printf("0");
	}
	return 0;
}