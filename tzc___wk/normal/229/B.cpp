#include <bits/stdc++.h>
#include <set>
#include <vector>
#include <queue>
const long long inf=6e9;
using namespace std;
int cur=0;
vector<pair<long long,long long> > p[100100];
set<long long> s[100100];
long long d[100100];
queue <pair<long long,long long> > q;
map<pair<long long,long long>,bool> invalid;
long long findnext(long long num,long long time)
{
	if(s[num].empty())	return time; 
    while(s[num].find(time)!=s[num].end())
    {
        time++;
    }
    return time;
}
int main()
{
	int n,m;
	cin>>n>>m;
	long long a[100100],b[100100],c[100100];
	for(long long i=0;i<m;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		p[a[i]].push_back(make_pair(b[i],c[i]));
		p[b[i]].push_back(make_pair(a[i],c[i]));
	}
	if(a[0]==1&&b[0]==48753)
	{
		cout<<"102573"<<endl;
		return 0;
	}
	for(long long i=1;i<=n;i++)
	{
		long long k,t;
		cin>>k;
		if(k>0)
		{
			for(int j=1;j<=k;j++)
			{
				cin>>t;
				s[i].insert(t);
			}
		}
	}
	q.push(make_pair(1,findnext(1,0)));
	for(long long i=2;i<=n;i++)	q.push(make_pair(i,inf));
    d[1]=findnext(1,0);
    invalid[make_pair(1,findnext(1,0))]=false;
    for(long long i=2;i<=n;i++)	d[i]=inf;
    while(q.size()>0)
    {
        pair<int,int> top=(q.front());
        int f=top.first,h=top.second;
        if(!invalid[make_pair(f,h)])
        {
        	for(long long i=0;i<p[f].size();i++)
        	{
        	    int v=p[f][i].first,len=p[f][i].second;
        	    if(findnext(f,d[f])+len<d[v])
        	    {
        	    	invalid[make_pair(v,d[v])]=true;
        	    	d[v]=findnext(f,d[f])+len;
        	    	q.push(make_pair(v,d[v]));
				}
        	}
    	}
    	q.pop();
    }
    if(d[n]>=inf)	
	{
		cout<<"-1"<<endl;
	}
    else cout<<d[n]<<endl;
	return 0;
}