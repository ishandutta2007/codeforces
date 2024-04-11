#include<cstdio>
#include<vector>
#include<map>
#include<cstring>
#include<algorithm>

using namespace std;

int dat[100100];
vector<int> cands;
vector<int> ids[450];

int valids[100100][2];//[i]->[[0],[1])
map<int,int> total;

int l[100100],r[100100],ans[100100];

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		scanf("%d",dat+i);
		total[dat[i]]++;
	}
	map<int,int>::iterator it=total.begin();
	while(it!=total.end())
	{
		if((*it).first<=(*it).second)
		{
			cands.push_back((*it).first);
		}
		it++;
	}
	for(int i=0;i<cands.size();i++)
	{
		ids[i].push_back(-1);
		for(int j=0;j<N;j++)
		{
			if(dat[j]==cands[i])
			{
				ids[i].push_back(j);
			}
		}
		ids[i].push_back(N);
	}
	for(int i=0;i<M;i++)
	{
		scanf("%d%d",l+i,r+i);
		ans[i]=0;
		l[i]--;r[i]--;
	}
	for(int i=0;i<cands.size();i++)
	{
		int val=cands[i];
		//printf("%d::",val);
		//for(int j=0;j<ids[i].size();j++)
		//{
		//	printf("%d ",ids[i][j]);
		//}
		//printf("\n");
		memset(valids,-1,sizeof(valids));
		for(int j=0;j+1+val<ids[i].size();j++)
		{
			for(int k=ids[i][j]+1;k<=ids[i][j+1];k++)
			{
				valids[k][0]=ids[i][j+val];
				valids[k][1]=ids[i][j+val+1];
			}
		}
		for(int j=0;j<M;j++)
		{
			if(valids[l[j]][0]<=r[j]&&valids[l[j]][1]>r[j])
			{
				ans[j]++;
			}
		}
		//for(int j=0;j<N;j++)
		//{
		//	printf("%d %d\n",valids[j][0],valids[j][1]);
		//}
	}
	for(int i=0;i<M;i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}