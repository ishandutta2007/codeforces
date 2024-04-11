#include<stdio.h>
char s[500020];
int n,m,z=1,mo=1000003;
int f[500020][2];
int g[500020][2];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		for(int j=0;j<m;j++)
			if(s[j]!='.')
				f[i][j&1^(s[j]=='1'||s[j]=='2')]=g[j][i&1^(s[j]=='1'||s[j]=='4')]=1;
	}
	for(int i=0;i<n;i++)
		z=z*(2-f[i][0]-f[i][1])%mo;
	for(int j=0;j<m;j++)
		z=z*(2-g[j][0]-g[j][1])%mo;
	printf("%d\n",z);
	return 0;
}