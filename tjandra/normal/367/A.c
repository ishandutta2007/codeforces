#include<stdio.h>
typedef unsigned u;
u x[100005],y[100005],z[100005];
int main()
{
	u m,i,j,k,S,s,l,r;
	char c;
	while((c=getchar())<'x');
	for(m=1;c>='x';c=getchar(),m++)
	{
		x[m]=x[m-1]+(c=='x');
		y[m]=y[m-1]+(c=='y');
		z[m]=z[m-1]+(c=='z');
	}
	for(scanf("%u",&m);m--;)
	{
		scanf("%u%u",&l,&r);l--;
		if(r-l<3){printf("YES\n");continue;}
		i=x[r]-x[l];
		j=y[r]-y[l];
		k=z[r]-z[l];
		S=0;
		s=(i>j)?(i-j):(j-i);
		if(S<s)S=s;
		s=(i>k)?(i-k):(k-i);
		if(S<s)S=s;
		s=(k>j)?(k-j):(j-k);
		if(S<s)S=s;
		printf((S>1)?"NO\n":"YES\n");
	}
	return 0;
}