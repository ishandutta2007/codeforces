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
int ans[109][109];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,q;cin>>n>>q;
  int ans[n+1],ans2[n+1]={0};
  ans[1]=1;
  ans[2]=2;
  rep(i,q){
  	int t;cin>>t;
  	if (t==1)
  	{
  		int x;cin>>x;
  		ans[1]+=x;
  		ans[2]+=x;
  		ans[1]%=n;
  		ans[2]%=n;
  	}
  	else{
  		if (ans[1]%2==0)
  		{
  			ans[1]--;ans[2]++;
  		}
  		else{
  			ans[1]++;
  			ans[2]--;
  		}
  	}
  }
  //cout<<ans[2]<<endl;
  repA(i,1,n){
  	if (i%2==1)
  	{
  		ans2[(((ans[1]+i-1)%n)+n-1)%n+1]=i;
  	}
  	else{
  		ans2[((ans[2]+i-2)%n+n-1)%n+1]=i;
  	}
  }
  repA(i,1,n){
  	cout<<ans2[i]<<" ";
  }
  
  return 0;
}