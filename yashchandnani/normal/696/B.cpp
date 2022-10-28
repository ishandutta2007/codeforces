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
ld ans[100009];
std::vector<int> v[100009];
int sz[100009];
void dfs(int x){
	sz[x]=1;
	rep(i,v[x].size()){
		dfs(v[x][i]);
		sz[x]+=sz[v[x][i]];
	}
}
void DFS(int vt){
	rep(i,v[vt].size()){
		ans[v[vt][i]]=ans[vt]+double(sz[vt]-sz[v[vt][i]]-1)/2+1;
		DFS(v[vt][i]);
	}
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;cin>>n;
  rep(i,n-1){
  	int x;cin>>x;
  	v[x-1].pb(i+1);
  }
  ans[0]=1;
  dfs(0);
  DFS(0);
  cout<<setprecision(10);
  rep(i,n){
  	cout<<ans[i]<<" ";
  }

  return 0;
}