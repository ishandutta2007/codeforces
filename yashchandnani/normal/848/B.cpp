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

std::vector<ii> v[200000],v2[200000];
std::vector<int> v3[800000];
int start[800000];
ii ans[200000];

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,w,h;cin>>n>>w>>h;
    int x,b,c;
    ii a[n];
    rep(i,n){
    	cin>>x>>b>>c;
    	a[i]=mp(x,b);
    	if (x==1)
    	{
    		v[b].pb(mp(c,i));
    	}
    	else{
    		v2[b].pb(mp(c,i));
    	}
    }
    rep(i,100000){
    	
    	sortA(v[i]);
    	rep(j,v[i].size()){
    		v3[300000+i-v[i][j].fi].pb(v[i][j].se);
    	}

    }
    rep(i,700000){
    	start[i]=v3[i].size();
    }
    repD(i,100000-1,0){
    	sort(v2[i].rbegin(),v2[i].rend());
    	rep(j,v2[i].size()){
    		v3[300000+i-v2[i][j].fi].pb(v2[i][j].se);
    	}

    }
    rep(i,600000){
    		rep(j,v3[i].size()){
	    		ans[v3[i][j]]=a[v3[i][(v3[i].size()-start[i]+j)%(v3[i].size())]];
	    	}
	    
	    
    }
    rep(i,n){
    	if (ans[i].fi==1)
    	{
    		cout<<ans[i].se<<" "<<h<<"\n";
    	}
    	else{
    		cout<<w<<" "<<ans[i].se<<"\n";
    	}
    }
	return 0;
}