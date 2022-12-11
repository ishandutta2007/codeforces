#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int n,m,q;
char a[maxn],b[maxn];
int s[maxn];
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	scanf("%s",a+1);
	scanf("%s",b+1);
	for(int i=1;i<=n-m+1;++i)
	{
		int yes=1;
		for(int j=1;j<=m;++j)if(a[i+j-1]!=b[j])yes=0;
		if(yes)s[i]++;
	}
	for(int i=1;i<=n;++i)s[i]+=s[i-1];
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(r-m+1<l)puts("0");
		else printf("%d\n",s[r-m+1]-s[l-1]);
	}
	return 0;
}