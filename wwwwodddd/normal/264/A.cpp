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
int n,a[1000020];
char s[1000020];
int main()
{
	scanf("%s",s);
	n=strlen(s);
	int l=0,r=n;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='l')
			a[--r]=i+1;
		else
			a[l++]=i+1;
	}
	for(int i=0;i<n;i++)
		printf("%d\n",a[i]);
}