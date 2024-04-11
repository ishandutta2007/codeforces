#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char s[1000020],o[120];
int z[10020],c[10020],q[10020];
int l,m,n;
int &A(int x)
{
	int p=lower_bound(c,c+l,x)-c;
	return c[p]==x?z[p]:z[l];
}
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++)
		s[i]-='a';
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int v=0;
		scanf("%s",o);
		for(int j=0;o[j];j++)
			v|=1<<o[j]-'a';
		c[i]=q[i]=v;
	}
	sort(c,c+m);
	l=unique(c,c+m)-c;
	for(int i=0;i<n;i++)
	{
		int p=i?s[i-1]:-1;
		int v=0;
		for(int j=i;j<=n;j++)
		{
			if(j<n&&v>>s[j]&1)
				continue;
			A(v)++;
			if(s[j]==p)
				break;
			v|=1<<s[j];
		}
	}
	for(int i=0;i<m;i++)
		printf("%d\n",A(q[i]));
	return 0;
}