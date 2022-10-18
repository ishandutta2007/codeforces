#include<bits/stdc++.h>
using namespace std;
struct node
{
	int width;
	int num;
};
node a[200005];
stack<int> b;
bool cmp(node a,node b)
{
	return a.width<b.width;
}
int main()
{
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a[i].width);
		a[i].num=i;
	}
	sort(a+1,a+m+1,cmp);
	int t;
	int now=1;
//	for(int i=1;i<=m;i++)
//	{
//		printf("%d %d\n",a[i].width,a[i].num);
//	}
	for(int i=1;i<=2*m;i++)
	{
		scanf("%1d",&t);
		if(t==0)
		{
			b.push(now);
			printf("%d ",a[now].num);
			now++;
		}
		else
		{
			printf("%d ",a[b.top()].num);
			b.pop();
		}
	}
	cout<<"\n";
	return 0;
}