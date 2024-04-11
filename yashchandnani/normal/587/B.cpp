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

#define      each(it,s)        for(mit it = s.begin(); it != s.end(); ++it)
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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,l,k;cin>>n>>l>>k;
  ll kk = k;
  int a[n];
  std::vector<int> v;
  map<int,int> m1,m2;
  rep(i,n) {
  	cin>>a[i];m1[a[i]]++;
  	if(i<l%n) m2[a[i]]++;
  }
  k = min(k,l/n);
  ll ans[n+1][k+1];
  ll sum =0;
  ll pre[n+1][k+1];
  fill(ans);fill(pre);
  int j =1;
  repA(i,1,k){
  	j =1;
  	each(it,m1){
  		ans[j][i] = 1LL*it->se*(pre[j][i-1]+1);
  		pre[j][i] = pre[j-1][i]+ans[j][i];
  		sum+=ans[j][i];
  		sum%=MOD;ans[j][i]%=MOD;pre[j][i]%=MOD;
  		//cout<<pre[j][i]<<endl;
  		j++;
  	}
  	//cout<<sum<<endl;
  }
  ll z  = l/n - k;
  if(z>0){
	  	z%=MOD;
	  sum+=(z*pre[j-1][k])%MOD;
	  sum%=MOD;
	}
	mit it2 = m2.begin();
	int i =1;
	each(it,m1){
		
		if((it->fi)==(it2->fi)){
			if(kk!=k) sum+=1LL*it2->se*(pre[i][k]+1);
			else sum+=1LL*it2->se*(pre[i][k-1]+1);
			sum%=MOD;
		//	cout<<it2->se<<" "<<pre[i][k]<<endl;
			it2++;
		}
		i++;
	}
  cout<<sum;



  return 0;
}