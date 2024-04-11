#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int> > iii;
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
std::vector<iii> v1,v2;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,s;cin>>n>>s;
  rep(i,n){
  	int x,y,z;cin>>x>>y>>z;
  	if (y>z)
  	{
  		v1.pb(mp(y-z,mp(x,z)));
  	}
  	else{
  		v2.pb(mp(z-y,mp(x,y)));
  	}
  }
  sortD(v1);
  sortD(v2);
  ll ans =0;
  ll a1 = 0,a2=0,slic=0;
  int ix=0;
  rep(i,v1.size()){
  	
  	if (slic+v1[i].se.fi<s)
  	{
  		a2+=1LL*v1[i].se.fi*v1[i].se.se;
  		a1+=1LL*v1[i].se.fi*v1[i].fi;
  		slic+=v1[i].se.fi;
  	}
  	else{
  		a2+=1LL*(s-slic)*v1[i].se.se;
  		a1+=1LL*(s-slic)*v1[i].fi;
  		v1[i].se.fi-=(s-slic);
  		ans+=a1+a2;
  		ans+=1LL*(v1[i].se.fi/s)*s*(v1[i].fi+v1[i].se.se);
  		v1[i].se.fi%=s;
  		a1=0;
  		a2=0;
  		slic=0;
  		ix=i;
  		i--;
  	}
  }
  ll a12 = 0,a22=0,slic2=0;
  int ix2=0;
  rep(i,v2.size()){
  	
  	if (slic2+v2[i].se.fi<s)
  	{
  		a22+=1LL*v2[i].se.fi*v2[i].se.se;
  		a12+=1LL*v2[i].se.fi*v2[i].fi;
  		slic2+=v2[i].se.fi;
  	}
  	else{
  		a22+=1LL*(s-slic2)*v2[i].se.se;
  		a12+=1LL*(s-slic2)*v2[i].fi;
  		v2[i].se.fi-=(s-slic2);
  		ans+=a12+a22;
  		ans+=1LL*(v2[i].se.fi/s)*s*(v2[i].fi+v2[i].se.se);
  		v2[i].se.fi%=s;
  		a12=0;
  		a22=0;
  		slic2=0;
  		ix2=i;
  		i--;
  	}
  }
  if (slic+slic2<=s)
  {
  		ans+=max(a1+a2+a22,a2+a12+a22);
  }
  else{
  	ans+=a1+a2+a12+a22;
  }
  cout<<ans;

  return 0;
}