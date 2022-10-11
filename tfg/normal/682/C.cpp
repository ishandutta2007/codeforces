#include <cstdio>
#include <vector>

struct edge
{
	int to;
	long long int cost;
};
struct vertex
{
	std::vector<edge> childs;
	long long int max_dist;
};

vertex tree[100100];

int dfs(int x, long long int dist, bool destroy)
{
	int ans=0;

	if(dist>tree[x].max_dist) destroy=true;
	if(dist<0) dist=0;
	//printf("walking on %i, maxdist=%lli, dist=%lli, destroy=%s\n",x,max_dist,dist,destroy?"true":"false");
	for(int i=0;i<tree[x].childs.size();i++)
		ans+=dfs(tree[x].childs[i].to, dist+tree[x].childs[i].cost, destroy);
	return ans+(destroy?1:0);
}

int main()
{
	int n;scanf("%i", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%lli", &tree[i].max_dist);
	}
	for(int i=1;i<n;i++)
	{
		edge temp;
		int father;
		scanf("%i %lli",&father,&temp.cost);
		temp.to=i;
		father--;
		tree[father].childs.push_back(temp);
		//printf("adding to=%i cost=%lli to %i\n",i,temp.cost,father);
	}
	printf("%lli",dfs(0,0,false));
}