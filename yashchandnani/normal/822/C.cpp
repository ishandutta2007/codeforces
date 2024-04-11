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





int main()
{
	int n,x;
	cin>>n>>x;
	std::vector<ii> v1[200007],v2[200007];
	ll ans[x];
	memset(ans,0,sizeof(ans));
	rep(i,n){
		int a,b,c;
		cin>>a>>b>>c;
		if (b-a+1>=x)
		{
			continue;
		}
		
		v1[a].pb(mp(b-a+1,c));
		v2[b].pb(mp(b-a+1,c));
	}

	ll mn=2000000009;
	repD(i,200001,0){
		rep(j,v2[i].size()){
			if (ans[x-v2[i][j].fi]!=0)
			{
				mn=min(mn,ans[x-v2[i][j].fi]+v2[i][j].se);
				
				
			}
			
		}
		rep(j,v1[i].size()){
			if(ans[v1[i][j].fi]!=0) ans[v1[i][j].fi]=ans[v1[i][j].fi]<v1[i][j].se?ans[v1[i][j].fi]:v1[i][j].se;
			else ans[v1[i][j].fi]=v1[i][j].se;
		}
	}
	
	if(mn<2000000009)
		cout<<mn<<endl;
	else{
		cout<<-1<<endl;
	}

	return 0;
}