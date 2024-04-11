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
  int n;cin>>n;
  string s[n];
  int count =0;
  rep(i,n){
  	cin>>s[i];
  	repA(j,0,s[i].size()-1){
  		
  		if (j!=0&&s[i][j]=='h'&&s[i][j-1]=='k')
  		{
  			s[i].erase(j-1,1);j-=2;

  			//cout<<s[i]<<endl;
  		}
  		else if (s[i][j]=='u')
  		{
  			s[i].insert(j+1,"o");
  			s[i][j]='o';
  		}
  	}
  	rep(j,i){
  		if (s[i]==s[j])
  		{
  			//cout<<i<<endl;
  			count++;
  			break;
  		}
  	}
  }
  cout<<n-count;
  return 0;
}