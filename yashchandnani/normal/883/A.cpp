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
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,m,a,d;cin>>n>>m>>a>>d;
  ll t[m];
  rep(i,m) cin>>t[i];
  sort(t,t+m);
  ll max=(d/a)+1;
  ll tm=0;ll typ1=0;
  ll ans=0;
  rep(i,m){
  	//cout<<ans<<" "<<tm<<endl;
  	if (t[i]<=tm)
  	{
  		continue;
  	}
  	if ((tm/a)*a+a>=t[i])
  	{
  		ans++;
  		tm = t[i]+d;
  		typ1 = min(n,tm/a);
  		continue;
  	}
  	else if (t[i]/a>n&&typ1!=n)
  	{
  		ll typ2 = n-typ1;
  		ans+=typ2/max;
  		ans+=(typ2%max?1:0);
  		ll mm = n - typ2%max+1;

  		tm = mm*a+d;
  		typ1= n;
  		i--;
  		continue;
  	}
  	ll typ2 = min(n,t[i]/a);

  	if ((typ2-typ1)%max!=0)
  	{
  		continue;
  	}
  	else{
  		if ((typ2-max+1)*a+d>=t[i])
  		{
  			continue;
  		}
  		ans+=(typ2-typ1)/max;
  		tm = t[i]+d;
  		ans++;
  		typ1=  min(n,tm/a);

  	}
  }
  if (typ1!=n)
  {
  	ll typ2 = n-typ1;
  		ans+=typ2/max;
  		ans+=(typ2%max?1:0);
  }
  cout<<ans;
  return 0;
}