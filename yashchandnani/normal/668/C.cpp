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
ld solve(double s,double a){
	
	return (s+double(sqrt(max(0.0,(s*s-4*a)))))/2;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;cin>>n;
  ld a[n+1],b[n+1],sum[n+1]={0},ans[n+1]={0},rts[n+1]={0},sum2[n+1]={0},ans2[n+1]={0},in[n+1]={0};

  rep(i,n) cin>>a[i+1];
  rep(i,n) cin>>b[i+1];
  rep(i,n) rts[i+1] = a[i+1]+b[i+1]+rts[i];
  rep(i,n) in[i+1]=in[i]+a[i+1];
  repA(i,1,n){
  		sum[i]=solve(rts[i],in[i]);
  		//cout<<sum[i]<<endl;
  		sum2[i]=rts[i]-sum[i];
  		ans[i]=sum[i]-sum[i-1];
  		ans2[i]=sum2[i]-sum2[i-1];
  		if (abs(sum[i]*ans2[i]+sum2[i]*ans[i]-ans[i]*ans2[i]-a[i])<0.00000001&&ans[i]>=-0.00000001&&ans2[i]>=-0.000000001)
  		{
  			continue;
  		}
  		else{
  			swap(sum[i],sum2[i]);
  			ans[i]=sum[i]-sum[i-1];
  			ans2[i]=sum2[i]-sum2[i-1];
  		}
  }
  cout<<setprecision(10);
  repA(i,1,n){
  	cout<<ans[i]<<" ";
  }
  cout<<"\n";
  repA(i,1,n){
  	cout<<ans2[i]<<" ";
  }
  return 0;
}