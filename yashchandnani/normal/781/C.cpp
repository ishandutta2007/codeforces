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
std::vector<int> edges[200009];
bool vis[200009];
int ans[400009];
int timee =0;
void DFS(int v){
	vis[v]=true;
	ans[timee]=v;
	timee++;
	rep(i,edges[v].size()){
		if (!vis[edges[v][i]])
		{
			DFS(edges[v][i]);
			ans[timee]=v;
			timee++;
		}
	}
	
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m,k;cin>>n>>m>>k;
  rep(i,m){
  	int x,y;cin>>x>>y;
  	edges[x].pb(y);
  	edges[y].pb(x);
  }
  DFS(1);
  int mxx = (2*n+k-1)/k;
  int tot=0;
  rep(i,k){
  	int sz=min(mxx,(timee-tot));
  	if (sz==0)
  	{
  		sz++;
  		tot--;
  	}
  	cout<<sz<<" ";
  	rep(j,sz){
  		cout<<ans[tot]<<" ";
  		tot++;
  	}

  	
  	cout<<"\n";
  }
  return 0;
}