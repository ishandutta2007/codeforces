#include<cstdio>
#include<vector>
#include<utility>
#include<queue>
#include<set>
#include<algorithm>

using namespace std;

const int bnd=314000000;

int seed[100100];
int diamond[100100];
vector<int> monsters[100100];
int unknown[100100];

vector<int> rules[100100];
vector<int> seeds[100100];

bool goodM[100100];

int mans[100100],Mans[100100];

typedef pair<int,int> P;

set<P> se;

int N,M;

void solve_min()
{
	for(int i=0;i<N;i++) mans[i]=bnd*2;
	for(int i=0;i<M;i++) if(unknown[i]==0) se.insert(P(diamond[i],seed[i]));
	while(!se.empty())
	{
		P p=*se.begin();
		se.erase(p);
		int d=p.first,s=p.second;
		if(mans[s]<=d) continue;
		mans[s]=d;
		for(int i=0;i<rules[s].size();i++)
		{
			unknown[rules[s][i]]--;
			if(unknown[rules[s][i]]==0)
			{
				int tmp=0;
				int id=rules[s][i];
				for(int j=0;j<monsters[id].size();j++)
				{
					tmp+=mans[monsters[id][j]];
					if(tmp>bnd) tmp=bnd;
				}
				tmp+=diamond[id];
				if(tmp>bnd) tmp=bnd;
				se.insert(P(tmp,seed[id]));
			}
		}
	}
}

void modify()
{
	for(int i=0;i<N;i++) Mans[i]=bnd*2;
	for(int i=0;i<N;i++)
	{
		if(mans[i]>bnd)
		{
			mans[i]=-1;
			Mans[i]=-1;
		}
	}
	for(int i=0;i<M;i++)
	{
		//if(mans[seed[i]]==-1) goodM[i]=false;
		//else goodM[i]=true;
		bool ok=true;
		for(int j=0;j<monsters[i].size();j++) if(mans[monsters[i][j]]==-1) ok=false;
		goodM[i]=ok;
	}
}

bool used[100100];
bool solved[100100];

int dfs(int v)
{
	if(solved[v]) return Mans[v];
	if(used[v]==true)
	{
		Mans[v]=-2;
		solved[v]=true;
		return -2;
	}
	used[v]=true;
	int res=-1;
	for(int i=0;i<seeds[v].size();i++)
	{
		int id=seeds[v][i];
		if(goodM[id]==false) continue;
		int tmp=diamond[id];
		for(int j=0;j<monsters[id].size();j++)
		{
			int a=dfs(monsters[id][j]);
			if(a==-2)
			{
				tmp=-2;
				break;
			}
			tmp+=a;
			if(tmp>bnd) tmp=bnd;
		}
		if(tmp==-2)
		{
			res=-2;
			break;
		}
		res=max(res,tmp);
	}
	Mans[v]=res;
	solved[v]=true;
	return res;
}

void solve_max()
{
	for(int i=0;i<N;i++) used[i]=false,solved[i]=false;
	for(int i=0;i<N;i++) if(used[i]==false&&mans[i]!=-1) dfs(i);
}
set<int> se2;

int main()
{
	scanf("%d%d",&M,&N);
	for(int i=0;i<M;i++)
	{
		se2.clear();
		scanf("%d",seed+i);
		seed[i]--;
		diamond[i]=0;
		int n;
		scanf("%d",&n);
		for(int j=0;j<n;j++)
		{
			int a;
			scanf("%d",&a);
			if(a==-1)
			{
				diamond[i]++;
				continue;
			}
			a--;
			monsters[i].push_back(a);
			se2.insert(a);
		}
		seeds[seed[i]].push_back(i);
		for(set<int>::iterator it=se2.begin();it!=se2.end();it++)
		{
			rules[*it].push_back(i);
		}
		unknown[i]=se2.size();
	}
	solve_min();
	modify();
	solve_max();
	for(int i=0;i<N;i++) printf("%d %d\n",mans[i],Mans[i]);
	return 0;
}