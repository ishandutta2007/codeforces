#include<iostream>
#include<stdio.h>
using namespace std;
char s[120][120];
char mx[120];
int n,m,i,j,ans;
int main()
{
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%s",s[i]);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			mx[j]=max(mx[j],s[i][j]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			if(s[i][j]==mx[j])
				break;
		j<m&&ans++;
	}
	printf("%d",ans);
	return 0;
}