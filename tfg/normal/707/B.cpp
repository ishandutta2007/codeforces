#include <cstdio>
#include <vector>
#include <algorithm>

#define INF 1000000001

int n,m,k;
std::vector<int> edge_to[101000];
std::vector<int> edge_weight[101000];
//int edges[3][10100];//0 and 1 is conected, 2 is weight
std::vector<int> a;
int min=INF;



int main()
{
	scanf("%i %i %i",&n,&m,&k);
	if(k==0)
	{
		printf("-1");
		return 0;
	}
	for(int i=0;i<m;i++)
	{
		int v1,v2,w;
		scanf("%i %i %i",&v1,&v2,&w);
		edge_to[v1-1].push_back(v2-1);
		edge_weight[v1-1].push_back(w);
		edge_to[v2-1].push_back(v1-1);
		edge_weight[v2-1].push_back(w);
	}
	for(int i=0;i<k;i++)
	{
		int temp;scanf("%i",&temp);
		a.push_back(temp-1);
	}
	std::sort(a.begin(),a.end());
	//for(int i=0;i<k;i++) printf("%i ",a[i]);
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<edge_to[a[i]].size();j++)
		{
			if(!std::binary_search(a.begin(),a.end(),edge_to[a[i]][j]))
			{
				if(edge_weight[a[i]][j]<min) min=edge_weight[a[i]][j];
			}
		}
	}
	if(min==INF) printf("-1");
	else printf("%i",min);
}