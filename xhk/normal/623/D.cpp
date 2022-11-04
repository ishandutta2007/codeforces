#include<bits/stdc++.h>
using namespace std;

int n;
double ans;
double c[400010],a[110],b[110];

int main()
{int i,j,k,x;
 
 scanf("%d",&n);
 c[n]=1;
 for(i=1;i<=n;i++)
 {	scanf("%d",&x);
 	a[i]=x/100.0;
 	b[i]=1-a[i];
 	c[n]*=a[i];
 }
 ans=c[n]*n;
 for(i=n+1;i<=400000;i++)
 {	j=1;
 	for(k=2;k<=n;k++)
 		if((1-b[k]*(1-a[k]))*(1-b[j])>(1-b[j]*(1-a[j]))*(1-b[k]))
 			j=k;
 	b[j]=b[j]*(1-a[j]);
 	c[i]=1;
	for(j=1;j<=n;j++) c[i]=c[i]*(1-b[j]);		
	ans+=i*(c[i]-c[i-1]);
 }
 printf("%.10lf\n",ans);
 return 0;
}