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
char s[100020];
char z[100020];
int zc;
int main()
{
	scanf("%s",s);
	for(int i=0;s[i];i++)
	{
		while(zc&&s[i]>z[zc])
			zc--;
		z[++zc]=s[i];
	}
	z[zc+1]=0;
	puts(z+1);
}