#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
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
std::map<int,int> my[300009];
int ans[300009];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m;cin>>n>>m;
  iii edges[m];
  rep(i,m){
  	int u,v,w;cin>>u>>v>>w;
  	edges[i]=mp(w,mp(u,v));
  	
  }

  sort(edges,edges+m);
  int ans=1;
  rep(i,m){
  	int v = edges[m-1-i].se.se;
  	int u = edges[m-1-i].se.fi;
  	int w = edges[m-1-i].fi;
  	mit it = my[v].upper_bound(w);
  	mit it2 = my[u].lower_bound(w);
  	int nxt=1;
  	if (it!=my[v].end())
  	{
  		nxt += it->se;
  	}
  	if (it2==my[u].end()||it2->se<nxt)
  	{
  		//cout<<i<<endl;
  		my[u][w]=nxt;
  		ans=max(ans,nxt);
  	}

  
  }

  cout<<ans;
  return 0;
}