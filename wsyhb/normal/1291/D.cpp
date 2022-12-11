#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
char s[N];
int a[N][30],now[30];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1),q;
	for(int i=1;i<=n;i++)
	{ 
		for(int j=0;j<26;j++) a[i][j]=a[i-1][j];
		a[i][s[i]-'a']++;
	}
	scanf("%d",&q);
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(l==r)
		{
			printf("Yes\n");
			continue;
		}
		int cnt=0;
		for(int i=0;i<26;i++)
		{
			now[i]=a[r][i]-a[l-1][i];
			if(now[i]) cnt++;
		}
		if(cnt>2) printf("Yes\n");
		else if(cnt==1) printf("No\n");
		else
		{
			if(s[l]==s[r]) printf("No\n");
			else printf("Yes\n");
		}
	}
	return 0;
}