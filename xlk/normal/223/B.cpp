#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
char s[200020];
char c[200020];
int ls,lc;
int I[200020];
int D[200020];
int w[300];
int p;
int main()
{
	scanf("%s",s);
	scanf("%s",c);
	ls=strlen(s);
	lc=strlen(c);
	for(int i=0;i<ls&&p<lc;i++)
	{
		if(s[i]==c[p])
		{
			I[i]++;
			p++;
		}
	}
	if(p<lc)
	{
		puts("No");
		return 0;
	}
	p=lc-1;
	for(int i=ls-1;i>=0&&p>=0;i--)
	{
		if(s[i]==c[p])
		{
			D[i]--;
			p--;
		}
	}
	for(int i=0;i<ls;i++)
	{
		w[s[i]]+=I[i];
		if(w[s[i]]==0)
		{
			puts("No");
			return 0;
		}
		w[s[i]]+=D[i];
	}
	puts("Yes");
	return 0;
}