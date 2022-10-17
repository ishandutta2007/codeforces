#include<stdio.h>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
int n,w,s,y=-1,a[120],p[120];
int main()
{
	scanf("%d%d",&n,&w);
	fr(i,n)
		scanf("%d",a+i),s+=a[i],a[i]==1&&(y=i);
	if(w<1||w>s||n==1&&w!=s||w==1&&y==-1)
		return puts("No"),0;
	puts("Yes");
	if(n==1)
		fr(i,2*a[0])
			printf("%d ",1);
	else if(w==1)
	{
		a[y]--;
		printf("%d ",y+1);
		fr(i,n)
			fr(j,2*a[i])
				printf("%d ",i+1);
		printf("%d",y+1);
	}
	else
	{
		w-=2,a[0]--,a[1]--;
		fr(i,n)
			for(;w&&a[i];p[i]++)
				w--,a[i]--;
		printf("1 ");
		fo(i,n-1)
			fr(j,2*a[i])
				printf("%d ",i+1);
		printf("1 2 ");
		fr(i,2*a[0])
			printf("%d ",1);
		printf("2 ");
		fr(i,n)
			fr(j,2*p[i])
				printf("%d ",i+1);
	}
	return 0;
}