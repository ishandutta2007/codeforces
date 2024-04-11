#pragma GCC optimize("O3","Ofast","unroll-loops")
#include <bits/stdc++.h> 

using namespace std;
#define int long long
const int maxn=2e5+5;
vector <int> a[maxn];
bool used[maxn];
int pr[maxn];
int u[maxn][20];
int tin[maxn];
int tout[maxn];
int timer=0;
int sub[maxn];
int f[maxn];
void dfs(int x)
{
	used[x]=1;
	tin[x]=timer;
	u[x][0]=pr[x];
	sub[x]=1;
	for(int i=1;i<20;++i)
	{
		if(u[x][i-1]==(-1)) 
		{
			u[x][i]=(-1);
		}
		else 
		{
			u[x][i]=u[u[x][i-1]][i-1];
		}
	}
	++timer;
	used[x]=1;
	for(auto v:a[x])
	{
		if(!used[v]) {if(x==0) {f[v]=v;} else {f[v]=f[x];} pr[v]=x;u[v][0]=x;dfs(v);sub[x]+=sub[v];}
	}
	++timer;
	tout[x]=timer;
}
bool pred(int x,int y)
{
	return (x==(-1) || (tin[x]<=tin[y] && tout[x]>=tout[y]));
}
int lca(int x,int y,int l=20)
{
	if(pred(x,y)) return x;
	if(pred(pr[x],y)) return pr[x];
    for(int i=(l-1);i>=0;i--)
    {
    	if(!pred(u[x][i],y))
    	{
    		 return lca(u[x][i],y,i);
    	}
    }
    assert(false);
    return 0;
}
bool in(int a,int b,int c)
{
	if(c==(-1)) return false;
    int lc=lca(a,b);
    if(!pred(lc,c)) 
    {
    	return false;
    }
    return (pred(c,a) || pred(c,b));
}
int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;++i) used[i]=0;
		pr[0]=(-1);
		f[0]=0;
		timer=0;
		for(int i=0;i<n;++i) a[i].clear();
		pair <int,int> b[n-1];
        for(int i=0;i<(n-1);++i)
        {
        	int x,y;
        	cin>>x>>y;
        	a[x].push_back(y);a[y].push_back(x);
        	b[i]={x,y};
        }
        dfs(0);
        int l=0,r=0; 
        int lc=0;
        int ans0=0;
        for(auto h:a[0])
        {
        	ans0+=(sub[h]*(sub[h]-1)/2);
        }
        cout<<ans0<<' '; 
        int curr=n*(n-1)/2-ans0;
        for(int i=1;i<=n;++i)
        {
        	if(i==n) {cout<<curr<<' ';break;}
        	int x;
        	if(in(l,r,i)) {x=i;}
        	else if(in(l,i,r)) {x=r;r=i;}
        	else if(in(r,i,l)) {x=l;l=i;}
        	else {x=(-1);}
        	if(in(l,r,x))
        	{
                if(l!=0 && r!=0)
                {
                	cout<<curr-sub[l]*sub[r]<<' ';
                	curr=sub[l]*sub[r];
                }
                else if(l==0)
                {
                    int res1=sub[r];
                    int o=f[r];
                    res1*=(sub[0]-sub[o]);
                    cout<<curr-res1<<' ';
                    curr=res1;
                }
                else if(r==0)
                {
                	swap(l,r);
                    int res1=sub[r];
                    int o=f[r];
                    res1*=(sub[0]-sub[o]);
                    cout<<curr-res1<<' ';
                    curr=res1;
                    swap(l,r);
                }
        	}
        	else 
        	{
        		cout<<curr<<' ';
        		for(int j=(i+1);j<=n;++j) 
        		{
        			cout<<0<<' ';
        		}
        		break;
        	}
        }
        cout<<endl;
	}
	return 0;
}