#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int mx=100+5;
char s[mx];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1)-1;
	if(n%2==1) printf("%d",(n+1)/2);
	else
	{
		int ans=0;
		for(int i=2;i<=n+1;i++)
			if(s[i]=='1')
			{
				ans=1;
				break;
			}
		printf("%d",n/2+ans);
	}
	return 0;
}