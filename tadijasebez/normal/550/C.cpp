#include <stdio.h>
#include <cstring>
const int N=105;
char word[N];
int a[N];
int sol=-1;
int main()
{
	int n,i,j,k;
	scanf("%s",&word);
	n=(unsigned) strlen(word);
	for(i=0;i<n;i++) a[i]=word[i]-'0';
	for(i=0;i<n;i++)
	{
		if(a[i]%8==0) sol=a[i];
		for(j=i+1;j<n;j++)
		{
			if((a[i]*10+a[j])%8==0) sol=a[i]*10+a[j];
			for(k=j+1;k<n;k++)
			{
				if((a[i]*100+a[j]*10+a[k])%8==0) sol=a[i]*100+a[j]*10+a[k];
			}
		}
	}
	if(sol>-1) printf("YES\n%i\n",sol);
	else printf("NO\n");
	return 0;
}