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
int sz[100009],rnk[100009]; 
ii parent[100009];
void make_set (int v) {
	parent[v] = make_pair (v, 0);
	rnk[v] = 0;
	sz[v]=1;
}
 
pair<int,int> find_set (int v) {
	if (v != parent[v].first) {
		int len = parent[v].second;
		parent[v] = find_set (parent[v].first);
		parent[v].second += len;
	}
	return parent[v];
}
 
void union_sets (int a, int b) {
	a = find_set (a) .first;
	b = find_set (b) .first;
	if (a != b) {
		if (rnk[a] < rnk[b])
			swap (a, b);
		parent[b] = make_pair (a, 1);
		sz[a]+=sz[b];
		if (rnk[a] == rnk[b])
			++rnk[a];
	}
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;cin>>n;
  rep(i,n) make_set(i+1);
  rep(i,n){
  	int p;cin>>p;
  	union_sets(i+1,p);
  }
  bool vis[n+1]={false};
  ll ans=0;
  int mx1=0,mx2=0;
  rep(i,n){
  	int z = find_set(i+1).fi;
  	//cout<<sz[z];
  	if (!vis[z])
  	{
  		//cout<<sz[z];
  		vis[z]=true;
  		ans+=1LL*sz[z]*sz[z];
  		if (sz[z]>mx1)
  		{
  			mx2=mx1;mx1=sz[z];
  		}
  		else if (sz[z]>mx2)
  		{
  			mx2=sz[z];
  		}
  	}
  }
 // cout<<ans;
  cout<<ans+2LL*mx2*mx1;

  return 0;
}