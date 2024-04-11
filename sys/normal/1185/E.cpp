#include <bits/stdc++.h>
using namespace std;
const int Maxn=2005; 
int maxi,T,n,m,cnt1[30][Maxn],cnt2[30][Maxn];
bool vis[30],covered[30],flag;
char re[Maxn][Maxn];
string str[Maxn];
struct point
{
	int x,y;
}S[Maxn],E[Maxn];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=26;i++)
			S[i].x=S[i].y=E[i].x=E[i].y=0;
		maxi=0;
		flag=true;
		memset(covered,0,sizeof(covered));
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=26;i++)
		{
			memset(cnt1[i],0,sizeof(int[n+1]));
			memset(cnt2[i],0,sizeof(int[m]));
		}
		for(int i=1;i<=n;i++)
			cin>>str[i];
		for(int i=1;i<=n;i++)
			for(int j=0;j<m;j++)
				if(str[i][j]!='.') flag=false;
		if(flag)
		{
			printf("YES\n0\n");
			continue;
		}
		flag=false;
		for(int i=1;i<=n;i++)
			for(int j=0;j<m;j++)
				if(str[i][j]!='.')
				{
					cnt1[str[i][j]-'a'+1][i]++,cnt2[str[i][j]-'a'+1][j]++;
					if(!vis[str[i][j]-'a'+1])
					{
						vis[str[i][j]-'a'+1]=true;
						S[str[i][j]-'a'+1]=(point){i,j};
					}
					E[str[i][j]-'a'+1]=(point){i,j};
				}
		for(int i=1;i<=26;i++)
			if(S[i].x) maxi=i;
		int tmp1=0,tmp2=0;
		for(int i=1;i<=26;i++)
		{
			tmp1=tmp2=0;
			if(!E[i].x) continue;
			for(int j=1;j<=n;j++)
				tmp1+=(bool)cnt1[i][j];
			for(int j=0;j<m;j++)
				tmp2+=(bool)cnt2[i][j];
			if((tmp1>1)+(tmp2>1)==2)
			{
				printf("NO\n");
				goto A;
			}
			if(tmp1==1)
			{
				for(int j=S[i].y;j<=E[i].y;j++)
					if(str[S[i].x][j]-'a'+1!=i) covered[i]=true;
			}
			else
			{
				for(int j=S[i].x;j<=E[i].x;j++)
					if(str[j][S[i].y]-'a'+1!=i) covered[i]=true;
			}
			if(!covered[i]) flag=true;
		}
		if(!flag)
		{
			printf("NO\n");
			goto A;
		}
		for(int i=1;i<=n;i++)
			for(int j=0;j<m;j++)
				re[i][j]='.';
		for(int i=1;i<=26;i++)
		{
			if(S[i].x)
			{
				for(int j=S[i].x;j<=E[i].x;j++)
					for(int k=S[i].y;k<=E[i].y;k++)
						re[j][k]=i+'a'-1;
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=0;j<m;j++)
				if(re[i][j]!=str[i][j])
				{
					printf("NO\n");
					goto A;
				}
		for(int i=1;i<=maxi;i++)
			if(!S[i].x)  S[i]=S[maxi],E[i]=E[maxi];
		printf("YES\n%d\n",maxi);
		for(int i=1;i<=maxi;i++)
			printf("%d %d %d %d\n",S[i].x,S[i].y+1,E[i].x,E[i].y+1); 
		A:;
	}
	return 0;
}