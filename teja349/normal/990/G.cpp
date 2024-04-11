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
ll a[200005];
vector<vi> factos(200005),adj(200005),lubb(200005),revfac(200005);
ll dsu[200005],haha[200005];
int par(int cur){
	if(dsu[cur]<0)
		return cur;
	dsu[cur]=par(dsu[cur]);
	return dsu[cur];
}
int merge(int u,int v){
	u=par(u);
	v=par(v);
	if(u==v)
		return 0;
	if(dsu[u]>dsu[v])
		swap(u,v);
	haha[dsu[u]*-1]--;
	haha[dsu[v]*-1]--;
	dsu[u]+=dsu[v];
	dsu[v]=u;
	haha[dsu[u]*-1]++;
	return 0;
}  

ll ans[200005];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i,j,k;
    rep(i,n){
    	cin>>a[i];
    }
    int x,y;
    rep(i,n-1){
    	cin>>x>>y;
    	x--;
    	y--;
    	adj[x].pb(y);
    	adj[y].pb(x);
    }
    for(i=1;i<200004;i++){
    	
    	for(j=i;j<200004;j+=i){
    		factos[j].pb(i);
    		if(i!=j)
    			revfac[i].pb(j);
    	}
    }
    rep(i,n){
    	dsu[i]=inf;
    }
    
    rep(i,n){
    	rep(j,factos[a[i]].size()){
    		
    		lubb[factos[a[i]][j]].pb(i);
    		
    	}
    }

    int cur;
    f(i,1,2*100000+1){
    	rep(j,lubb[i].size()){
    		haha[1]++;
    		dsu[lubb[i][j]]=-1;
    	}
    	rep(j,lubb[i].size()){
    		cur=lubb[i][j];
    		rep(k,adj[cur].size()){
    			if(dsu[adj[cur][k]]!=inf){
    				merge(cur,adj[cur][k]);
    			}
    		}

    	}
    	rep(j,lubb[i].size()){
    		if(dsu[lubb[i][j]]<0){
    			//cout<<lubb[i][j]<<" "<<haha[dsu[lubb[i][j]]*-1]<<endl;
    			ans[i]+=haha[dsu[lubb[i][j]]*-1]*dsu[lubb[i][j]]*(dsu[lubb[i][j]]-1)/2;
    			haha[dsu[lubb[i][j]]*-1]=0;
    		}
    		
    		dsu[lubb[i][j]]=inf;

    	}
    	
    }

    fd(i,2*100000,1){
    	rep(j,revfac[i].size()){
    		ans[i]-=ans[revfac[i][j]];
    	}
    }
    f(i,1,2*100000+1){
    	if(ans[i])
    		cout<<i<<" "<<ans[i]<<endl;
    }



    return 0;  
    
}