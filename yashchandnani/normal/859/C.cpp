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
#define      sortD(v)          sort(v.begin(), v.end(), greater<auto>())
#define      fill(a)           memset(a, 0, sizeof (a))

#define      rep(i, n)         for(int i = 0; i < (n); ++i)
#define      repA(i, a, n)     for(int i = a; i <= (n); ++i)
#define      repD(i, a, n)     for(int i = a; i >= (n); --i)
#define 	 pq(x)			   priority_queue<x,std::vector<x>,compare>
#define 	 rpq(x)			   priority_queue<x,std::vector<x>,compare>
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
  int n;cin>>n;
  if (n==1)
  {
  	int x;cin>>x;
  	cout<<0<<" "<<x<<endl;
  	return 0;
  }
  else if (n==2)
  {
  	int x,y;cin>>x>>y;
  	cout<<min(x,y)<<" "<<max(x,y)<<endl;
  	return 0;
  }
  int a[n],sum[n];
  rep(i,n){
  	cin>>a[i];
  	if (i!=0)
  	{
  		sum[i]=sum[i-1];
  	}
  	
  }
  int ans[n];
  ans[n-1]=a[n-1];
  sum[n-1]=a[n-1];
  repD(i,n-2,0){
  	sum[i]=sum[i+1]+a[i];
  	ans[i]=max(ans[i+1],sum[i+1]-ans[i+1]+a[i]);
  }
  cout<<sum[0]-ans[0]<<" "<<ans[0]<<endl;
  return 0;
}