#include <stdio.h>

int main()
{
	int n,i,j;
	char a[771],b[56]={0};
	scanf("%d%s",&n,a);
	for(i=0,j=0;j<n;i++,j+=i)
    {
        b[i]=a[j];
    }
    printf("%s",b);
	return 0;
}