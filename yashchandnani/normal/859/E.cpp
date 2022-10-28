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
std::vector<int> v[200009];
bool terr[200009],vis[200009];
int p[200009],p2[200009],rnk[200009];

int find(int x){
	while(p[x]!=0){
		x=p2[x];
	}
	return x;
}
int DFS(int x){
	int ans=1;
	rep(i,v[x].size()){
		
			ans+=DFS(v[x][i]);
		
	}
	return ans;
}
void uni(int x,int y){
	x=find(x);
	y=find(y);
	if (rnk[x]>rnk[y])
	{
		p2[y]=x;
		
	}
	else{
		p2[x]=y;
		if (rnk[x]==rnk[y])
		{
			rnk[x]++;
		}
	}
}
int mark(int x){
	int ans=0;
	while(x!=0){
		terr[x]=true;
		x=p[x];
		ans++;
	}
	return ans;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;cin>>n;
  
  int cir=0;

  ll ans=1;
  rep(i,n){
  	int x,y;

  	cin>>x>>y;
  	vis[x]=true;
  	
  	if (find(x)==find(y))
  	{
  		cir=mark(x);
  		cir+=mark(y);
  		if(x!=y) ans*=2;
  		ans%=MOD;
  	}
  	else{
  		
  		
  		uni(x,y);
  		p[x]=y;
  	}
  	vis[x]=true;
  	
  	v[y].pb(x);
  }
  rep(i,200009){
  	if (vis[i]==false&&terr[i]==false&&v[i].size()!=0)
  	{
  		ans*=DFS(i);
  		ans%=MOD;
  	}
  }
  cout<<ans<<endl;



  return 0;
}