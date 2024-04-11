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
	int n,k,x;
	std::priority_queue<ii,vector<ii> , mycomparison > q;
	cin>>n;
	string s[n];
	int l[n];
	rep(i,n){
		cin>>s[i];
		l[i]=s[i].size();
		cin>>k;
		rep(j,k){
			cin>>x;
			q.push(mp(x,i));
		}
	}
	char c[3000000];
	rep(i,3000000){
		c[i]='?';
	}
	int sz=0;
	
	while(!q.empty()){
		
		if ((q.top()).fi+l[(q.top()).se]-1<=sz)
		{
			q.pop();
			continue;
		}
		if (sz<(q.top()).fi)
		{
			sz=(q.top()).fi-1;
		}
		repA(i,sz,(q.top()).fi+l[(q.top()).se]-2){
			c[i]=s[(q.top()).se][i+1-(q.top()).fi];
			
		}
		sz=(q.top()).fi+l[(q.top()).se]-1;
		q.pop();
		

	}
	rep(i,sz){
		if (c[i]!='?')
		{
			cout<<c[i];
		}
		else{
			cout<<"a";
		}
	}
	return 0;
}