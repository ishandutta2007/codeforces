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


/*

Copied from rajat1603 (nice usage of comparator).

Dynamic convex Hull 

decreasing slopes (lower convex HULL of points)
/////////////  for lower convex hull of points just change in operator  ////////////////


*/


struct line{
	long long a , b;
	double xleft;
	bool type;
	line(long long _a , long long _b){
		a = _a;
		b = _b;
		type = 0;
	}
	bool operator < (const line &other) const{
		if(other.type){
			return xleft < other.xleft;
		}
		return a > other.a;
	}
};
double meet(line x , line y){
	return 1.0 * (y.b - x.b) / (x.a - y.a);
}
struct cht{
	set < line > hull;
	cht(){
		hull.clear();
	}
	typedef set < line > :: iterator ite;
	bool hasleft(ite node){
		return node != hull.begin();
	}
	bool hasright(ite node){
		return node != prev(hull.end());
	}
	void updateborder(ite node){
		if(hasright(node)){
			line temp = *next(node);
			hull.erase(temp);
			temp.xleft = meet(*node , temp);
			hull.insert(temp);
		}
		if(hasleft(node)){
			line temp = *node;
			temp.xleft = meet(*prev(node) , temp);
			hull.erase(node);
			hull.insert(temp);
		}
		else{
			line temp = *node;
			hull.erase(node);
			temp.xleft = -1e18;
			hull.insert(temp);
		}
	}
	bool useless(line left , line middle , line right){
		return meet(left , middle) > meet(middle , right);
	}
	bool useless(ite node){
		if(hasleft(node) && hasright(node)){
			return useless(*prev(node) , *node , *next(node));
		}
		return 0;
	}
	void addline(long long a , long long b){
		line temp = line(a , b);
		auto it = hull.lower_bound(temp);
		if(it != hull.end() && it -> a == a){
			if(it -> b > b){
				hull.erase(it);
			}
			else{
				return;
			}
		}
		hull.insert(temp);
		it = hull.find(temp);
		if(useless(it)){
			hull.erase(it);
			return;
		}
		while(hasleft(it) && useless(prev(it))){
			hull.erase(prev(it));
		}
		while(hasright(it) && useless(next(it))){
			hull.erase(next(it));
		}
		updateborder(it);
	}
	long long getbest(long long x){
		if(hull.empty()){
			return -1e18;
		}
		line query(0 , 0);
		query.xleft = x;
		query.type = 1;
		auto it = hull.lower_bound(query);
		it = prev(it);
		return it -> a * x + it -> b;
	}
};


cht hoo;
ll subtree[123456];
vector<vi> adj(123456);
ll ans[123456],a[123456],b[123456];
//std::ios::sync_with_stdio(false);
int dfs(int cur,int par){
	int i;
	subtree[cur]=1;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par){
			dfs(adj[cur][i],cur);
			subtree[cur]+=subtree[adj[cur][i]];
		}
	}
	return 0;

}   
int clearcht(){
	hoo.hull.clear();
}
int addtocht(int cur,int par){
	int i;
	hoo.addline(b[cur],ans[cur]);
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par){
			addtocht(adj[cur][i],cur);
		}	
	}
	return 0;
}
int dsutree(int cur,int par){
	int i,maxi=0,val=-1;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par){
			if(subtree[adj[cur][i]]>maxi){
				maxi=subtree[adj[cur][i]];
				val=i;
			}
		}
	}
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par && i!=val){
			dsutree(adj[cur][i],cur);
			clearcht();
		}
	}
	if(val!=-1){
		dsutree(adj[cur][val],cur);
	}
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=par && i!=val){
			addtocht(adj[cur][i],cur);
			
		}
	}
	if(val==-1){
		ans[cur]=0;
	}
	else{
		ans[cur]=hoo.getbest(a[cur]);
	}
	hoo.addline(b[cur],ans[cur]);
	
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
    int n,i;
    cin>>n;
    rep(i,n){
    	cin>>a[i];
    }
    rep(i,n){
    	cin>>b[i];
    }
    int u,v;
    rep(i,n-1){
    	cin>>u>>v;
    	u--;
    	v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    dfs(0,-1);
    dsutree(0,-1);
    rep(i,n){
    	cout<<ans[i]<<endl;
    }
    return 0;  
    
}