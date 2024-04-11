#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=200050;
const int M=N*20;
int x[M],ls[M],rs[M],clock,root[N<<2];
//void Set(int &c, int ss, int se, int qi)
//{
//	if(!c) c=++clock;
//	x[c]++;
//	if(ss==se) return;
//	int mid=ss+se>>1;
//	if(qi<=mid) Set(ls[c],ss,mid,qi);
//	else Set(rs[c],mid+1,se,qi);
//}
bool on=false;
vector<int> back;
void Set(int p, int &c, int ss, int se, int qi)
{
	if(back.empty()) c=++clock;
	else c=back.back(),back.pop_back();
	if(on) back.push_back(p);
	x[c]=x[p]+1,ls[c]=ls[p],rs[c]=rs[p];
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[p],ls[c],ss,mid,qi);
	else Set(rs[p],rs[c],mid+1,se,qi);
}
int sz,n;
vector< pair<int,int> > upd;
void Set(int c, int qi)
{
	upd.push_back(make_pair(qi,c));
	//for(;c<=sz;c+=c&-c) Set(root[c],1,n,qi);
}
void Set()
{
	sort(upd.begin(),upd.end());
	int i,j=0;
	for(i=1;i<=n;i++)
	{
		root[i]=root[i-1];
		on=false;
		int br=0;
		while(j<upd.size() && upd[j].first==i)
		{
			if(br) on=true;
			Set(root[i],root[i],1,sz,upd[j].second);
			br++;
			j++;
		}
	}
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
int Get(int c, int qs, int qe)
{
	return Get(root[qe],1,sz,1,c)-Get(root[qs-1],1,sz,1,c);
	//int ans=0;
	//for(;c;c-=c&-c) ans+=Get(root[c],1,n,qs,qe);
	//return ans;
}
vector<long long> index;
int FindIndex(long long x)
{
	int top=index.size()-1;
	int bot=0;
	int mid;
	while(top>bot)
	{
		mid=top+bot>>1;
		if(index[mid]<x) bot=mid+1;
		else top=mid;
	}
	return top+1;
}
vector< pair<int,int> > Tree[N];
int b[N],e[N],a[N],time;
void DFS(int cur, int prev, long long path)
{
	index.push_back(path);
	index.push_back(path-a[cur]);
	int i;
	b[cur]=++time;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i].first;
		int w=Tree[cur][i].second;
		if(v!=prev)
		{
			DFS(v,cur,path+w);
		}
	}
	e[cur]=time;
}
void MakeIndex()
{
	sort(index.begin(),index.end());
	index.erase(unique(index.begin(),index.end()),index.end());
	sz=index.size();
}
int sol[N];
void Prepare(int cur, int prev, long long path)
{
	Set(FindIndex(path-a[cur]),b[cur]);
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i].first;
		int w=Tree[cur][i].second;
		if(v!=prev)
		{
			Prepare(v,cur,path+w);
		}
	}
}
void Solve(int cur, int prev, long long path)
{
	sol[cur]=Get(FindIndex(path),b[cur],e[cur]);
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i].first;
		int w=Tree[cur][i].second;
		if(v!=prev)
		{
			Solve(v,cur,path+w);
		}
	}
}
int main()
{
	int u,v,i,w;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=2;i<=n;i++) 
	{
		scanf("%i %i",&u,&w);
		Tree[i].push_back(make_pair(u,w));
		Tree[u].push_back(make_pair(i,w));
	}
	DFS(1,0,0);
	MakeIndex();
	Prepare(1,0,0);
	Set();
	Solve(1,0,0);
	for(i=1;i<=n;i++) printf("%i ",sol[i]-1);
	return 0;
}