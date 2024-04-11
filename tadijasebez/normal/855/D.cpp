#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
vector< pair<int,int> > Tree[N];
int par[N],type[N];
vector<int> Roots;
int b[N],e[N],time,special,part;
int SpecialMark[N],Depth[N],PartMark[N];
int anc[N][200],SubTree[N],sub;
bool Part[N][200],Special[N][200];
void DFS(int cur, int prev, int depth)
{
	b[cur]=++time;
	Depth[cur]=depth;
	SubTree[cur]=sub;
	int i;	
	if(depth>200)
	{
		anc[cur][0]=prev;
		if(type[cur]==0) Part[cur][0]=true;
		else Special[cur][0]=true;
		for(i=1;i<200;i++)
		{
			anc[cur][i]=par[anc[cur][i-1]];
			if(Part[cur][i-1]) Part[cur][i]=true;
			if(Special[cur][i-1]) Special[cur][i]=true;
			if(type[anc[cur][i-1]]==0) Part[cur][i]=true;
			else Special[cur][i]=true;
		}
	}
	vector<int> SpecialChilds,PartChilds;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i].first;
		int t=Tree[cur][i].second;
		if(t==0) SpecialChilds.push_back(v);
		if(t==1) PartChilds.push_back(v);
	}
	if(!SpecialChilds.empty())
	{
		if(!SpecialMark[cur]) SpecialMark[cur]=++special;
		for(i=0;i<SpecialChilds.size();i++)
		{
			int v=SpecialChilds[i];
			SpecialMark[v]=SpecialMark[cur];
			DFS(v,cur,depth+1);
		}
	}
	if(!PartChilds.empty())
	{
		if(!PartMark[cur]) PartMark[cur]=++part;
		for(i=0;i<PartChilds.size();i++)
		{
			int v=PartChilds[i];
			PartMark[v]=PartMark[cur];
			DFS(v,cur,depth+1);
		}
	}
	e[cur]=time;
}
int main()
{
	int n,i,u,v,t,q;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i",&par[i],&type[i]);
		if(par[i]==-1)
		{
			Roots.push_back(i);
		}
		else
		{
			Tree[par[i]].push_back(make_pair(i,type[i]));
		}
	}
	for(i=0;i<Roots.size();i++){ sub++;DFS(Roots[i],0,1);}
	//for(i=1;i<=n;i++) printf("%i %i %i %i\n",i,Depth[i],SpecialMark[i],PartMark[i]);
	scanf("%i",&q);
	int br=0;
	while(q--)
	{
		scanf("%i %i %i",&t,&u,&v);
		br++;
		//if(n==1000 && br==873) printf("%i %i %i\n",t,u,v);
		if(u==v)
		{
			printf("NO\n");
			continue;
		}
		if(t==1)
		{
			if(SpecialMark[u] && SpecialMark[u]==SpecialMark[v])
			{
				if(b[u]<=b[v] && e[u]>=e[v]) printf("YES\n");
				else printf("NO\n");
			}
			else printf("NO\n");
		}
		if(t==2)
		{
			if(PartMark[u] && PartMark[u]==PartMark[v])
			{
				if(b[u]<=b[v] && e[u]>=e[v])
				{
					//if(n==1000 && br==873) printf("%i %i %i\n",t,u,v);
					printf("YES\n");
					continue;
				}
			}
			if(SubTree[u]==SubTree[v])
			{
				bool ok=true;
				if(Depth[u]>Depth[v])
				{
					while(Depth[u]>Depth[v])
					{
						if(Depth[u]-200>Depth[v])
						{
							if(Special[u][199]) ok=false;
							u=anc[u][199];
						}
						else
						{
							if(type[u]==1) ok=false;
							u=par[u];
						}
					}	
				}
				else if(Depth[v]>Depth[u])
				{
					while(Depth[v]>Depth[u])
					{
						if(Depth[v]-200>Depth[u])
						{
							if(Part[v][199]) ok=false;
							v=anc[v][199];
						}
						else
						{
							if(type[v]==0) ok=false;
							v=par[v];
						}
					}	
				}
				if(u!=v)
				{
					while(Depth[u]>200 && anc[u][199]!=anc[v][199])
					{
						if(Special[u][199]) ok=false;
						if(Part[v][199]) ok=false;
						u=anc[u][199];
						v=anc[v][199];
					}
					while(u!=v)
					{
						if(type[u]==1) ok=false;
						if(type[v]==0) ok=false;
						u=par[u];
						v=par[v];
					}
				}
				else ok=false;
				if(ok)
				{
					printf("YES\n");
					continue;
				}
			}
			//bool done=false;
			//while(par[u]>-1 && type[u]==0 && !done)
			//{
			//	u=par[u];
			//	if(PartMark[u] && PartMark[u]==PartMark[v])
			//	{
			//		if(b[u]<=b[v] && e[u]>=e[v])
			//		{
			//			printf("YES\n");
			//			done=true;
			//		}
			//	}
			//}
			//if(done) continue;
			//if(par[u]>-1 && type[u]==0 && PartMark[par[u]] && PartMark[par[u]]==PartMark[v])
			//{
			//	if(!(b[par[u]]>=b[v] && e[par[u]]<=e[v]))
			//	{
			//		printf("YES\n");
			//		continue;
			//	}
			//}
			printf("NO\n");
		}
	}
	return 0;
}