#include <stdio.h>
#include <cstring>
const int N=5050;
char word[N];
int dp[N],dd[N];
int sol=10000000;
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int i,j,n,x,y;
	scanf("%s",&word);
	n=(unsigned) strlen(word);
	for(i=1;i<=n;i++) dp[i]=dp[i-1]+(word[i-1]=='a');
	for(i=1;i<=n;i++) dd[i]=dd[i-1]+(word[i-1]=='b');
	int tr;
	for(i=0;i<=n;i++)
	{
		for(j=n;j>0;j--)
		{
			if(i>j) break;
			tr=dd[n];
			if(j>0) tr-=dd[j];
			tr+=dp[j]-dp[i];
			tr+=dd[i];
			sol=min(sol,tr);
		}
	}
	printf("%i\n",n-sol);
	return 0;
}