#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 500005
vector<int> G[N];
int n,m;
int dgr[N],fa[N],vis[N],ok[N],qwq[N],OK,d[N],dep[N],qbq[N];
bool tag;
void dfs(int u,int f)
{
	fa[u]=f,vis[u]=1,dep[u]=dep[f]+1;
	if(OK) return ;
	int minn=inf,mid=0;
	for(int v:G[u])
	{
		if(v==f) continue;
		if(dgr[v]%3!=2) continue;
		if(vis[v]&&abs(dep[u]-dep[v])+1!=n)
		{
			if(abs(dep[u]-dep[v])+1<minn)
			{
				minn=abs(dep[u]-dep[v])+1,mid=v;
			}
		}
	}
	if(mid)
	{
		// printf("%d %d\n",u,mid);
		OK=1;
		ok[mid]=1; int tmp=u;
		while(tmp!=mid) ok[tmp]=1,tmp=fa[tmp];
		return ;
	}
	for(int v:G[u])
	{
		if(v==f) continue;
		if(dgr[v]%3!=2) continue;
		if(!vis[v]) dfs(v,u);
		if(OK) return ;
	}
}
pair<vector<int>,int> getlef(int u,int ND)
{
	for(int i=1;i<=n;i++) qwq[i]=d[i]=fa[i]=0;
	qwq[u]=1; queue<int> q; q.push(u);
	vector<int> nd; nd.pb(u);
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		// cout<<u<<"--"<<endl;
		for(int v:G[u])
		{
			if(dgr[v]%3==2&&!qwq[v])
			{
				qwq[v]=1,vis[v]=1;
				// cout<<v<<endl;
				q.push(v);
				nd.pb(v);
			}
		}
	}
	for(int i:nd)
	{
		for(int v:G[i])
		{
			if(dgr[v]%3==2) d[v]++;
		}
	}
	vector<int> lef;
	for(int i:nd) if(qbq[i]==1) lef.pb(i);
	assert(lef.size()>=2);
	for(int i=1;i<=n;i++) qwq[i]=0;
	int QAQ=lef[0]; qwq[QAQ]=1;
	q.push(QAQ);
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int v:G[u])
		{
			if(dgr[v]%3==2&&!qwq[v])
			{
				// printf("%d %d\n",u,v);
				qwq[v]=1; fa[v]=u;
				q.push(v);
				if(qbq[v]==1)
				{
					vector<int> ans; int tmp=v;
					while(tmp!=QAQ)
					{
						ans.pb(tmp),tmp=fa[tmp];
					}
					ans.pb(QAQ);
					// printf("%d %d\n",(int)ans.size(),(int)nd.size());
					return mp(ans,ans.size()==nd.size());
				}
			}
		}
	}
	assert(0);
}
void END()
{
	OK=0;
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<=n;i++) dgr[i]=0,fa[i]=0,vis[i]=0,ok[i]=0,qwq[i]=0,d[i]=0,qbq[i]=0;
}
int cnt=0;
void work()
{
	cin>>n>>m;
	cnt++;
	if(cnt==159&&tag)
	{
		printf("%d %d\n",n,m);
		for(int i=1;i<=m;i++)
		{
			int x=read(),y=read();
			printf("%d %d\n",x,y);
		}
		return ;
	}
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
		dgr[u]++,dgr[v]++;
	}
	if(tag) return ;
	if(n==1)
	{
		cout<<"NO\n";
		END();
		return ;
	}
	// for(int i=1;i<=n;i++) printf("%d ",dgr[i]); cout<<"\n";
	// return ;
	for(int i=1;i<=n;i++)
	{
		if(dgr[i]%3==0)
		{
			cout<<"YES\n";
			cout<<n-1<<"\n";
			for(int j=1;j<=n;j++) if(j!=i) printf("%d ",j);
			cout<<"\n";
			END();
			return ;
		}
	}
	vector<int> one;
	for(int i=1;i<=n;i++)
	{
		if(dgr[i]%3==1) one.pb(i);
	}
	if(one.size()>1)
	{
		for(int i:one) qwq[i]=1;
		int QAQ=one[0]; vis[QAQ]=1;
		queue<int> q; q.push(QAQ);
		// cout<<QAQ<<endl;
		while(!q.empty())
		{
			int u=q.front(); q.pop();
			for(int v:G[u])
			{
				if(vis[v]) continue;
				if(qwq[v])
				{
					ok[v]=ok[QAQ]=1; int tmp=u;
					while(tmp!=QAQ)
					{
						ok[tmp]=1;
						tmp=fa[tmp];
					}
					int sum=0; for(int i=1;i<=n;i++) if(!ok[i]) sum++;
					if(sum)
					{
						cout<<"YES\n";
						cout<<sum<<"\n";
						for(int i=1;i<=n;i++)
						{
							if(!ok[i]) printf("%d ",i);
						}
						cout<<"\n";
						END();
						return ;
					}
				}
				fa[v]=u,vis[v]=1;
				q.push(v);
			}
		}
		// assert(0);
		// return ;
	}
	// return ;
	for(int i=1;i<=n;i++) fa[i]=vis[i]=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]&&dgr[i]%3==2)
		{
			// cout<<i<<endl;
			dfs(i,0);
			if(OK)
			{
				int sum=0; for(int i=1;i<=n;i++) if(!ok[i]) sum++;
				cout<<"YES\n";
				cout<<sum<<"\n";
				for(int i=1;i<=n;i++)
				{
					if(!ok[i]) printf("%d ",i);
				}
				cout<<"\n";
				END();
				return ;
			}
		}
	}
	for(int i=1;i<=n;i++) fa[i]=vis[i]=0;
	if(one.size()==1)
	{
		int nd=one[0];
		for(int i:G[nd]) qbq[i]=1;
		// cout<<nd<<endl;
		bool QaQ=0;
		vector<pair<vector<int>,int>> v;
		for(int i=1;i<=n;i++)
		{
			// for(int j=1;j<=n;j++) printf("%d ",vis[j]); cout<<"\n";
			if(i==nd) continue;
			if(vis[i]) continue;
			v.pb(getlef(i,nd));
			if(!QaQ&&v.size()==2&&v[0].sec==1&&v[1].sec==1) v.pop_back(),QaQ=1;
			if(v.size()==2)
			{
				ok[nd]=1;
				for(int i:v[0].fir) ok[i]=1;
				for(int i:v[1].fir) ok[i]=1;
				int sum=0; for(int i=1;i<=n;i++) if(!ok[i]) sum++;
				cout<<"YES\n";
				cout<<sum<<"\n";
				for(int i=1;i<=n;i++)
				{
					if(!ok[i]) printf("%d ",i);
				}
				cout<<"\n";
				END();
				return ;
			}
		}
	}
	cout<<"NO\n";
	END();
}
signed main()
{
	int T=read();
	while(T--) work();
	return 0;
}