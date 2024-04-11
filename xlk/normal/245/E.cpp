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
char s[509]; 
int mn,mx,c;
int main()
{
    scanf("%s",s);
	for(int i=0;s[i];i++)
	{
		if(s[i]=='+')
			c++;
		else
			c--;
		mn=min(mn,c);
		mx=max(mx,c);
    }
	printf("%d",mx-mn);
}