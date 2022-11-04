#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m,p;
char a[1000010];

int main()
{int i,j,k;
 
 scanf("%d%d",&n,&m);
 scanf("%s",a+1);
 for(i=1;i<=n;i++)
 	if(a[i]=='.')
 	{	p=i;
 		break;
 	}
 for(i=p+1;i<=n;i++)
 	if(a[i]>='5') break;
 if(i==n+1)
 {	k=n;
	while(a[k]=='0') k--;
	if(a[k]=='.') k--;
 	for(i=1;i<=n;i++)
 		printf("%c",a[i]);
	printf("\n");
	return 0;
 }
 else
 {	for(j=i+1;j<=n;j++) a[j]='0';
 	while(m && a[i]>='5')
 	{	j=i-1;
 		if(a[j]=='.') j--;
 		while(a[j]=='9')
		{	a[j]='0';
			j--;
		}
 		if(j==0)
 			a[0]='1';
 		else
 			a[j]++;
 		a[i]='0';	
 		i=j;
		if(i<p) break;
		m--;
	}
	k=n;
	while(a[k]=='0') k--;
	if(a[k]=='.') k--;
	if(a[0]=='1') printf("1");
	for(i=1;i<=k;i++)
		printf("%c",a[i]);
	return 0;
 }
 return 0;
}