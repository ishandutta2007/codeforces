#include <stdio.h>
#include <cstring>
const int N=1000500;
int S[N],L[N],t,sol,cnt=1;
char x[N];
int main()
{
	scanf("%s",&x);
	int n=strlen(x);
	for(int i=0;i<n;i++)
	{
		if(x[i]=='(') S[++t]=i;
		else if(t)
		{
			L[i]=i-S[t]+1+L[S[t--]-1];
			if(L[i]==sol) cnt++;
			if(L[i]>sol) sol=L[i],cnt=1;
		}
	}
	printf("%i %i\n",sol,cnt);
}