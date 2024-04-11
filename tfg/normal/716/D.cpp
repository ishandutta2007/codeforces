#include <vector>
#include <cstdio>
#include <utility>
#include <queue>
#include <algorithm>

typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;

const int inf=1e9+9;

struct Edge
{
	bool defined;
	int v1, v2;
	int w;
};

std::vector<int> graph[1010];
Edge edges[10010];

int dji_it=0;
int vertex_it[1010];//iteration of dji
int dist[1010];//distance
int dji_comp[1010];//is the first edge that was undefined on the way to this vertex

int n, m, L, s, t;

int dji(int o, bool ignore)
{
	dji_it++;
	//printf("Starting dji #%i.\n",dji_it);
	std::priority_queue<iii, std::vector<iii>, std::greater<iii> > hp;
	int ans=0;
	hp.push(iii(0,ii(o,-1)));//<dist,to,edge> from and edge are used if they come from a undefined
	while(!hp.empty())
	{
		iii now=hp.top();
		hp.pop();
		int on=now.second.first;
		if(vertex_it[on]==dji_it) continue;
		if(now.first>inf) return inf;
		vertex_it[on]=dji_it;
		dji_comp[on]=now.second.second;
		if(on==t) return now.first;
		dist[on]=now.first;
		//printf("distance to %i is %i.\n", on, now.first);
		for(int i=0;i<graph[on].size();i++)
		{
			if(ignore && (!edges[graph[on][i]].defined)) continue;
			if(vertex_it[edges[graph[on][i]].v1]==dji_it && vertex_it[edges[graph[on][i]].v2]==dji_it) continue;
			long long int next_distance=edges[graph[on][i]].w + now.first;
			int next_vertex=(edges[graph[on][i]].v1==on)?edges[graph[on][i]].v2:edges[graph[on][i]].v1;
			//printf("adding edge to %i, dist is %lli.\n", next_vertex, next_distance);
			if(now.second.second==-1 && (!edges[graph[on][i]].defined))
				hp.push(iii(next_distance,ii(next_vertex,graph[on][i])));
			else
				hp.push(iii(next_distance,ii(next_vertex,now.second.second)));
		}
	}
	return inf;
}


int main()
{
	scanf("%i %i %i %i %i",&n,&m,&L,&s,&t);
	for(int i=0;i<m;i++)
	{
		scanf("%i %i %i",&edges[i].v1,&edges[i].v2,&edges[i].w);
		if(edges[i].w==0)
		{
			edges[i].w=1;
			edges[i].defined=false;
		}
		else
			edges[i].defined=true;
		graph[edges[i].v1].push_back(i);
		graph[edges[i].v2].push_back(i);
	}
	if(dji(s, true)<L) {printf("NO\n");return 0;}
	if(dji(s, false)>L) {printf("NO\n");return 0;}
	printf("YES\n");

	int min=0;
	while(1)
	{
		min=dji(s, false);
		if(min==L) break;
		int num_edge=dji_comp[t];
		edges[num_edge].w=1+L-min;
		edges[num_edge].defined=true;
	}

	for(int i=0;i<m;i++)
	{
		printf("%i %i %i\n",edges[i].v1, edges[i].v2, edges[i].w);
	}

}