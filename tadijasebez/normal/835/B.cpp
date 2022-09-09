#include <stdio.h>
#include <cstring>
int cifre[100050];
char broj[100050];
int count[10];
int main()
{
	int k,i,n;
	scanf("%i",&k);
	scanf("%s",&broj);
	n=(unsigned) strlen(broj);
	int sum=0;
	for(i=0;i<n;i++)
	{
		cifre[i]=broj[i]-'0';
		sum+=cifre[i];
		count[cifre[i]]++;
	}
	int tr=0,sol=0;
	while(sum<k)
	{
		while(count[tr]==0)
		{
			tr++;
		}
		sum+=9-tr;
		count[tr]--;
		sol++;
	}
	printf("%i\n",sol);
	return 0;
}