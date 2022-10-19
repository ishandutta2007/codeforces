#include<bits/stdc++.h>
using namespace std;
char s[10];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1),x=s[1]-'1';
		printf("%d\n",10*x+n*(n+1)/2);
	}
	return 0;
}