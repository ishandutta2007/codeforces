#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	string score[110];
	int n,m;
	bool suc[110];
	memset(suc,false,sizeof(suc));
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		cin>> score[i];
	}
	for(int i=0;i<m;i++)
	{
		char maxscore='0';
		for(int j=0;j<n;j++)
		{
			maxscore=max(maxscore,score[j][i]);
		}
		for(int j=0;j<n;j++)
		{
			if(score[j][i]==maxscore)
			{
				suc[j]=true;
			}
		}
	}
	int res=0;
	for(int i=0;i<n;i++)
	{
		if(suc[i]) res++;
	}
	printf("%d\n",res);
	return 0;
}