#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,m,k,d,b,l[N],c[N],p[N],x[N],t[N];
char s[N];
int main()
{
	scanf("%s%d",s,&m);
	n=strlen(s);
	for(int i=0;i<n;i++)
		l[i]=(n+i-1)%n;
	while(m--)
	{
		scanf("%d%d",&k,&d);
		for(int i=0;i<n;i++)
			c[i]=i;
		int r=0;
		for(int i=0;i<d;i++)
			for(int j=i;j<k;j+=d)
				c[j]=r++;
		for(int i=0;i<n;i++)
			p[i]=c[i];
		for(int i=0;i<n;i++)
			x[i]=c[l[i]];
		b=n-k;
		while(b)
		{
			if(b&1)
			{
				for(int i=0;i<n;i++)
					p[i]=x[p[i]];
			}
			for(int i=0;i<n;i++)
				t[i]=x[x[i]];
			for(int i=0;i<n;i++)
				x[i]=t[i];
			b>>=1;
		}
		for(int i=0;i<n;i++)
			t[p[i]]=s[i];
		for(int i=0;i<n;i++)
			s[(i+n-k)%n]=t[i];
		printf("%s\n",s);
	}
	return 0;
}