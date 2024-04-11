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
vector<vl> adj(312345),wt(312345);
vl vec,vec1;  
int flag=0;
stack<int> st;
int n;
ll dist[312345];
int dfs(int cur,int par){
	if(!flag){
		st.push(cur);
	}
	if(cur==n-1){
		flag=1;
		//cout<<st.size()<<endl;
	}
	int i;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par){
			dist[adj[cur][i]]=dist[cur]+wt[cur][i];
			dfs(adj[cur][i],cur);
		}
	}

	if(!flag){
		st.pop();
	}
	return 0;
}
int cnt=0;
int visit[312345];
int visdfs(int cur,int par){
	cnt++;
	//cout<<cur<<" "<<par<<endl;
	int i;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par && visit[adj[cur][i]]==0){
			visdfs(adj[cur][i],cur);
		}
	}
	return 0;
}
ll a[312345],b[312345],notpossible[312345];
int main(){
    std::ios::sync_with_stdio(false);
    int m;
    cin>>n>>m;
    int i,j;
    ll u,v,w;
    rep(i,n-1){
    	cin>>u>>v>>w;
    	u--;
    	v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    	wt[u].pb(w);
    	wt[v].pb(w);
    }
    dfs(0,-1);
    //cout<<st.size()<<endl;
    while(!st.empty()){
    	vec1.pb(st.top());
    	st.pop();
    }

    fd(i,vec1.size()-1,0){
    	vec.pb(vec1[i]);
    	//cout<<vec1[i]<<endl;
    	visit[vec1[i]]=1;
    }
    int found=0,elem;
    //cout<<vec.size()<<endl;
    rep(i,vec.size()){

    	cnt=0;
    	//cout<<cnt<<endl;
    	visdfs(vec[i],-1);
    	//cout<<vec[i]<<" "<<cnt<<endl;
    	if(cnt>2){
    		found=1;
    		break;
    	}
    	else{
    		elem=0;
    		rep(j,adj[vec[i]].size()){
    			if(!visit[adj[vec[i]][j]]){
    				elem=wt[vec[i]][j];
    			}
    		}
    		if(elem==0){
    			notpossible[i]=1;
    		}
    		a[i]=elem;
    		b[i]=elem-dist[vec[i]];
    	}
    }
    ll maxi=inf;
    maxi*=inf;
    maxi*=-1;
        multiset<ll> seti;
    multiset<ll>::iterator it;
    seti.insert(maxi);
    rep(i,vec.size()-2){

    	maxi=max(maxi,dist[vec[i]]-dist[vec[i+2]]+a[i]);
    	if(a[i]!=0)
    		maxi=max(maxi,dist[vec[i]]-dist[vec[i+1]]+a[i]);
    }
    i=vec.size()-2;
    if(a[vec.size()-2]!=0){
    	maxi=max(maxi,dist[vec[i]]-dist[vec[i+1]]+a[i]);
    }

    rep(i,vec.size()){
    	if(!notpossible[i]){
    		seti.insert(b[i]);
    	}
    }
    ll val;
    rep(i,vec.size()){
    	if(!notpossible[i]){
    		seti.erase(seti.find(b[i]));
    		
    	}
    	it=seti.end();
    		it--;
    		val=*it+dist[vec[i]]+a[i];
    		maxi=max(val,maxi);

    }
    //cout<<maxi<<"dasds"<<endl;
    ll gg;
    rep(i,m){
    	cin>>gg;
    	if(found){
    		cout<<dist[n-1]<<endl;
    	}
    	else{
    		cout<<min(dist[n-1],dist[n-1]+maxi+gg)<<endl;
    	}
    }





    return 0;  
    
}