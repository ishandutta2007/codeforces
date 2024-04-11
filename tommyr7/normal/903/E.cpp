#include <bits/stdc++.h>
#define Maxn 5007
using namespace std;
int n,k;
char s[Maxn][Maxn];
int pos[Maxn/2][Maxn/2][5];
int r[30];
bool flag=false;
bool check(int p,int q)
{
	for (int i=2;i<=n;i++)
	{
		int pos1=0,pos2=0,cnt=0;
		bool check1=false,check2=false;
		for (int j1=1;j1<=pos[1][i][0];j1++)
		{
			int j=pos[1][i][j1];
			if (s[1][j]!=s[i][j])
			{
				pos2=pos1;
				pos1=j;
				++cnt;
			}
			if (j==p) check1=true;
			if (j==q) check2=true;
		}
		if (s[1][p]!=s[i][p]&&!check1)
		{
			pos2=pos1;
			pos1=p;
			++cnt;
		}
		if (s[1][q]!=s[i][q]&&!check2)
		{
			pos2=pos1;
			pos1=q;
			++cnt;
		}
		if (cnt!=2&&cnt!=0) return false;
		if (cnt==0&&!flag) return false;
		if (cnt==2&&(s[1][pos1]!=s[i][pos2]||s[1][pos2]!=s[i][pos1])) return false;
	}
	return true;
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	memset(r,0,sizeof(r));
	for (int i=1;i<=k;i++)
		++r[s[1][i]-'a'+1];
	for (int i=1;i<=26;i++)
		if (r[i]>=2) flag=true;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			pos[i][j][0]=0;
			for (int p=1;p<=k;p++)
				if (s[i][p]!=s[j][p]) 
				{
					++pos[i][j][0];
					if (pos[i][j][0]>4)
					{
						printf("%d\n",-1);
						return 0;
					}
					pos[i][j][pos[i][j][0]]=p;
				}
		}
	for (int i=1;i<=k;i++)
		for (int j=i+1;j<=k;j++)
		{
			swap(s[1][i],s[1][j]);
			if (check(i,j))
			{
				for (int p=1;p<=k;p++)
					printf("%c",s[1][p]);
				printf("\n");
				return 0;
			}
			swap(s[1][i],s[1][j]);
		}
	printf("%d\n",-1);
	return 0;
}