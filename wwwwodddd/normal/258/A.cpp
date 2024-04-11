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
int p,l;
char s[100020];
int main()
{
	scanf("%s",s);
	l=strlen(s);
	p=l-1;
	for(int i=0;i<l;i++)
	{
		if(s[i]=='0')
		{
			p=i;
			break;
		}
	}
	for(int i=0;i<l;i++)
		if(i!=p)
			printf("%c",s[i]);
}