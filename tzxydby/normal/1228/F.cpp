#include<bits/stdc++.h>
using namespace std;
const int N=1<<17;
vector<int>e[N],seq,res;
int f[N],n,ans;
pair<int,int> getfar(int v,int p=0)
{
	f[v]=p;
	pair<int,int> res=pair<int,int>(0,v);
	for(int i=0;i<e[v].size();i++)
	{
		int u=e[v][i];
		if(u==p)
			continue;
		pair<int,int> got=getfar(u,v);
		got.first++;
		res=max(res,got);	
	} 
	return res;
}
pair<int,int> solve(int v,int p=0)
{
	int ch=e[v].size()-(p!=0);
	if(ch>3) 
		return pair<int,int>(0,-1);
	if(ch==0) 
		return pair<int,int>(1,0);
	vector<int> valid,spec;
	for(int i=0;i<e[v].size();i++)
	{
		int u=e[v][i];
		if(u==p)
			continue;
		pair<int,int> got=solve(u,v);
		if(got.first==0)
			return pair<int,int>(0,-1);
		if(got.first==1)
			valid.push_back(got.second);
		else
			spec.push_back(got.second); 
	} 
	if(spec.size()>=2)
		return pair<int,int>(0,-1);
	sort(valid.begin(),valid.end());
	if(ch==1)
	{
		ans=v;
		if(valid.size()==1&&valid[0]==0)	
			return pair<int,int>(2,1);
		else
			return pair<int,int>(0,-1);
	}
	if(ch==2)
	{
		if(valid.size()>=2&&valid[0]==valid[1])
			return pair<int,int>(1,valid[0]+1);
		else if(valid.size()==1&&valid[0]==spec[0])
			return pair<int,int>(2,valid[0]+1);
		else
			return pair<int,int>(0,-1);
	}
	if(ch==3)
	{
		ans=v;
		if(valid.size()==3&&valid[0]==valid[1]&&valid[1]+1==valid[2])
			return pair<int,int>(2,valid[2]+1);
		else
			return pair<int,int>(0,-1);
	}
	return pair<int,int>(0,-1); 
} 
int main()
{
	scanf("%d",&n);
	n=(1<<n)-2;
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	pair<int,int> a=getfar(1);
	pair<int,int> b=getfar(a.second);
	pair<int,int> c=getfar(b.second);
	int v=c.second;
	while(v)
	{
		seq.push_back(v);
		v=f[v];
	}
	int md=seq.size()/2;
	for(int i=md-1;i<=md+2;i++)
	{
		if(0<=i&&i<seq.size())
		{
			pair<int,int> g=solve(seq[i]);
			if(g.first==2)
				res.push_back(ans);
		}
	}
	sort(res.begin(),res.end());
	printf("%d\n",res.size());
	for(auto i:res)
		printf("%d ",i);
	return 0;
}