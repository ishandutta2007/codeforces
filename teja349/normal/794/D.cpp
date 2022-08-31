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
vector<vi> adj(312345),newadj(312345);
int valed[312345],equi[312345];

int compute1(int val){
	ll haha=1;
	ll lol=312347;
	ll mod1=1000000+3;
	ll ans=0,i;
	rep(i,adj[val].size()){
		ans+=haha*adj[val][i];
		ans%=mod1;
		haha*=lol;
		haha%=mod1;
	}
	return ans;
}
int compute2(int val){
	ll haha=1;
	ll lol=31231;
	ll mod1=mod;
	ll ans=0,i;
	rep(i,adj[val].size()){
		ans+=haha*adj[val][i];
		ans%=mod1;
		haha*=lol;
		haha%=mod1;
	}
	return ans;
}
int dfs(int cur,int par,int lol){
	valed[cur]=lol;
	int i;
	rep(i,newadj[cur].size()){
		if(newadj[cur][i]!=par){
			dfs(newadj[cur][i],cur,lol+1);
		}
	}
	return 0;
}
map<pair<int, pii > ,int > mapi; 
int main(){
    std::ios::sync_with_stdio(false);
    int n,m,i,j,u,v,hash1,hash2;
    int counter=0;
    cin>>n>>m;
    rep(i,m){
    	cin>>u>>v;
    	u--;
    	v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    rep(i,n){
    	adj[i].pb(i);
    	sort(adj[i].begin(),adj[i].end());
    }
   // return 0;
    rep(i,n){
    	hash1=compute1(i);
    	hash2=compute2(i);
    	if(mapi.find(mp(hash1,mp(hash2,adj[i].size())))==mapi.end()){
    		mapi[mp(hash1,mp(hash2,adj[i].size()))]=counter++;
    	}
    	equi[i]=mapi[mp(hash1,mp(hash2,adj[i].size()))];
    }
   // return 0;
    rep(i,n){
    	//cout<<equi[i]<<" ";
    	rep(j,adj[i].size()){
    		if(equi[i]!=equi[adj[i][j]] &&find( newadj[equi[i]].begin(), newadj[equi[i]].end(),equi[adj[i][j]])==newadj[equi[i]].end()){
    			newadj[equi[i]].pb(equi[adj[i][j]]);
    		}
    		if(newadj[equi[i]].size()>=3){
    			cout<<"NO"<<endl;

    			return 0;
    		}
    	}
    }
    if(counter==1){
    	cout<<"YES"<<endl;
    	rep(i,n){
    		cout<<1<<" ";
    	}
    	return 0;
    }
    int mew=0;
    int remem;
    rep(i,counter){
    	if(newadj[i].size()>=3){
    		cout<<"NO"<<endl;
    		return 0;
    	}
    	else if(newadj[i].size()==2){
    		mew+=2;
    	}
    	else if(newadj[i].size()==1){
    		remem=i;
    		mew++;
    	}
    	//cout<<newadj[i].size()<<" ";
    }
    if(mew!=2*counter-2){
    	cout<<"NO"<<endl;
    	return 0;
    }
    dfs(remem,-1,1);
    cout<<"YES"<<endl;
    rep(i,n){
    	cout<<valed[equi[i]]<<" ";
    }
    return 0;

   
}