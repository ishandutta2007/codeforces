#include<bits/stdc++.h>
using namespace std;
const int N=200005;
char s[N],t[N];
int las[N];
int main()
{
	scanf("%s%s",s+1,t+1);
	int n=strlen(s+1),m=strlen(t+1);
	int p=m,i=n;
	while(i)
	{
		if(s[i]==t[p])
		{
			las[p]=i;
			p--;
		}
		i--;
	}
	las[m+1]=n+1;
	p=1;
	int ans=las[1]-1;
	for(int i=1;i<=n;i++)
	{
		if(s[i]==t[p])
		{
			ans=max(ans,las[p+1]-i-1);
			p++;
		}
	}
	printf("%d\n",ans);
	return 0;
}