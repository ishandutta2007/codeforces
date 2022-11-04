#include<cstdio>
#include<iostream>
using namespace std;

int n,m;
double f[1010][1010],c[1010];

int main()
{int i,j,k,x,y;
 double t;
 
 scanf("%d%d",&n,&m);
 scanf("%d%d",&x,&y);
 n=n-x+1;
 
 for(i=1;i<=m;i++)
 	f[n][i]=0;

 if(m==1)
 {	printf("%.10lf\n",(double)(n-1)*2);
 	return 0;
 }

 for(i=n-1;i>=1;i--)
 {	for(j=1;j<=m;j++)
 		c[j]=0;
	for(k=1;k<=80;k++)
		for(j=1;j<=m;j++)
		{	if(j==1)
				f[i][j]=(f[i][j+1]+f[i+1][1]+3)/2;
			else if(j==m)			 	
				f[i][j]=(f[i][j-1]+f[i+1][1]+3)/2;
			else
				f[i][j]=(f[i][j-1]+f[i][j+1]+f[i+1][j]+4)/3;	
		}
 }
 		 	
 printf("%.10lf\n",(double)f[1][y]);
 
 return 0;
}