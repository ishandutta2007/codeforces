#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Node
{
	int x,y;
}a[10];
bool cmp(Node a,Node b)
{
	return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
int main()
{
	for(int i=1;i<=8;i++)
	  scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+9,cmp);
	if (a[1].x==a[2].x&&a[2].x==a[3].x&&a[3].x!=a[4].x&&a[4].x==a[5].x&&a[5].x!=a[6].x&&a[6].x==a[7].x&&a[7].x==a[8].x&&
		a[1].y==a[4].y&&a[4].y==a[6].y&&a[6].y!=a[2].y&&a[2].y==a[7].y&&a[7].y!=a[3].y&&a[3].y==a[5].y&&a[5].y==a[8].y)
		printf("respectable\n");
	else printf("ugly\n");
	return 0;
}