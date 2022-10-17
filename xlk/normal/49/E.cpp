#include<stdio.h>
#include<string.h>
#include<bitset>
char s[60],t[60],o[9];
int x[60],y[60],z[60],f[60][60],ns,nt,m;
std::bitset<60> b[60][60];
int fs[60][60],ft[60][60];
void work(int &n,char *s,int f[60][60])
{
	n=strlen(s);
	memset(b,0,sizeof b);
	for(int i=0;i<n;i++)
		b[i][i+1][s[i]-97]=1;
	for(int j=2;j<=n;j++)
		for(int i=0;i+j<=n;i++)
			for(int k=i+1;k<i+j;k++)
				for(int c=0;c<m;c++)
					b[i][i+j][z[c]]=b[i][i+j][z[c]]||b[i][k][x[c]]&&b[k][i+j][y[c]];
	for(int i=0;i<n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=0;k<26;k++)
				if(b[i][j][k])
					f[i][j]|=1<<k;
}
int main()
{
	scanf("%s%s%d",s,t,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%s",o);
		x[i]=o[3]-97;
		y[i]=o[4]-97;
		z[i]=o[0]-97;
	}
	work(ns,s,fs),work(nt,t,ft);
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for(int i=0;i<=ns;i++)
		for(int x=0;x<=nt;x++)
			for(int j=i+1;j<=ns;j++)
				for(int y=x+1;y<=nt;y++)
					if(fs[i][j]&ft[x][y]&&f[i][x]+1<f[j][y])
						f[j][y]=f[i][x]+1;
	printf("%d\n",f[ns][nt]<=100?f[ns][nt]:-1);
	return 0;
}