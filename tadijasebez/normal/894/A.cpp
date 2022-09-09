#include <stdio.h>
#include <cstring>
char ch[10000];
int main()
{
	scanf("%s",&ch);
	int i,j,k,n,sol=0;
	n=strlen(ch);
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			for(k=j+1;k<n;k++)
				if(ch[i]=='Q' && ch[j]=='A' && ch[k]=='Q') sol++;
	printf("%i\n",sol);
	return 0;
}