#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const char s[10][10]={"1110111","0010010","1011101","1011011","0111010","1101011","1101111","1010010","1111111","1111011"};
int n,k,f[2005][2005],from[2005][2005],digit[2005][2005],sa[2005],now,ans[2005];
char t[2005][15];
int calc(char*from,const char*to)
{
	int res=0;
	for(int i=0;i<7;i++)
	{
		if(from[i]=='1'&&to[i]=='0')return -1;
		if(from[i]=='0'&&to[i]=='1')res++;
	}
	return res;
}
bool cmp(int a,int b)
{
	return f[now][a]<f[now][b];
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)f[0][i]=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",t[i]);
		for(int j=0;j<=k;j++)
		{
			f[i][j]=-1;
			for(int c=0;c<10;c++)
			{
				int v=calc(t[i],s[c]);
				if(v==-1||v>j)continue;
				if(f[i-1][j-v]*10+c>f[i][j])
				{
					f[i][j]=f[i-1][j-v]*10+c;
					from[i][j]=j-v;
					digit[i][j]=c;
				}
			}
			sa[j]=j;
		}
		now=i;
		sort(sa,sa+k+1,cmp);
		int last=-1,m=-1;
		for(int j=0;j<=k;j++)
		{
			if(last!=f[i][sa[j]])m++;
			last=f[i][sa[j]];
			f[i][sa[j]]=m;
		}
	}
	if(f[n][k]==-1)
	{
		printf("-1\n");
		return 0;
	}
	int nowi=n,nowj=k;
	while(nowi)
	{
		ans[nowi]=digit[nowi][nowj];
		nowj=from[nowi][nowj];
		nowi--;
	}
	for(int i=1;i<=n;i++)printf("%d",ans[i]);
	printf("\n");
	return 0;
}