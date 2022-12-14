#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
#include <set>
using namespace std;
#define N 250005
#define ll long long 
int n,now,d[N],vis[N],nxt[N];ll sum,ans,f[N][2];
struct Heap
{
	priority_queue<ll >a,b;ll sum;int size;
	void insert(ll x){a.push(x);sum+=x,size++;}
	void erase(ll x){b.push(x);sum-=x,size--;}
	void clear(){while(!b.empty()&&a.top()==b.top())a.pop(),b.pop();}
	ll pop(){clear();ll tmp=a.top();sum-=tmp,size--;a.pop();return tmp;}
	bool empty(){return !size;}
	ll top(){clear();return a.top();}
}s[N];
struct P
{
	int x,y;
	P(){x=y=0;}
	P(int a,int b){x=a,y=b;}
	bool operator < (const P &a) const {return d[x]>d[a.x];}
};
vector<P >v[N];
vector<ll >used,out;
vector<int >hav[N];
void dfs(int x,int from)
{
	vis[x]=now;
	while(s[x].size>d[x]-now)s[x].pop();
	for(int i=0;i<v[x].size();i++)
	{
		int to1=v[x][i].x;if(d[to1]<=now)break;
		if(to1!=from)dfs(to1,x);
	}
	used.clear(),out.clear();ll ret=0;int cnt=d[x]-now;
	for(int i=0;i<v[x].size();i++)
	{
		int to1=v[x][i].x,val=v[x][i].y;if(d[to1]<=now)break;
		if(to1!=from)
		{
			ll t=f[to1][1]+val-f[to1][0];
			if(t<0){cnt--;ret+=t+f[to1][0];continue;}
			ret+=f[to1][0],s[x].insert(t),used.push_back(t);
		}
	}
	while(!s[x].empty()&&s[x].size>cnt)out.push_back(s[x].pop());
	f[x][0]=ret+s[x].sum;
	while(!s[x].empty()&&s[x].size>cnt-1)out.push_back(s[x].pop());
	f[x][1]=ret+s[x].sum;
	for(int i=0;i<out.size();i++)s[x].insert(out[i]);
	for(int i=0;i<used.size();i++)s[x].erase(used[i]);
}

void init(int x)
{
	for(int i=0;i<v[x].size();i++)
	{
		int to1=v[x][i].x;
		if(d[to1]>now)s[to1].insert(v[x][i].y);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1,x,y,z;i<n;i++)
		scanf("%d%d%d",&x,&y,&z),d[x]++,d[y]++,sum+=z,
		v[x].push_back(P(y,z)),v[y].push_back(P(x,z));
	for(int i=1;i<=n;i++)hav[d[i]].push_back(i),sort(v[i].begin(),v[i].end());
	printf("%lld ",sum);nxt[n]=n;
	for(int i=n-1;i;i--)if(hav[i+1].size())nxt[i]=i+1;else nxt[i]=nxt[i+1];
	for(now=1;now<n;printf("%lld ",ans),now++,ans=0)
	{
		for(int i=0;i<hav[now].size();i++)init(hav[now][i]);
		for(int k=now+1;k<n;k=nxt[k])
			for(int i=0;i<hav[k].size();i++)
				if(vis[hav[k][i]]!=now)dfs(hav[k][i],0),ans+=f[hav[k][i]][0];
	}puts("");
}