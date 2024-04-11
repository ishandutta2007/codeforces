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
int n,k,z;
char s[500020];
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	if(k==2)
	{
		for(int i=0;i<n;i++)
			if(s[i]+i%2!='B')
				z++;
		if(z<n-z)
		{
			printf("%d\n",z);
			for(int i=1;i<=n;i++)
				printf("%c",'A'+i%2);
		}
		else
		{
			printf("%d\n",n-z);
			for(int i=0;i<n;i++)
				printf("%c",'A'+i%2);
		}
	}
	else
	{
		for(int i=0;i<n;i++)
			if(s[i]==s[i+1])
			{
				z++;
				s[i+1]='A';
				while(s[i+1]==s[i]||s[i+1]==s[i+2])
					s[i+1]++;
			}
		printf("%d\n",z);
		printf("%s\n",s);
	}
	return 0;
}