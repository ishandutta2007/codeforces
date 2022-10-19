#include<bits/stdc++.h>
using namespace std;
const int N=2005;
const long long mod=998244353;
int n;
string s;
bool bad;
bool seen[N];
int cval[N];
vector<pair<int,int>>edges[N];
void flood(int x,int cv)
{
	if(seen[x])
	{
		if(cval[x]!=cv)
			bad=true;
		return;
	}
	seen[x]=true;
	cval[x]=cv;
	for(auto e:edges[x])
		flood(e.first,cv^e.second);
}
long long gogo()
{
	bad=false;
	int nc=0;
	for(int i=0;i<2*n+2;i++)
	{
		if(!seen[i])
		{
			flood(i,0);
			nc++;
		}
	}
	if(bad)
		return 0;
	long long ans=1;
	for(int i=0;i+1<nc;i++)
		ans=ans*2%mod;
	return ans;
}
long long get_res(int m)
{
	for(int i=0;i<N;i++)
	{
		seen[i]=false;
		cval[i]=-1;
		edges[i].clear();
	}
	for(int i=0;i<n;i++)
		edges[i].push_back(make_pair(n-1-i,0));
	for(int i=0;i<m;i++)
		edges[n+i].push_back(make_pair(n+(m-1-i),0));
	for(int i=m;i<n;i++)
	{
		edges[n+i].push_back(make_pair(2*n,0));
		edges[2*n].push_back(make_pair(n+i,0));	
	} 
	edges[2*n].push_back(make_pair(2*n+1,1));
	edges[2*n+1].push_back(make_pair(2*n,1));
	for(int i=0;i<n;i++)
	{
		char c=s[n-1-i];
		if(c=='0')
		{
			edges[i].push_back(make_pair(n+i,0));
			edges[n+i].push_back(make_pair(i,0));
		}
		else if(c=='1')
		{
			edges[i].push_back(make_pair(n+i,1));
			edges[n+i].push_back(make_pair(i,1));
		}
	}
	edges[0].push_back(make_pair(2*n+1,0));
	edges[2*n+1].push_back(make_pair(0,0));
	edges[n].push_back(make_pair(2*n+1,0));
	edges[2*n+1].push_back(make_pair(n,0));
	return gogo();
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>s;
	n=s.length();
	long long ans=0;
	for(int i=1;i<n;i++)
		ans=(ans+get_res(i))%mod;
	cout<<ans<<"\n";
	return 0;
}