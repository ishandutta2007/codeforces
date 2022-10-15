#include<bits/stdc++.h>
using namespace std;
int a[10001],b[10001],n;
int main()
{
	scanf("%d",&n);
	int suma=0,sumb=0;
	for(int i=1;i<=n;i++)
	  {
	  	scanf("%d",&a[i]);
	  	suma+=a[i];
	  }
	for(int i=1;i<=n;i++)
	  {
	  	scanf("%d",&b[i]);
	  	sumb+=b[i];
	  }
	if(suma>=sumb)
	  printf("Yes");
	else
	  printf("No");
	return 0;
}