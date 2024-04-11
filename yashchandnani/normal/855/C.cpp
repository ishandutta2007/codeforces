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
#define 	 pq(x)			   priority_queue<x,std::vector<x>,compare>
#define 	 rpq(x)			   priority_queue<x,std::vector<x>,Rcompare>

std::vector<int> v[100009];
int n,m,k;
ll ans1[100009][11],ans2[100009][11],ans3[100009][11];
void DFS(int s,int p){
	ll a1[11]={0},a2[11]={0},a3[11]={0};
	bool flag=false;
	rep(i,v[s].size()){
		if(v[s][i]!=p){
			DFS(v[s][i],s);
			if (flag==false)
			{
				rep(j,11){
					a1[j]=ans1[v[s][i]][j];
					a2[j]=ans2[v[s][i]][j];
					a3[j]=ans3[v[s][i]][j];
				}
				flag =true;
			}
			else{
				repD(j,10,0){
					ll chk=0,chk2=0,chk3=0;
					rep(xx,j+1){
						int yy = j-xx;

							ll ch=a1[xx]*ans1[v[s][i]][yy];
							ch%=MOD;
							chk+=ch;
							
							ch= a2[xx]*ans2[v[s][i]][yy];
							ch%=MOD;
							chk2+=ch;
							chk%=MOD;
							chk2%=MOD;
							ch=a3[xx]*ans3[v[s][i]][yy];
							ch%=MOD;
							chk3+=ch;
							chk3%=MOD;
						
					}
					a1[j]=chk;
					a2[j]=chk2;
					a3[j]=chk3;
				}
			}
		}
	}
	if (flag==false)
	{
		ans1[s][0]=m;
		ans2[s][0]=m;
		ans2[s][1]=1;
		ans3[s][0]=k-1;
		return;

	}
	rep(i,11){
		ans1[s][i]=1LL*((k-1)*(a2[i]-a1[i])%MOD)+1LL*(m*a1[i]);
		ans1[s][i]%=MOD;
		ans3[s][i]=1LL*((k-1)*(a2[i])%MOD);
		ans3[s][i]%=MOD;
		if (i==0)
		{
			ans2[s][0]=ans1[s][0];
			continue;
		}
		ans2[s][i]=ans1[s][i]+a3[i-1];
		ans2[s][i]%=MOD;
	}
	

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n>>m;
  rep(i,n-1){
  	int x,y;cin>>x>>y;
  	v[x].pb(y);
  	v[y].pb(x);
  }
  int x;cin>>k>>x;
  m--;
  DFS(1,0);
  ll fns=0;
  
  rep(i,x+1){
  	fns+=ans2[1][i];
  	fns%=MOD;
  }
  cout<<fns<<endl;
  return 0;
}