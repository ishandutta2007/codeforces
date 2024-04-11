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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
using namespace __gnu_pbds;

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
#define flush fflush(stdout) 
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// find_by_order()  // order_of_key
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int dsu[312345],sumi[312345],val[312345],fixer[312345],opp[312345];
vector<vi> adj(312345),vec(312345);

int getpar(int u){
	if(dsu[u]<0)
		return u;
	dsu[u]=getpar(dsu[u]);
	return dsu[u];
}
int s[312345];
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    int i;
    string st;
    cin>>st;
    int c,qq;
    int vali;
    rep(i,k){
    	cin>>c;
    	rep(qq,c){
    		cin>>vali;
    		vali--;
    		adj[vali].pb(i);
    	}
    }
    rep(i,n){
    	s[i]=st[i]-'0';
    }
    rep(i,k+10){
    	dsu[i]=-1;
    	val[i]=0;
    	sumi[i]=0;
    	fixer[i]=0;
    	opp[i]=0;
    	vec[i].pb(i);
    }
    int sofar=0;
    int u,v,j;
    int paru,parv,par;
    rep(i,n){
    	if(adj[i].size()==0){
    		cout<<sofar<<endl;
    		continue;
    	}
    	else if(adj[i].size()==1){
    		//cout<<i<<"dsa ";
    		u=adj[i][0];
    		par=getpar(u);
    		fixer[par]=1;
			sofar-=sumi[par];
			//cout<<u<<endl;
			if(((val[u]^s[i])^opp[par])==0){
				opp[par]^=1;
				sumi[par]=(dsu[par]*-1)-sumi[par]; 
			}
			sofar+=sumi[par];
			cout<<sofar<<endl;
    	}
    	else{
    		u=adj[i][0];
    		v=adj[i][1];
    		paru=getpar(u);
    		parv=getpar(v);
    		if(paru==parv){
    			cout<<sofar<<endl;
    			continue;
    		}
    		sofar-=sumi[paru];
    		sofar-=sumi[parv];
    		if(dsu[paru]<dsu[parv])
    		{
    			swap(u,v);
    			swap(paru,parv);
    		}
    		if(((val[u]^val[v])^s[i])==(opp[paru]^opp[parv])){
    			if(fixer[paru]){
    				assert(fixer[parv]==0);
    				opp[parv]^=1;
    				sumi[parv]=(dsu[parv]*-1)-sumi[parv];
    			}
    			else{
    				opp[paru]^=1;
    				sumi[paru]=(dsu[paru]*-1)-sumi[paru];
    			}
    		}
    		if(opp[parv]!=opp[paru]){
    			opp[paru]^=1;
    			rep(j,vec[paru].size()){
    				val[vec[paru][j]]^=1;
    			}
    		}
    		if(fixer[paru]){
    			fixer[parv]=1;
    		}
    		rep(j,vec[paru].size()){
    			vec[parv].pb(vec[paru][j]);
    		}
    		sumi[parv]+=sumi[paru];
    		dsu[parv]+=dsu[paru];
    		dsu[paru]=parv;	
    		if(fixer[parv]==0){
    			if(sumi[parv]>(dsu[parv]*-1)-sumi[parv]){
    				opp[parv]^=1;
    				sumi[parv]=(dsu[parv]*-1)-sumi[parv];
    			}
    		}
    		sofar+=sumi[parv];
    		cout<<sofar<<endl;
    	}
    }
    return 0;   
}