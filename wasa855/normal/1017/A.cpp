#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int id;
	int a,b,c,d;
};
Node a[1005];
bool cmp(Node a,Node b)
{
	if(a.a+a.b+a.c+a.d!=b.a+b.b+b.c+b.d)
	{
		return a.a+a.b+a.c+a.d>b.a+b.b+b.c+b.d;
	}
	return a.id<b.id;
}
int main()
{
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		a[i].id=i;
		scanf("%d %d %d %d",&a[i].a,&a[i].b,&a[i].c,&a[i].d);
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(a[i].id==1)
		{
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}