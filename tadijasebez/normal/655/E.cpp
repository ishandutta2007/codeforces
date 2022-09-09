#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=1000050;
const int mod=1e9+7;
int cnt[26],lai[26],id[26];
bool comp(int i, int j){ return lai[i]<lai[j];}
char s[N];
int main()
{
	int n,m,k,i,j;
	scanf("%i %i",&n,&k);
	scanf("%s",s+1);
	m=strlen(s+1);
	for(i=1;i<=m;i++)
	{
		int x=1;
		for(j=0;j<k;j++)
		{
			x+=cnt[j];
			if(x>=mod) x-=mod;
		}
		cnt[s[i]-'a']=x;
		lai[s[i]-'a']=i;
	}
	for(i=0;i<k;i++) id[i]=i;
	sort(id,id+k,comp);
	i=0;
	while(n--)
	{
		int x=1;
		for(j=0;j<k;j++)
		{
			x+=cnt[j];
			if(x>=mod) x-=mod;
		}
		cnt[id[i]]=x;
		i++;
		if(i==k) i=0;
	}
	int sol=1;
	for(i=0;i<k;i++)
	{
		sol+=cnt[i];
		if(sol>=mod) sol-=mod;
	}
	printf("%i\n",sol);
	return 0;
}