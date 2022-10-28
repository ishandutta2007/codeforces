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

ll lca(ll x,ll y){
	if (x<y)
	{
		swap(x,y);
	}
	int i =0,j=0;
	while(1LL<<i<=y) i++;
	while(1LL<<j<=x) j++;
	rep(k,j-i) x=x>>1;
	while(y!=x){
		y=y>>1;
		x=x>>1;
	}
	return x;
}
int solve(ll a,ll b,ll  x,ll y){
	ll l =lca(a,x);
	if (b<y)
	{
		swap(b,y);
	}
	if (lca(b,y)==y&&lca(b,l)==b)
	{
		int ans=0;
		while(l!=b){
			l=l>>1;
			ans++;
		}
		return ans;
	}

	else return 0;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q;cin>>q;
  std::vector<pair<int,pair<ll,ll> > > v;
  rep(i,q){
  	
  	int t;cin>>t;
  	if (t==1)
  	{
  		ll x,y,z;cin>>x>>y>>z;v.pb(mp(z,mp(x,lca(x,y))));v.pb(mp(z,mp(y,lca(x,y))));
  		//cout<<q<<" "<<v.size()<<endl;
  	}
  	else{
  		ll u,vt;cin>>u>>vt;ll l=lca(u,vt);
  		ll ans=0;
  		//cout<<v.size()<<endl;
  		rep(i,v.size()){
  			//cout<<solve(u,l,v[i].se.fi,v[i].se.se)<<endl;
  			//cout<<v[i].se.fi<<" "<<v[i].se.se<<endl;
  			ans+=1LL*v[i].fi*solve(u,l,v[i].se.fi,v[i].se.se);
  			ans+=1LL*v[i].fi*solve(vt,l,v[i].se.fi,v[i].se.se);
  			//cout<<ans<<endl;
  		}
  		cout<<ans<<"\n";

  	}
  }

  return 0;
}