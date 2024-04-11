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
std::vector<ll> ans;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m,q;cin>>n>>m>>q;
  int a[n],b[m];
  ll sa=0,sb=0;
  bool fa=false,fb=false;
  rep(i,n){
  	cin>>a[i];
  	if (fa)
  	{
  		sa-=a[i];
  	}
  	else{
  		sa+=a[i];
  	}
  	fa=!fa;
  }
  rep(i,n){
  	cin>>b[i];
  	if (!fb)
  	{
  		sb-=b[i];
  	}
  	else{
  		sb+=b[i];
  	}
  	fb=!fb;

  }
  ans.pb(((sa+sb)));
  rep(i,m-n){
  	cin>>b[i+n];
  	if (!fb)
  	{
  		sb-=b[i+n];
  		if (n%2==0)
  		{
  			sb+=b[i];
  		}
  		else{
  			sb-=b[i];
  		}
  	}
  	else{
  		sb+=b[i+n];
  		if (n%2!=0)
  		{
  			sb+=b[i];
  		}
  		else{
  			sb-=b[i];
  		}
  	}
  	sb*=-1;
  	ans.pb(((sa+sb)));

  }
  sortA(ans);
  ll shf=0;
  int ix  = lower_bound(ans.begin(),ans.end(),shf)-ans.begin();
  if (ix!=0&&ix!=m-n+1)
  {
  	cout<<min(abs(ans[ix]-shf),abs(ans[ix-1]-shf))<<"\n";
  }
  else if (ix==0)
  {
  	cout<<abs(ans[ix]-shf)<<"\n";
  }
  else{
  	cout<<abs(ans[ix-1]-shf)<<"\n";
  }
  rep(i,q){
  	int st,en,ch;
  	cin>>st>>en>>ch;
  	st=st%2;
  	en=en%2;
  	if (st==en)
  	{
  		if (st==1)
  		{
  			shf-=ch;
  		}
  		else{
  			shf+=ch;
  		}
  	}
  	
  int ix  = lower_bound(ans.begin(),ans.end(),shf)-ans.begin();
  if (ix!=0&&ix!=m-n+1)
  {
  	cout<<min(abs(ans[ix]-shf),abs(ans[ix-1]-shf))<<"\n";
  }
  else if (ix==0)
  {
  	cout<<abs(ans[ix]-shf)<<"\n";
  }
  else{
  	cout<<abs(ans[ix-1]-shf)<<"\n";
  }
  }
  return 0;
}