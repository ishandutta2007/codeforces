#include <stdio.h>
int cnt[10],a[10];
int main()
{
	int n,i,j=1,k,l;
	scanf("%i",&n);
	for(i=1;i<=9;i++)
	{
		scanf("%i",&a[i]);
		if(a[i]<=a[j]) j=i;
	}
	cnt[j]=n/a[j];
	n%=a[j];
	if(!cnt[j]) return printf("-1\n"),0;
	for(l=cnt[j];l;l--)
	{
		n+=a[j];
		cnt[j]--;
		k=j;
		for(i=1;i<=9;i++) if(a[i]<=n) k=i;
		cnt[k]++;
		n-=a[k];
	}
	for(i=9;i;i--) for(j=0;j<cnt[i];j++) printf("%i",i);
	printf("\n");
}