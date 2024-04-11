#include<stdio.h>
#include<string.h>
int hl,hr,n,z;
int w[120],l[120],r[120],p[120],v[120];
char c;
void F(int x,int y)
{
	double k=((x&1?100-hr:hr)-hl+x*(y?100:-100))*.00001;
	int c=0;
	memset(v,0,sizeof v);
	for(int i=y,j;i<x+y;i++)
	{
		double q=((y?100:-100)*i-hl)/k;
		for(j=0;j<n;j++)
			if(p[j]==i%2&&l[j]<=q&&q<=r[j])
			{
				if(v[j])
					return;
				v[j]=1;
				c+=w[j];
				break;
			}
		if(j==n)
			return;	
	}
	if(z<c)
		z=c;
}
int main()
{
	scanf("%d %d %d",&hl,&hr,&n);
	for(int i=0;i<n;i++)
		scanf("%d %c%d%d",w+i,&c,l+i,r+i),p[i]=c=='T';
	for(int i=0;i<=n;i++)
		F(i,1),F(i,0);
	printf("%d",z);
	return 0;
}