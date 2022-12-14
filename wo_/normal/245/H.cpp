#include<cstdio>
#include<cstring>

using namespace std;

int tmp[5050][5050];

char ch[5050];

int main()
{
	scanf("%s",ch);
	int N=strlen(ch);
	for(int i=0;i<N;i++)
	{
		tmp[i][i]++;
		for(int l=1;;l++)
		{
			if(i-l<0||i+l>=N) break;
			if(ch[i-l]!=ch[i+l]) break;
			tmp[i-l][i+l]++;
		}
	}
	for(int i=0;i<N-1;i++)
	{
		if(ch[i]!=ch[i+1]) continue;
		tmp[i][i+1]++;
		for(int l=1;;l++)
		{
			if(i-l<0||i+l+1>=N) break;
			if(ch[i-l]!=ch[i+l+1]) break;
			tmp[i-l][i+l+1]++;
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=1;j<N;j++)
		{
			tmp[i][j]+=tmp[i][j-1];
		}
	}
	for(int j=0;j<N;j++)
	{
		for(int i=1;i<N;i++)
		{
			tmp[i][j]+=tmp[i-1][j];
		}
	}
	int Q;
	scanf("%d",&Q);
	for(int i=0;i<Q;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;b--;
		int ans=0;
		if(a==0&&b==0) ans=1;
		else if(a==0)
		{
			ans=tmp[b][b];
		}
		else
		{
			ans=tmp[b][b]-tmp[b][a-1]-tmp[a-1][b]+tmp[a-1][a-1];
		}
		printf("%d\n",ans);
	}
	return 0;
}