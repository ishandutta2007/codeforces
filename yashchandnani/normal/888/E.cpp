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

#define      each(it,s)        for(sit it = s.begin(); it != s.end(); ++it)
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
std::vector<int> v,v1,v2;
std::vector<ll> chk1,chk2;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m;cin>>n>>m;
  int a[n];
  rep(i,n){
  	int x;cin>>x;
  	if (x%m==0)
  	{
  		n--;i--;continue;
  	}
  	else {
  		v.pb(x);
  	}
  }
  int sz1 = n/2;
  int sz2 = n-sz1;
  rep(i,sz1){
  	v1.pb(v[i]);
  }
  repA(i,sz1,n-1){
  	v2.pb(v[i]);
  }
  chk1.pb(0);
  chk2.pb(0);
  rep(i,sz1){
  	int sz = chk1.size();
  	rep(j,sz){
  		chk1.pb(chk1[j]+v1[i]);
  	}
  }
  rep(i,sz2){
  	int sz = chk2.size();
  	rep(j,sz){
  		chk2.pb(chk2[j]+v2[i]);
  	}
  }
  set<int> s1,s2;
  rep(i,chk1.size()){
  	s1.insert(chk1[i]%m);
  }
  rep(i,chk2.size()){
  	s2.insert(chk2[i]%m);
  }
  sit mx = s2.end();mx--;
  int ye = *mx;
  ll ans =0;
 // cout<<ye<<endl;
  each(it,s1){
  	ll z = *it;
  	ans = max(ans,(z+ye)%m);
  	int zz = m-1-z;
  	sit it2 = s2.upper_bound(zz);
  	it2--;
  	ans = max(ans,1LL*(*it+*it2)%m);
  }
  cout<<ans;
  return 0;
}