#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define SZ 5010
#define SZZ 25000100
char s[SZ+1]; int n,k;
bool good[SZ][SZ];
int ch[SZZ][2],val[SZZ],sum[SZZ],M=1;
int alc(int& x)
{
	if(!x) x=++M;
	return x;
}
int main()
{
	scanf("%s%d",s+1,&k);
	n=strlen(s+1);
	for(int l=1;l<=n;l++)
	{
		for(int i=1;i+l-1<=n;i++)
		{
			int j=i+l-1;
			if(s[i]!=s[j]) continue;
			if(i+2<=j-2&&!good[i+2][j-2]) continue;
			good[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int cur=1;
		for(int j=i;j<=n;j++)
		{
			cur=alc(ch[cur][s[j]-'a']);
			val[cur]+=good[i][j];
		}
	}
	for(int i=M;i>=1;i--) sum[i]=sum[ch[i][0]]+sum[ch[i][1]]+val[i];
	int cur=1; string s;
	while(k>val[cur])
	{
		k-=val[cur];
		if(sum[ch[cur][0]]>=k) cur=ch[cur][0], s+="a";
		else k-=sum[ch[cur][0]], cur=ch[cur][1], s+="b";
	}
	puts(s.c_str());
}