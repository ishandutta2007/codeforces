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

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define fbo find_by_order
#define ook order_of_key

class mycomparison{
    bool reverse;
  public:
    mycomparison(const bool &revparam=true) {reverse=revparam;}
    bool operator() (const ii &lhs, const ii &rhs) const {
      if (reverse) return (lhs.fi>rhs.fi);
      else         return (lhs.fi<rhs.fi);
    }
};

int main()
{
	int n,k;
	cin>>n>>k;
	int z=(n-1)/k;
	int ans=2*z;
	if ((n-1)%k==1)
	{
		cout<<ans+1<<endl;
	}
	else if ((n-1)%k==0)
	{
		cout<<ans<<endl;
	}
	else{
		cout<<ans+2<<endl;
	}
	rep(i,k){
		cout<<1<<" "<<i+2<<endl;
	}
	repA(i,k+2,n){
		cout<<i<<" "<<i-k<<endl;
	}

	return 0;
}