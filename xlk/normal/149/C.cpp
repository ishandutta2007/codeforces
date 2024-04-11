#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int i,n,a[100020],b[100020];
bool cmp(int x,int y){return a[x]<a[y];}
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",a+i),b[i]=i;
	sort(b,b+n,cmp);
	printf("%d\n",(n+1)/2);
	for(i=0;i<n;i+=2)
		printf("%d ",b[i]+1);
	printf("\n%d\n", n/2);
	for(i=1;i<n;i+=2)
		printf("%d ",b[i]+1);
	return 0;
}