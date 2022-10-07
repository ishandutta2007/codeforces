#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,q,a[100005],t;
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		t+=a[i];
	}
	while(q--)
	{
		int type,x;
		scanf("%d%d",&type,&x);
		if(type==1)
		{
			t-=a[x];
			a[x]=!a[x];
			t+=a[x];
		}
		else
		{
			if(t>=x)printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}