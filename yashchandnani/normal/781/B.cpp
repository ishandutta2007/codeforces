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
int n;
string s[1009][2];
int ans[1009];
set<string> fvl;
void prin(){
	cout<<"YES\n";
	rep(i,n){
		if (ans[i]==0)
		{
			ans[i]=1;
		}
		cout<<s[i][ans[i]-1]<<"\n";
	}
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n;
  rep(i,n){
  	stringstream ss;
  	string x,y;cin>>x>>y;
  	
  	ss<<char(x[0])<<char(x[1])<<char(x[2]);
  	ss<<"\n\n";
  	ss<<char(x[0])<<char(x[1])<<char(y[0])<<"\n\n";
  	ss>>s[i][0];
  	ss>>s[i][1];
  	//cout<<s[i][0]<<" "<<s[i][1]<<endl;
  	rep(j,i){
  		if (s[i][0]==s[j][0]&&s[i][1]==s[j][1])
  		{
  			cout<<"NO";
  			return 0;
  		}
  		else if (s[i][0]==s[j][0])
  		{
  			ans[i]=ans[j]=2;
  			fvl.insert(s[i][1]);fvl.insert(s[j][1]);
  		}

  	}
  }
  bool flag =true;
  while(flag){
  	flag =false;
  	rep(i,n){
  		if (ans[i]==0)
  		{
  			
	  		bool f1=(fvl.find(s[i][0])!=fvl.end());
	  		bool f2=(fvl.find(s[i][1])!=fvl.end());
	  		flag|=(f1|f2);
	  		if (f1&&f2)
	  		{
	  			cout<<"NO";
	  			return 0;
	  		}
	  		else if (f1)
	  		{
	  			ans[i]=2;
	  			fvl.insert(s[i][1]);
	  		}
	  		else if (f1)
	  		{
	  			ans[i]=1;
	  			fvl.insert(s[i][0]);
	  		}
	  	}
  	}
  	if (fvl.size()==n)
  	{
  		break;
  	}
  }
  prin();
  
  return 0;
}