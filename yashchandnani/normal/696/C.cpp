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
ll solve(ll x,ll y){
	if (x==0)
	{
		return 1;
	}
	ll ans=1;
	if (x%2)
	{
		ans=y;
	}
	ll z = solve(x/2,y);
	ans*=z;
	ans%=MOD;
	ans*=z;
	ans%=MOD;
	return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 int m = 333333336;
 int n;cin>>n;
 ll x,y=2;
 bool odd=false;
 rep(i,n){
 	ll z;cin>>z;
 	y=solve(z,y);
 	y%=MOD;
 	if (z%2==0)
 	{
 		odd=true;
 	}
 }
 y*=500000004;
 y%=MOD;
 if (odd==false)
 {
 	x=y-1;

 }
 else{
 	x=y+1;
 }
 x*=333333336;
 x%=MOD;
 cout<<x<<"/"<<y;


  return 0;
}