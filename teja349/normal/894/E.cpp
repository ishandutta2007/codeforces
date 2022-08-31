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
#define inf (1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);   
int tim=2;
int cnter=2;
vector<vi> adj(1234567),revadj(1234567),strong(1234567);
vector<vl> boo(1234567);
int comp[1234567],visit[1234567],post[1234567];
int u[1234567],v[1234567];
ll w[1234567];
ll haha[1234567];
//map<pii,ll> edge;
vi vec;
int dfs(int cur){
	visit[cur]=1;
	int i;
	rep(i,adj[cur].size()){
		if(!visit[adj[cur][i]])
			dfs(adj[cur][i]);
	}
	post[cur]=tim++;
    vec.pb(cur);
	return 0;
}
int dfsrev(int cur){
	comp[cur]=cnter;
	int i;
	rep(i,revadj[cur].size()){
		if(!comp[revadj[cur][i]])
			dfsrev(revadj[cur][i]);
	}
	
	return 0;
}
ll closure(ll wt){
	ll l=0,mid;
	ll h=inf;
	ll ans=0;
	while(l<=h){
		mid=(l+h)/2;
		if(mid*(mid+1)/2<=wt){
			ans=mid;
			l=mid+1;
		}
		else{
			h=mid-1;
		}
	}
	mid=ans;
	//cout<<mid<<endl;
	return wt*(mid+1)-mid*(mid+1)*(mid+2)/6;
}
ll dp[1234567];
int main(){
   // std::ios::sync_with_stdio(false);
    int n,m;
    //cin>>n>>m;
    scanf("%d",&n);
    scanf("%d",&m);
    int i;
    rep(i,m){
    	//cin>>u[i]>>v[i]>>w[i];
        scanf("%d",&u[i]);
        scanf("%d",&v[i]);
        scanf("%d",&w[i]);
    	u[i]--;
    	v[i]--;
    	adj[u[i]].pb(v[i]);
    	revadj[v[i]].pb(u[i]);
    }
    int s;
    //cin>>s;
    scanf("%d",&s);
    s--;
    rep(i,n){
    	if(!visit[i])
    		dfs(i);
    }
    //vii vec;
    
    //sort(vec.begin(),vec.end());
    fd(i,vec.size()-1,0){
    	if(!comp[vec[i]]){
    		cnter++;
    		dfsrev(vec[i]);
    	}
    }
    rep(i,n){
    	//cout<<comp[i]<<endl;
    	visit[i]=0;
    }
    dfs(s);
    ll ans=0;
    rep(i,m){
    	if(visit[u[i]] && visit[v[i]]){
    		if(comp[u[i]]==comp[v[i]]){
    			haha[comp[u[i]]]+=closure(w[i]);
    			//cout<<haha[3]<<endl;
    			//cout<<"Dasads"<<comp[u[i]]<<endl;
    		}
    		else{
    			continue;
    			//edge[mp(comp[u[i]],comp[v[i]])]=w[i];
    		}
    	}
    }
    
    rep(i,m){
    	if(visit[u[i]] && visit[v[i]]){
    		if(comp[u[i]]==comp[v[i]]){
    			continue;
    			haha[comp[u[i]]]+=closure(w[i]);
    			//cout<<"Dasads";
    		}
    		else{
    			
    			//edge[mp(comp[u[i]],comp[v[i]])]=max(edge[mp(comp[u[i]],comp[v[i]])],w[i]+haha[comp[v[i]]]);
    			strong[comp[v[i]]].pb(comp[u[i]]);
    			boo[comp[v[i]]].pb(w[i]+haha[comp[v[i]]]);
    		}
    	}
    }
    ll iinf=inf;
    iinf*=iinf;
    iinf*=inf;
    rep(i,cnter+100){
    	dp[i]=-1*iinf;
    }
    //cout<<comp[s]<<endl;
    dp[comp[s]]=haha[comp[s]];
    ll maxi=dp[comp[s]];
    
    int j;
    f(i,3,cnter+1){
    	rep(j,strong[i].size()){
    		dp[i]=max(dp[i],dp[strong[i][j]]+boo[i][j]);

    	}
    	maxi=max(dp[i],maxi);
    }	
    printf("%lld\n",maxi);
    //cout<<maxi<<endl;

    return 0;  
    
}