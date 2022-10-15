#include<bits/stdc++.h>
using namespace std;
int a[105],ans[105];
bool b[105];
int t;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	  {
	  	scanf("%d",&a[i]);
	  	if(!b[a[i]])
	  	  {
	  	  	ans[++t]=i;
	  	  	b[a[i]]=1;
		  }
	  	if(t==k)
	  	  {
	  	  	printf("YES\n");
			for(int j=1;j<=k;j++)
	  	  	  printf("%d ",ans[j]);
	  	  	return 0;
		  }
	  }
	printf("NO");
	return 0;
}