#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<ll,int> ii;
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
ii parent[100009];int rnk[100009];ll sz[100009];
void make_set (int v) {
	parent[v] = make_pair (v, 0);
	rnk[v] = 0;
}
 
pair<int,int> find_set (int v) {
	if (v != parent[v].first) {
		int len = parent[v].second;
		parent[v] = find_set (parent[v].first);
		parent[v].second += len;
	}
	return parent[v];
}
 
void union_sets (int a, int b,ll l) {
	//cout<<a<<" "<<b<<endl;
	a = find_set(a).first;
	b = find_set(b).first;
	//cout<<a<<" "<<b<<endl;
	if (a != b) {
		if (rnk[a] < rnk[b])
			swap (a, b);
		parent[b] = make_pair (a, 1);
		sz[a]+=sz[b]+l;
		if (rnk[a] == rnk[b])
			++rnk[a];
	}
	else{
		sz[a]+=l;
	}
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m,p,q;cin>>n>>m>>p>>q;
  repA(i,1,n) make_set(i);
  rep(i,m){
  	int a,b;ll l;cin>>a>>b>>l;
  	union_sets(a,b,l);
  }
  rpq(ii) qu;
  bool flag=false;
  ii en=mp(0,0);
  repA(i,1,n){
  	ii x=(find_set(i));int y=x.fi;
  	//cout<<y<<" "<<i<<endl;
  	if (y==i)
  	{
  		//cout<<sz[i]<<" "<<i<<endl;
  		qu.push(mp(sz[i],i));
  		
  	}
  	else {
  		flag =true;
  		en=mp(y,i);
  	}
  }
  //cout<<qu.size()<<endl;
  //cout<<en.fi<<" "<<en.se<<endl;
  if (qu.size()<q)
  {
  	cout<<"NO\n";return 0;
  }
  else if (qu.size()==q)
  {
  	if (flag||p==0)
  	{
  		cout<<"YES\n";
  		rep(i,p){
  			cout<<en.fi<<" "<<en.se<<"\n";
  		}
  		return 0;
  	}
  	else{
  		cout<<"NO\n";return 0;
  	}
  }
  else if (int(qu.size())-p>q)
  {
  	//cout<<qu.size()-p<<endl;
  	cout<<"NO\n";return 0;
  }
  else{
  	cout<<"YES\n";
  	while(qu.size()!=q){
  		ii x,y;x=qu.top();qu.pop();y = qu.top();
  		qu.pop();
  		cout<<x.se<<" "<<y.se<<"\n";
  		if (flag==false)
  		{
  			flag =true;
  			en=mp(x.se,y.se);
  		}
  		sz[x.se]=(x.fi+=y.fi+min(1000000000LL,sz[x.se]+sz[y.se]+1));
  		qu.push(x);
  		p--;
  	}
  	rep(i,p){
  			cout<<en.fi<<" "<<en.se<<"\n";
  		}
  }
  return 0;
}