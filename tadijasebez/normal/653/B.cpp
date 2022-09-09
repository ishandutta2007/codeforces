#include <stdio.h>
const int N=40;
int a[N],b[N],c[N];
int s[10],t[10],sol;
bool Try(int n, int q)
{
	int i,j;
	//for(i=1;i<=n;i++) printf("%c",'a'+s[i]);
	//printf("\n");
	for(i=1;i<=n;i++) t[i]=s[i];
	for(i=1;i<n;i++)
	{
		bool done=0;
		for(j=1;j<=q;j++)
		{
			if(a[j]==t[i] && b[j]==t[i+1])
			{
				t[i+1]=c[j];
				done=1;
				break;
			}
		}
		if(!done) return 0;
	}
	if(t[n]!=0) return 0;
	return 1;
}
int main()
{
	int n,q,i,j;
	scanf("%i %i",&n,&q);
	for(i=1;i<=q;i++) scanf("\n%c%c %c",&a[i],&b[i],&c[i]),a[i]-='a',b[i]-='a',c[i]-='a';
	int po=1;for(i=1;i<=n;i++) po*=6;
	for(i=0;i<po;i++)
	{
		sol+=Try(n,q);
		s[1]++;
		for(j=1;j<=n;j++) if(s[j]==6) s[j+1]++,s[j]=0;
	}
	printf("%i\n",sol);
	return 0;
}