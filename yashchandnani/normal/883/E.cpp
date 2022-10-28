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
bool look(string& s,int i){
	rep(j,s.size()){
		if (s[j]==char(int('a')+i))
		{
			return true;
		}
	}
	return false;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;cin>>n;
  string t;cin>>t;
  bool dn[26]={false};
  rep(i,t.size()){
  	if (t[i]!='*')
  	{
  		dn[t[i]-'a']=true;
  	}
  }
  int m;cin>>m;
  std::vector<string> s;
  rep(i,m){
  	string chk;cin>>chk;
  	bool flag =false;
  	rep(j,chk.size()){
  		if (t[j]==chk[j]||(t[j]=='*'&&dn[chk[j]-'a']==false))
  		{
  			
  		}
  		else{
  			flag =true;
  			break;
  		}
  	}
  	if (!flag)
  	{
  		s.pb(chk);
  	}
  }
  int ans=0;
  rep(i,26){
  	if (dn[i])
  	{
  		continue;
  	}
  	bool flag =false;
  	rep(j,s.size()){
  		if (!look(s[j],i))
  		{
  			flag =true;
  			break;
  		}
  	}
  	if (!flag)
  	{
  		ans++;
  	}
  }
  cout<<ans;
  return 0;
}