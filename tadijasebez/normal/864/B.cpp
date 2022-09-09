#include <stdio.h>
#include <cstring>
const int N=250;
int sol,ans;
bool DP[26];
int max(int a, int b){ return a>b?a:b;}
char word[N];
int main()
{
	int n,i,j;
	scanf("%i",&n);
	scanf("%s",&word);
	for(i=0;i<n;i++)
	{
		if(word[i]<'a')
		{
			ans=0;
			for(j=0;j<26;j++) DP[j]=false;
		}
		else
		{
			if(!DP[word[i]-'a'])
			{
				ans++;
				DP[word[i]-'a']=true;
			}
			sol=max(sol,ans);
		}
	}
	printf("%i\n",sol);
	return 0;
}