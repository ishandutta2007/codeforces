#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld; 

typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _  %  MOD
#define __ %= MOD

#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.rbegin(), v.rend())
#define      fill(a)           memset(a, 0, sizeof (a))

#define      rep(i, n)         for(int i = 0; i < (n); ++i)
#define      repA(i, a, n)     for(int i = a; i <= (n); ++i)
#define      repD(i, a, n)     for(int i = a; i >= (n); --i)
#define 	 pq(x)			   priority_queue<x,std::vector<x>,compare>
#define 	 rpq(x)			   priority_queue<x,std::vector<x>,Rcompare>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define fbo find_by_order
#define ook order_of_key
struct Rcompare
{
  bool operator()(ii lhs,ii rhs){
    return lhs.fi>rhs.fi;
  }
};
struct compare
{
  bool operator()(ii lhs,ii rhs){
    return lhs.fi<rhs.fi;
  }
};
std::vector<int> dir[300009];
std::vector<ii> undir[300009];
int ans[300009];
int ix[300009];
bool vis[300009];
void DFS(int s){
	if (vis[s])
	{
		return;
	}
	vis[s]=true;
	rep(i,dir[s].size()){
		if (!vis[dir[s][i]])
		{
			DFS(dir[s][i]);
		}
	}
	rep(i,undir[s].size()){
		if (!vis[undir[s][i].fi])
		{
			if (ix[undir[s][i].se]==undir[s][i].fi)
			{
				ans[undir[s][i].se]=1;
			}
			DFS(undir[s][i].fi);
		}
	}
}
void dfss(int s){
	if (vis[s])
	{
		return;
	}
	vis[s]=true;
	rep(i,dir[s].size()){
		if (!vis[dir[s][i]])
		{
			dfss(dir[s][i]);
		}
	}
	rep(i,undir[s].size()){
		if (!vis[undir[s][i].fi])
		{
			if (ix[undir[s][i].se]==undir[s][i].fi)
			{
				ans[undir[s][i].se]=1;
			}
			else{
				ans[undir[s][i].se]=0;
			}
			
		}
	}
	
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m,s;cin>>n>>m>>s;
  int count =0;
  rep(i,m){
  	int t,u,v;cin>>t>>u>>v;
  	if (t==1)
  	{
  		dir[u].pb(v);
  	}
  	else{
  		undir[u].pb(mp(v,count));
  		undir[v].pb(mp(u,count));
  		ix[count]=u;
  		count++;
  	}
  }
  DFS(s);
  int ans1=0;
 repA(i,1,n){
 	if (vis[i])
 	{
 		ans1++;
 		vis[i]=false;
 	}
 }
 cout<<ans1<<"\n";
 rep(i,count){
 	if (ans[i]==1)
 	{
 		cout<<"-";

 	}
 	else{
 		cout<<"+";
 	}
 }
 cout<<"\n";
 fill(vis);
 dfss(s);ans1=0;
 repA(i,1,n){
 	if (vis[i])
 	{
 		ans1++;
 		vis[i]=false;
 	}
 }
 cout<<ans1<<"\n";
 rep(i,count){
 	if (ans[i]==0)
 	{
 		cout<<"-";

 	}
 	else{
 		cout<<"+";
 	}
 }
  return 0;
}