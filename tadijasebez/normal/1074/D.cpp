#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
map<int,int> par,xr,sol;
map<int,vector<pair<int,int> > > E;
int Find(int x)
{
	if(!par[x]) return x;
	int y=Find(par[x]);
	xr[x]^=xr[par[x]];
	return par[x]=y;
}
bool ok=1;
void Union(int x, int y, int w)
{
	ok=1;
    Find(x);Find(y);
    int xw=xr[x],yw=xr[y];
    x=Find(x);y=Find(y);
    if(x==y){ if(w^xw^yw!=0) ok=0;return;}
    else
	{
		xr[x]=xw^yw^w;
		par[x]=y;
	}
}
int GetDist(int x, int y)
{
	Find(x);Find(y);
	return xr[x]^xr[y];
}
void DFS(int u)
{
	for(auto p:E[u])
	{
		int v=p.first,w=p.second;
		if(sol.count(v)) continue;
		sol[v]=sol[u]^w;
		DFS(v);
	}
}
int main()
{
	sol[0]=0;
	int q,l,r,t,x,i,last=0;
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i %i",&t,&l,&r);
		l^=last;r^=last;
		l++;r++;
		if(l>r) swap(l,r);
		//printf(":D %i %i %i\n",t,l-1,r-1);
		if(t==2)
		{
			if(sol.count(r) && sol.count(l-1)) last=sol[r]^sol[l-1],printf("%i\n",last);
			else if(Find(r)==Find(l-1)) last=GetDist(l-1,r),printf("%i\n",last);
			else last=1,printf("-1\n");
		}
		else
		{
			scanf("%i",&x);x^=last;
			l--;
			if(!sol.count(l) && !sol.count(r))
			{
				Union(l,r,x);
				if(ok) E[l].pb(mp(r,x)),E[r].pb(mp(l,x));
			}
			else if(sol.count(l) && sol.count(r))
			{

			}
			else if(sol.count(l))
			{
				sol[r]=sol[l]^x;
				//printf("sol[r]=%i\n",sol[r]);
				DFS(r);
			}
			else if(sol.count(r))
			{
				sol[l]=sol[r]^x;
				DFS(l);
			}
		}
	}
	return 0;
}