#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,l,f[105][105][105],from[105][105][105],fail[105],nxt[105][26];
char s1[105],s2[105],v[105],ans[105];
int main()
{
	scanf("%s%s%s",s1+1,s2+1,v+1);
	n=(int)strlen(s1+1);
	m=(int)strlen(s2+1);
	l=(int)strlen(v+1);
	for(int i=1;i<l;i++)
	{
		int j=fail[i];
		while(j&&v[j+1]!=v[i+1])j=fail[j];
		if(v[j+1]==v[i+1])fail[i+1]=j+1;
		else fail[i+1]=0;
	}
	for(int i=0;i<=l;i++)
	for(int c=0;c<26;c++)
	{
		int j=i;
		while(j&&v[j+1]!=c+'A')j=fail[j];
		if(v[j+1]==c+'A')nxt[i][c]=j+1;
		else nxt[i][c]=0;
	}
	memset(f,0x80,sizeof(f));
	f[0][0][0]=0;
	for(int i=0;i<=n;i++)
	for(int j=0;j<=m;j++)
	for(int k=0;k<l;k++)
	{
		if(i<n&&f[i+1][j][k]<f[i][j][k])
		{
			f[i+1][j][k]=f[i][j][k];
			from[i+1][j][k]=i*40000+j*200+k;
		}
		if(j<m&&f[i][j+1][k]<f[i][j][k])
		{
			f[i][j+1][k]=f[i][j][k];
			from[i][j+1][k]=i*40000+j*200+k;
		}
		if(i<n&&j<m&&s1[i+1]==s2[j+1]&&f[i+1][j+1][nxt[k][s1[i+1]-'A']]<f[i][j][k]+1)
		{
			f[i+1][j+1][nxt[k][s1[i+1]-'A']]=f[i][j][k]+1;
			from[i+1][j+1][nxt[k][s1[i+1]-'A']]=i*40000+j*200+k;
		}
	}
	int x=n,y=m,z=0;
	for(int i=0;i<l;i++)
	  if(f[n][m][i]>f[n][m][z])
	    z=i;
	if(f[x][y][z]==0)return puts("0"),0;
	while(x&&y)
	{
		ans[f[x][y][z]]=s1[x];
		int v=from[x][y][z];
		x=v/40000,y=v/200%200,z=v%200;
	}
	printf("%s\n",ans+1);
	return 0;
}