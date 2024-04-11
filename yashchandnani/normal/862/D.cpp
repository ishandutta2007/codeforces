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
void chng(char*s,int l,int m){
	char c;
	if (s[l]=='0')
	{
		c='1';
	}
	else c='0';
	repA(i,l,m){
		s[i]=c;
	}
}
void query(char* s,int n){
	cout<<"? ";
	rep(i,n) cout<<s[i];
	cout<<endl;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;cin>>n;
  int c1,c0;
  cout<<"? ";
  rep(i,n){
  	cout<<1;
  }
  cout<<endl;
  cin>>c1;
  c1=n-c1;
  c0=n-c1;
  cout<<"? ";
  rep(i,n-1){
  	cout<<1;
  }
  cout<<0<<endl;
  char s[n];
  int x;
  cin>>x;
  x=n-x;
  if (x>c1)
  {
  	s[n-1]='1';
  	rep(i,n-1){
  		s[i]='1';
  	}
  	x=c1;
  }
  else{
  	s[n-1]='0';
  	rep(i,n-1) s[i]='0';
  	x=c0;
  }
 
  int l=0,r=n-2;
  while(l<r){
  	int m = (l+r)/2;
  	chng(s,l,m);
  	query(s,n);
  	int upd;cin>>upd;
  	upd=n-upd;
  	chng(s,l,m);
  	if (upd==x+m-l+1)
  	{
  		l=m+1;
  	}
  	else{
  		r=m;
  	}

  }
  if (s[n-1]=='1')
  {
  	cout<<"! "<<n<<" "<<l+1;
  }
  else{
  	cout<<"! "<<l+1<<" "<<n;
  }
  return 0;
}