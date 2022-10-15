#include<bits/stdc++.h>
using namespace std;
char a[101][101],smaller[101],small[101];
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  {
	  	for(int j=1;j<=m;j++)
	  	  cin>>a[i][j];
	  	getchar();
	  }
	int sum=0;
	memset(small,'0',sizeof(small));
	memset(smaller,'0',sizeof(smaller));
	for(int i=1;i<=m;i++)
	  {
	  	strcpy(small,smaller);
	  	for(int j=1;j<n;j++)
	      {
	        if(a[j][i]<a[j+1][i])
	          smaller[j]='1';
	        if(a[j][i]>a[j+1][i]&&smaller[j]!='1')
	          {
	          	sum++;
	          	strcpy(smaller,small);
	          	break;
			  }
		  }
	 }
	printf("%d",sum);
	return 0;
}