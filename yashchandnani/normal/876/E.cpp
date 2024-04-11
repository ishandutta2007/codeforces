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
std::vector<int> v[100009];
int chk(int v){
	int ans=v;
	while(v!=0){
		ans+=v%10;
		v/=10;
	}
	return ans;
}
std::vector<int> child[100009];
bool vis[100009];
int a[100009];
bool vis2[100009];
ii comp(std::vector<int>& v1,std::vector<int>& v2){
	rep(i,min(v1.size(),v2.size())){
		if (v1[i]!=v2[i])
		{
			return mp(v1[i],v2[i]);
		}
	}
	if (v1.size()<=v2.size())
	{
		return mp(-1,0);
	}
	else{
		return mp(0,-1);
	}
}
bool cycl(int v){
  if (vis2[v])
  {
    return true;
  }
  vis[v]=true;
  vis2[v]=true;
  rep(i,child[v].size()){
  	if (a[v]==1)
  	{
  		a[child[v][i]]=1;
  	}
    if (vis2[child[v][i]])
    {
      return true;
    }
    if (cycl(child[v][i])==true)
    {
      return true;
    }
  }
  vis2[v]=false;
  return false;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;cin>>n;
  int m;cin>>m;
  
  std::vector<int> v[n];
  {
  int x;cin>>x;
  rep(i,x){
  	int y;cin>>y;
  	v[0].pb(y);
  }}
  rep(i,n-1){
  	int x;cin>>x;
  	rep(j,x){
  		int y;cin>>y;
  		v[i+1].pb(y);
  	}
  	ii z = comp(v[i],v[i+1]);
  	//cout<<z.fi<<" "<<z.se<<endl;
  	//cout<<a[3]<<endl;
  	
  	if (z.se==-1)
  	{
  		cout<<"No";
  		return 0;
  	}
  	if (z.fi==-1)
  	{
  		continue;
  	}
  	if (a[z.fi]==1)
  	{
  		if (a[z.se]==2)
  		{
  			cout<<"No";
  			return 0;
  		}
  		a[z.se]=1;
  	}
  	if (z.fi>z.se)
  	{
  		if ((a[z.fi]==0||a[z.fi]==2)&&(a[z.se]==0||a[z.se]==1))
  		{
  			a[z.fi]=2;
  			a[z.se]=1;
  		}
  		else{
  			cout<<"No";
  			return 0;
  		}
  	}
    child[z.fi].pb(z.se);
  	
  }
  repA(i,1,m){
    if (!vis[i])
    {
      fill(vis2);
      if (cycl(i))
      {
        cout<<"No";
        return 0;
      }
    }
  }
  cout<<"Yes"<<endl;
  std::vector<int> ans;
  int fns=0;
  repA(i,1,m){
  	if (a[i]==2||a[i]==0)
  	{
  		fns++;
  		ans.pb(i);
    	}
  }
  cout<<fns<<endl;
  rep(i,fns){
  	cout<<ans[i]<<" ";
  }
  return 0;
}