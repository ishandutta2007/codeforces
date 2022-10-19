#include<bits/stdc++.h>
using namespace std;
const int N=300005;
struct seg
{
	int l,r,id;	
	bool operator<(const seg k)const
	{
		return l==k.l?r>k.r:l<k.l;
	}
}a[N];
int n,p;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].l,&a[i].r);
		a[i].id=i;
	}
	sort(a+1,a+n+1);
	p=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i].r<=a[p].r)
		{
			printf("%d %d\n",a[i].id,a[p].id);
			return 0;
		}
		if(a[i].r>a[p].r)
			p=i;
	}
	puts("-1 -1");
	return 0;
}