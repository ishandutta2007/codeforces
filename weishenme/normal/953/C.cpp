#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	 if (n%i==0)
	  {
	  	int flag=1;
	  	for (int j=1;j<=i;j++)
	  	 if (a[j]!=a[1])flag=0;
	  	if (!flag)continue;
	  	int la=a[1]^1;
	  	for (int k=2;k<=n/i;k++)
	  	 {
	  	 	for (int j=(k-1)*i+1;j<=k*i;j++)
	  	 	 if (a[j]!=la)flag=0;
	  	 	if (!flag)break;
			la=la^1; 
	  	 }
	  	if (flag)
		 {
		 	puts("YES");
		 	return 0;
		 } 
	  }
	puts("NO");  
}