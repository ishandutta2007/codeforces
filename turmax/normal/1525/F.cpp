#include <bits/stdc++.h> 

using namespace std; 
#define int long long 
const int maxn=55;
vector <int> h[maxn];
int mt[maxn];
bool used[maxn];
bool dfs(int x)
{
	if(used[x]) return false;
	used[x]=1;
	for(auto l:h[x])
	{
		if(mt[l]==(-1) || dfs(mt[l]))
		{
			mt[l]=x;
			return true; 
		}
	}
	return false;
}
int fin(int n)
{
    for(int i=0;i<n;++i) 
    {
    	mt[i]=(-1);used[i]=0;
    }
    for(int i=0;i<n;++i) {for(int j=0;j<n;++j) used[j]=0; dfs(i);}
    int ans=0;
    for(int i=0;i<n;++i) if(mt[i]!=(-1)) ++ans; 
    return ans;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	pair <int,int> u[k];
	for(int i=0;i<m;++i)
	{
		int x,y;
		cin>>x>>y;
		x--;y--;
        h[x].push_back(y);
	}
    pair <int,int> d3[k];
    pair <int,int> d2[k];
	for(int i=0;i<k;++i) {cin>>u[i].first>>u[i].second;d3[i]=u[i];}
	vector <int> z;
    int r=(n-1-fin(n));
    vector <int> l;
	for(int i=0;i<(k-r);++i)
	{
		vector <pair<int,int>> v;
		for(int j=0;j<=(r+i);++j) 
		{
			v.push_back({max(0LL,u[j].first)-max(0LL,u[j].first-u[j].second),j});
		}
		sort(v.begin(),v.end());
		int curr=v[0].second;
		u[curr].first-=u[curr].second;
		z.push_back(curr);
        l.push_back(v[0].first);
	}
    for(int i=z.size()-1;i>=0;--i)
    {
        for(int j=0;j<k;++j) d2[j]=d3[j];
        l.clear();
        for(int j=0;j<z.size();++j)
        {
             l.push_back(max(0LL,d2[z[j]].first)-max(0LL,d2[z[j]].first-d2[z[j]].second));
             d2[z[j]].first-=d2[z[j]].second;
        }
        int curr=0;
        for(int j=i;j<z.size();++j)
        {
            curr+=l[j];
        }
        for(int j=(r+i);j>=0;j--)
        {
            int curr2=d3[j].first; 
            if(curr2<curr)
            {
                curr=curr2;
                for(int k=i;k<z.size();++k)
                {
                    z[k]=j; 
                }
                ++i;
                break;
            }
        }
    }
	vector <int> d[k];
	for(int cyc=0;cyc<(k-r);++cyc)
	{
    bool ok1=0;
    for(int i=0;i<n;++i) 
    {
    	int res1=fin(n);
        vector <int> t=h[i];
        h[i].clear();
        int res2=fin(n);
        h[i]=t; 
        if(res1==res2) continue; 
        else 
        {
        	ok1=1;
            d[z[cyc]].push_back(i);
            h[i].clear(); 
            break;
        }
    }
    if(!ok1)
    {
    for(int i=0;i<n;++i) 
    {
    	int res1=fin(n);
        vector <int> v;
        for(int j=0;j<n;++j)
        {
        	for(int l=0;l<h[j].size();++l)
        	{
        		if(h[j][l]==i)
        		{
        			h[j].erase(h[j].begin()+l);
        			v.push_back(j);
        			break;
        		}
        	}
        }
        int res2=fin(n);
        if(res1==res2) 
        {
            for(auto l:v)
            {
            	h[l].push_back(i);
            }
            continue;
        }
        else 
        {
            d[z[cyc]].push_back(-i-2);
            break;
        }
    }
    }
    }
    int sum=k; 
    for(int i=0;i<k;++i) sum+=d[i].size();
    cout<<sum<<endl;
    for(int i=0;i<k;++i)
    {
    	for(auto h:d[i])
    	{
    		cout<<h+1<<' ';
    	}
    	cout<<0<<' ';
    }
	return 0;
}