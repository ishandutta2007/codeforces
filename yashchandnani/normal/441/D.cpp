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
ii parent[100009];int rnk[100009];
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
 
void union_sets (int a, int b) {
	//cout<<a<<" "<<b<<endl;
	a = find_set(a).first;
	b = find_set(b).first;
	//cout<<a<<" "<<b<<endl;
	if (a != b) {
		if (rnk[a] < rnk[b])
			swap (a, b);
		parent[b] = make_pair (a, 1);
		
		if (rnk[a] == rnk[b])
			++rnk[a];
	}
}
std::vector<int> s[100009];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;cin>>n;
  int pp[n+1],pos[n+1];
  repA(i,1,n){
  	make_set(i);
  }
  rep(i,n) {
  	cin>>pp[i+1];
  	pos[pp[i+1]]=i+1;
  	union_sets(i+1,pp[i+1]);
  }
  int count=0;std::vector<int> v;

  repA(i,1,n){
  	int y =find_set(i).fi;
  	if (y==i)
  	{
  		v.pb(i);
  		count++;
  	}
  	else{
  		s[y].pb(i);
  	}
  }
  int m;cin>>m;
  m=n-m;
  //cout<<count<<" "<<m<<endl;
  if (count>=m)
  {
  	cout<<count-m<<"\n";
  	rep(k,count-m){
  		int i=1,j=2;
  		while(find_set(i).fi==find_set(j).fi){
  			j++;
  		}
  		union_sets(i,j);
  		cout<<i<<" "<<j<<" ";
  	}
  	return 0;
  }
  else{
  	m-=count;
  	cout<<m<<"\n";
  	int i=1;
  	while(m){
  		
  		if (pos[i]!=i)
  		{
  			int j =i,mn=pos[i];
  			//cout<<i<<endl;
  			while(pos[j]!=i){
  				//cout<<j<<endl;
  				j=pos[j];
  				mn=min(mn,j);
  			}
  			cout<<i<<" "<<mn<<" ";
  			int x = pp[i],y=pp[mn];
  			pos[x]=mn;pos[y]=i;
  			pp[mn]=x;
  			pp[i]=y;
  			m--;

  		}
  		else{
  			i++;
  		}

  	}

  }

  return 0;
}