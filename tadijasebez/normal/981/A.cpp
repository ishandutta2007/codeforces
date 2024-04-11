#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
const int N=100;
char s[N];
bool Check(int l, int r)
{
	for(int i=1;i<=r-l+1;i++)
	{
		if(s[l+i-1]!=s[r-i+1]) return false;
	}
	return true;
}
int main()
{
	int n,i,j,sol=0;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i+1;j++)
		{
			if(!Check(j,j+i-1))
			{
				//printf("%i %i\n",j,j+i-1);
				sol=i;
			}
		}
	}
	printf("%i\n",sol);
	return 0;
}