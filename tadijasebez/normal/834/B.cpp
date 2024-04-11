#include <stdio.h>
#include <cstring>
char guests[1000050];
int FAI[26];
int LAI[26];
int main()
{
	int n,k,i;
	scanf("%i %i",&n,&k);
	scanf("%s",&guests);
	int guard=0;
	for(i=0;i<n;i++)
	{
		if(FAI[guests[i]-'A']==0)
			FAI[guests[i]-'A']=i+1;
		LAI[guests[i]-'A']=i+1;
	}
	for(i=0;i<n;i++)
	{
		if(FAI[guests[i]-'A']==i+1)
		{
			if(guard==k)
			{
				printf("YES\n");
				return 0;
			}
			guard++;
		}
		if(LAI[guests[i]-'A']==i+1)
		{
			guard--;
		}
	}
	printf("NO\n");
	return 0;
}