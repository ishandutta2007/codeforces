#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int N=3e3+5;
char s[N],a[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,cnt=0;
		scanf("%d%s",&n,s+1);
		for(int i=1;i<=n;i++)
			if((s[i]-'0')&1) a[++cnt]=s[i];
		if(cnt<2) printf("-1\n");
		else printf("%c%c\n",a[1],a[2]);
	}
	return 0;
}