#include<cstdio>
#include<vector>

using namespace std;

vector<int> cri[100100],notcri[100100];
int totalnot=0;
int crinum[100100]={},notcrinum[100100]={};

bool cand[100100];
int candnum=0;

int claim[100100];

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",claim+i);
		int num=claim[i];
		if(num>0)
		{
			cri[num].push_back(i);
			crinum[num]++;
		}
		else
		{
			notcri[-num].push_back(i);
			notcrinum[-num]++;
			totalnot++;
		}
	}
	for(int c=1;c<=N;c++)
	{
		int lie=crinum[c]+totalnot-notcrinum[c];
		if(lie!=M)
		{
			cand[c]=false;
			continue;
		}
		cand[c]=true;
		candnum++;
	}
	if(candnum==1)
	{
		int criminal;
		for(int i=1;i<=N;i++) if(cand[i]==true) criminal=i;
		for(int i=1;i<=N;i++)
		{
			if(claim[i]>0&&claim[i]==criminal) printf("Truth\n");
			else if(claim[i]>0) printf("Lie\n");
			if(claim[i]<0&&claim[i]==-criminal) printf("Lie\n");
			else if(claim[i]<0) printf("Truth\n");
		}
	}
	else
	{
		for(int i=1;i<=N;i++)
		{
			if(claim[i]>0)
			{
				if(cand[claim[i]]==false) printf("Lie\n");
				else printf("Not defined\n");
			}
			else
			{
				if(cand[-claim[i]]==false) printf("Truth\n");
				else printf("Not defined\n");
			}
		}
	}
	return 0;
}