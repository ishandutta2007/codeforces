#include<stdio.h>
#define fo(i,n) for(int i=1;i<=n;i++)
int n,m,c,f[1020],g[1020];
char s[1020];
double z;
int F(int*c,int n,int m)
{
	int s=0;
	fo(i,n)
		if(c[i])
		{
			s+=c[i]-1;
			z+=s*(m-c[i]);
			if(!c[i+1]||c[i+1]<c[i])
				s=0;
		}
	s=0;
	fo(i,n)
		if(c[i])
		{
			z+=s*(c[i]-1);
			s+=m-c[i];
			if(!c[i+1]||c[i+1]>c[i])
				s=0;
		}
}
int main()
{
	scanf("%d%d",&n,&m);
	fo(i,n)
	{
		scanf("%s",s+1);
		fo(j,m)
			if(s[j]=='X')
				f[i]=j,g[j]=i,c++;
	}
	F(f,n,m);
	F(g,m,n);
	z*=2;
	fo(i,n)
		fo(j,i)
			z+=(m-!!f[i])*(m-!!f[j])*(i-j);
	fo(i,m)
		fo(j,i)
			z+=(n-!!g[i])*(n-!!g[j])*(i-j);		
	z*=2;
	z/=n*m-c,z/=n*m-c;
	printf("%.15f",z);
	return 0;
}