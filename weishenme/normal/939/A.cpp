#include<bits/stdc++.h>
using namespace std;
int n,f[5005];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&f[i]);
	for (int i=1;i<=n;i++)
	 if (f[f[f[i]]]==i)
	  {
	  	puts("YES");
	  	return 0;
	  }
	puts("NO");  
}