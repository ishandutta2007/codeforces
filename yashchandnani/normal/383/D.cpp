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
#define SZ(x) ((int) (x).size())
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
int dp[1001][40001];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  fill(dp);
	int n;cin>>n;
	int a[n];
	rep(i,n) cin>>a[i+1]; 
	ll ans =0;
	repA(i,1,n){
		dp[i][20000-a[i]]=dp[i][20000+a[i]]=1;
		repA(j,10000,30000){
			dp[i][j] += dp[i-1][j-a[i]]+dp[i-1][j+a[i]];
			dp[i][j]%=MOD;
		}
		//cout<<a[i]<<endl;
		ans+=dp[i][20000];
		ans%=MOD;
		//cout<<ans<<endl;
	}
	cout<<ans;

  return 0;
}