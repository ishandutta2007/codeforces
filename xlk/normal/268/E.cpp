#include<stdio.h>
#include<algorithm>
#define X first
#define Y second
using namespace std;
typedef pair<int,int>ii;
ii a[100020];
double z,s;
int n,v;
bool cmp(const ii&a,const ii&b)
{
	return a.X*a.Y*(100-b.Y)>b.X*b.Y*(100-a.Y);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&a[i].X,&a[i].Y),v+=a[i].X;
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)
	{
		z+=s*(100-a[i].Y);
		s+=a[i].X*a[i].Y;
	}
	printf("%.9f",z/10000+v);
	return 0;
}