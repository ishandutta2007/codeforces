//teja349
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);   
vector<vii> vec(323456);
vector<vi> adj(312345);
int lev[312345],maxdepth[312345];
ll bigg=0;
int jaja[312345][19];
vi wow;
int n;
int dfs(int cur,int par){
	int i;
	lev[cur]=1;
	maxdepth[cur]=0;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par){
			dfs(adj[cur][i],cur);
			lev[cur]=max(lev[adj[cur][i]]+1,lev[cur]);
		
			maxdepth[cur]=max(maxdepth[adj[cur][i]],maxdepth[cur]);
		}
	}


	int depth=2;
	int previ=n,u,val;
	ll j;
	int ans,low,mid,high;
	vec[cur].pb(mp(1,n));
	jaja[cur][1]=n;
	vii::iterator it;
	int iter=0;
	while(1){
		//iter++;
		
		wow.clear();
		
		rep(j,adj[cur].size()){
			u=adj[cur][j];
			if(u==par)
				continue;
			it=upper_bound(vec[u].begin(),vec[u].end(),mp(depth-1,-1));
			if(it==vec[u].end())
				continue;
			
			wow.pb(it->ss);
		}
		
		sort(all(wow));
		int low=2;
		int high=n-1;
		ans=-1;
		while(low<=high){
			mid=(low+high)/2;
			val=wow.end()-lower_bound(all(wow),mid);
			if(val>=mid){
				ans=mid;
				low=mid+1;
			}
			else{
				high=mid-1;
			}
		}
		if(ans==-1){
			maxdepth[cur]=max(depth-1,maxdepth[cur]);
			break;
		}
		// if(ans==previ){
		// 	vec[cur].erase(vec[cur].end()-1);
		// }
		jaja[cur][depth]=ans;
		vec[cur].pb(mp(depth,ans));
		previ=ans;
		depth++;
	}
	val=maxdepth[cur]+1;
	rep(i,adj[cur].size()){
		u=adj[cur][i];
		if(u==par)
			continue;
		f(j,1,val){
			jaja[cur][j]=max(jaja[cur][j],jaja[u][j]);	
		}

	}
	//jaja[cur][val]=1;
	f(j,1,val-1){

		bigg+=j*(jaja[cur][j]-jaja[cur][j+1]);

	}
	j=val-1;
	//cout<<cur<<" "<<maxdepth[cur]<<endl;
	bigg+=j*(jaja[cur][j]-1);

	


	return 0;

}
int main(){
    std::ios::sync_with_stdio(false);
    //int n;
    cin>>n;
    int i,u,v;
    rep(i,n-1){
    	cin>>u>>v;
    	u--;
    	v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    dfs(0,-1);
    //bigg=0;
    rep(i,n){
    	bigg+=lev[i];
    }
    cout<<bigg<<endl;
    return 0;  
    
}