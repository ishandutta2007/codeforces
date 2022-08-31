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
ll visit[123456],dist[123456],diam[123456],siz[123456];
vector<vi> adj(123456);
vector<vl> vec(123456),vecte(123456); 
int maxi,counter,vert,mew=1,n;
double answ=0,haha;
int dfs(int cur,int par,int dire){
	int i;
	if(maxi<dire){
		maxi=dire;
		vert=cur;
	}
	
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par)
			dfs(adj[cur][i],cur,dire+1);
	}
	return 0;
}
int dfs2(int cur,int par,int dire){
	int i;
	counter++;
	visit[cur]=mew;
	
	dist[cur]=max(dist[cur],(ll)dire);
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par)
			dfs2(adj[cur][i],cur,dire+1);
	}
	return 0;
}
int dfs3(int cur,int par){
	vec[mew][dist[cur]]++;
	int i;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par)
			dfs3(adj[cur][i],cur);
	}
	return 0;
}
int constr(){
	int i,j;
	int vert1,vert2;
	rep(i,n){
		
		if(visit[i])
			continue;
		//cout<<i<<" ss"<<endl;
		maxi=-1;
		dfs(i,-1,0);
		vert1=vert;
		maxi=-1;
		dfs(vert1,-1,0);
		vert2=vert;
		dfs2(vert1,-1,0);
		counter=0;
		dfs2(vert2,-1,0);
		
		vec[mew].resize(counter+12,0);
		vecte[mew].resize(counter+12,0);
		//mew++;
		diam[mew]=dist[vert1];
		siz[mew]=counter;
		dfs3(vert1,-1);
		fd(j,vecte[mew].size()-3,0){
			vec[mew][j+1]=vec[mew][j];
		}
		fd(j,vec[mew].size()-2,0){

			vecte[mew][j]=(j)*vec[mew][j]+vecte[mew][j+1];
			vec[mew][j]+=vec[mew][j+1];
		}
		mew++;
	}
	return 0;


}
int dfs4(int cur,int par,int come){
	int i;
	//cout<<come<<"sa"<<endl;
	answ+=(vecte[come][haha-dist[cur]]);
	answ+=(siz[come]-vec[come][haha-dist[cur]])*haha;
	answ+=vec[come][haha-dist[cur]]*dist[cur];
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par){
			dfs4(adj[cur][i],cur,come);
		}
	}
	return 0;
}
map<pii,ll> mapi;
int main(){
    std::ios::sync_with_stdio(false); 
    int m,q,i,u,v;
    cin>>n>>m>>q;
    rep(i,m){
    	cin>>u>>v;
    	u--;
    	v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    constr();
    rep(i,q){
    	cin>>u>>v;
    	u--;
    	v--;
    	if(visit[u]==visit[v]){
    		cout<<-1<<endl;
    		continue;
    	}
    	int com1=visit[u];
    	int com2=visit[v];

    	haha=max(diam[com1],diam[com2]);
    	answ=0;
    	if(siz[com1]<siz[com2]){
    		if(mapi.find(mp(com1,com2))!=mapi.end())
    			answ=mapi[mp(com1,com2)];
    		else	
    			dfs4(u,-1,com2);
    		mapi[mp(com1,com2)]=answ;
    	}
    	else{
    		if(mapi.find(mp(com2,com1))!=mapi.end())
    			answ=mapi[mp(com2,com1)];
    		else
    			dfs4(v,-1,com1);
    		mapi[mp(com2,com1)]=answ;
    	}
    	//cout<<answ<<endl;
    	answ*=1.00;
    	answ/=siz[com1];
    	answ/=siz[com2];
    	cout << setprecision (14) << answ << endl;

    }
    //cout<<vec[1][1]<<"as"<<endl;
    
   

}