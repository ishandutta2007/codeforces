#include<cstdio>
#include<vector>
#include<set>

using namespace std;

vector<int> G[100100];

int used[100100];

int main()
{
	int N,M,h,t;
	scanf("%d%d%d%d",&N,&M,&h,&t);
	for(int i=0;i<M;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int ub=h+t+5;
	int a=1;
	for(int u=0;u<N;u++)
	{
		for(int i=0;i<G[u].size();i++)
		{
			a++;
			int v=G[u][i];
			int head=G[u].size()-1,tail=G[v].size()-1;
			if(head<h||tail<t) continue;
			int hcnt=0,tcnt=0,both=0;
			//set<int> heads,tails;
			for(int j=0;j<min(head+1,ub);j++)
			{
				if(G[u][j]==v) continue;
				used[G[u][j]]=a;
				hcnt++;
				//heads.insert(G[u][j]);
			}
			for(int j=0;j<min(tail+1,ub);j++)
			{
				if(G[v][j]==u) continue;
				//if(heads.find(G[v][j])==heads.end())
				//{
				//	tails.insert(G[v][j]);
				//}
				//else
				//{
				//	if(heads.size()>h)
				//	{
				//		heads.erase(G[v][j]);
				//		tails.insert(G[v][j]);
				//	}
				//}
				tcnt++;
				if(used[G[v][j]]==a) both++;
			}
			//if(heads.size()>=h&&tails.size()>=t)
			if(hcnt<h||tcnt<t||hcnt+tcnt-both<h+t) continue;
			set<int> heads,tails;
			for(int j=0;j<min(h+t+5,(int)G[u].size());j++)
			{
				if(G[u][j]==v) continue;
				heads.insert(G[u][j]);
			}
			for(int j=0;j<min(h+t+5,(int)G[v].size());j++)
			{
				if(G[v][j]==u) continue;
				if(heads.find(G[v][j])==heads.end()) tails.insert(G[v][j]);
				else
				{
					if(heads.size()>h)
					{
						heads.erase(G[v][j]);
						tails.insert(G[v][j]);
					}
				}
			}
		//	{
				printf("YES\n");
				printf("%d %d\n",u+1,v+1);
				set<int>::iterator it=heads.begin();
				int cnt=0;
				for(;cnt<h;cnt++,it++)
				{
					printf("%d%c",*it+1,cnt==h-1?'\n':' ');
				}
				cnt=0;
				it=tails.begin();
				for(;cnt<t;cnt++,it++)
				{
					printf("%d%c",*it+1,cnt==t-1?'\n':' ');
				}
				return 0;
		//	}
		}
	}
	printf("NO\n");
	return 0;
}