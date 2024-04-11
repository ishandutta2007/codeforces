#include<stdio.h>
#include<algorithm>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> ii;
ii a[100020];
int n,x,z[100020];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i].X),a[i].Y=i;
	sort(a,a+n);
	x=-1;
	for(int i=0;i<n;i++)
	{
		x=max(x,a[i].Y);
		z[a[i].Y]=x-a[i].Y;
	}
	for(int i=0;i<n;i++)
		printf("%d ",z[i]-1);
	return 0;
}