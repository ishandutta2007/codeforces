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

#define      each(it,s)        for(sit it = s.begin(); it != s.end(); ++it)
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
    if(lhs.fi<rhs.fi||(lhs.fi==rhs.fi)&&(lhs.se<rhs.se)) return true;
    else return false;
  }
};
std::vector<vi> a,seet,ans;
vector<ii> sttoi[1000009];
set<int> ss1[1000009],ss2[1000009];
int n,m;
std::vector<ii> row[1000009];
std::vector<ii> col[1000009];
std::vector<int> edges[1000009];
bool vis[1000009];
void DFS(int x,int i,int j){
	int z = i*m+j;
	vis[z]=true;
	seet[i][j]=x;
	sttoi[x].pb(mp(i,j));
  if (ss1[x].find(i)==ss1[x].end())
  {
    ss1[x].insert(i);
  }
  if (ss2[x].find(j)==ss2[x].end())
  {
    ss2[x].insert(j);
  }
	rep(i,edges[z].size()){
		if (!vis[edges[z][i]])
		{
			int aa = edges[z][i]/m;int bb = edges[z][i]%m;
			DFS(x,aa,bb);
		}
	}
	

}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t st =time(0);
  cin>>n>>m;
  rpq(ii) q;
  rep(i,n){
  	std::vector<int> v(m,0);
  	seet.pb(v);
  	ans.pb(v);
  	rep(j,m){
  		int x;cin>>x;
  		v[j]=x;
  		q.push(mp(x,i*m+j));
  		row[i].pb(mp(x,j));col[j].pb(mp(x,i));
  	}
  	a.pb(v);
  }
  rep(i,n) {
    sortA(row[i]);
    rep(j,m-1){
      if (row[i][j].fi==row[i][j+1].fi)
      {
        edges[i*m+row[i][j].se].pb(i*m+row[i][j+1].se);
        edges[i*m+row[i][j+1].se].pb(i*m+row[i][j].se);
      }
    }
  }
  rep(i,m) {
    sortA(col[i]);
    rep(j,n-1){
      if (col[i][j].fi==col[i][j+1].fi)
      {
        edges[i+col[i][j].se*m].pb(i+col[i][j+1].se*m);
        edges[i+col[i][j+1].se*m].pb(i+m*col[i][j].se);
      }
    }
  }
  int count =1;
  rep(i,n){
  	rep(j,m){
  		if (seet[i][j]==0)
  		{
  			//cout<<i<<" "<<j<<endl;
  			DFS(count,i,j);
  		
  			count++;
  		}
  	}
  }
  
  int ans[n][m];
  fill(ans);
  int r[n]={0},c[m]={0};
  while(!q.empty()){
  	ii z = q.top();
  	int x = z.fi,i=z.se/m,j=z.se%m;
  	int s = seet[i][j];q.pop();
  	int st=0;
    //cout<<i<<" "<<j<<endl;
  	if (ans[i][j]==0)
  	{
  		each(it,ss1[s]){
  			int aa = *it;
  		//cout<<aa<<endl;
  			if ((a[aa][r[aa]]<a[i][j]))
  			{
  				st=max(st,ans[aa][r[aa]]);
  			}
  			if ((a[aa][r[aa]]==a[i][j]))
  			{
  				st=max(st,ans[aa][r[aa]]-1);
  			}
  			
  		}
  		each(it,ss2[s]){
  			int ab = *it;
        //cout<<ab<<endl;
  			if ((a[c[ab]][ab]<a[i][j]))
  			{
  				st=max(st,ans[c[ab]][ab]);
  			}
  			if ((a[c[ab]][ab]==a[i][j]))
  			{
  				st=max(st,ans[c[ab]][ab]-1);
  			}
  		}
  		st++;
  		//cout<<i<<" "<<j<<" "<<st<<endl;
  		rep(jj,sttoi[s].size()){
  			int aa = sttoi[s][jj].fi;
  			int ab = sttoi[s][jj].se;
  			ans[aa][ab]=st;
  			r[aa]=ab;
  			c[ab]=aa;
  		}
  	}
  }
  rep(i,n){
  	rep(j,m){
  		cout<<ans[i][j]<<" ";
  	}
  	cout<<"\n";
  }
  clock_t end=time(0);
  cout<<setprecision(10);
  //cout<<(double(end-st))/CLOCKS_PER_SEC<<endl;
  return 0;
}