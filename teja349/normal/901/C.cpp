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
//setbase - cout << setbase (16); cout << 100 << endl; Prlls 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prlls xxx77
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
ll posin=1,remem[312345];
ll vis[312345],ans[312345];
ll bit[312345][2];
ll update(ll type,ll pos,ll val){
	while(pos<312345){
		bit[pos][type]+=val;
		pos+=pos&(-pos);
	}
	return 0;
}
ll query(ll type,ll pos){
	ll anss=0;
	while(pos>0){
		anss+=bit[pos][type];
		pos-=pos&(-pos);
	}
	return anss;
}
ll entered[312345];
vector<vi> adj(312345);
ll dfs(ll cur,ll par){
	vis[cur]=1;
	entered[cur]=posin;
	remem[posin]=cur;
	posin++;
	//cout<<cur<<"saSsaSas"<<endl;
	ll val1=inf,val=0;
	ll j;
	//st.push(max(val,cur));
	ll i;
	rep(i,adj[cur].size()){
		if(!vis[adj[cur][i]])
			dfs(adj[cur][i],cur);
		else if(par!=adj[cur][i] && entered[adj[cur][i]]){
			f(j,entered[adj[cur][i]],entered[cur]+1){
				val1=min(val1,remem[j]);
				val=max(val,remem[j]);
			}
			//cout<<val<<" "<<val1<<endl;
			ans[val1]=val;
		}
			
	}
	entered[cur]=0;
	posin--;
	//cout<<cur<<"leqve"<<endl;
	//stmin.pop();
	//st.pop();
	return 0;
}
ll wow[312345],l[312345],r[312345];

int main(){
    std::ios::sync_with_stdio(false);
    ll n,m,q;
    cin>>n>>m;
    ll i,j,u,v;
    rep(i,m){
    	cin>>u>>v;
    	u--;
    	v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    //compute(0,n-1,0,n-1);
    rep(i,n){
    	ans[i]=n;
    }
    rep(i,n){
    	if(!vis[i]){
    		//cout<<"dassad";
    		dfs(i,-1);
    	}
    }
    //dfs(0);
    vii vec,quer;
    fd(i,n-2,0){
    	ans[i]=min(ans[i+1],ans[i]);
    	vec.pb(mp(ans[i],i+1));
    }
    vec.pb(mp(ans[n-1],n));
    sort(all(vec));
    cin>>q;
    rep(i,q){
    	cin>>l[i]>>r[i];
    	quer.pb(mp(r[i],(i)));
    }
    sort(all(quer));
    j=0;
    f(i,1,n+1){
    	update(1,i,1);
    }
    rep(i,quer.size()){
    	//cout<<"dasda"<<endl;
    	while(j<n && vec[j].ff<=quer[i].ff){
    		//cout<<j<<endl;
    		update(1,vec[j].ss,-1);
    		update(2,vec[j].ss,vec[j].ff+1);
    		j++;
    	}

    	wow[quer[i].ss]=query(2,r[quer[i].ss])-query(2,l[quer[i].ss]-1)+(query(1,r[quer[i].ss])-query(1,l[quer[i].ss]-1))*(r[quer[i].ss]+1);
    	wow[quer[i].ss]-=r[quer[i].ss]*(r[quer[i].ss]+1)/2-l[quer[i].ss]*(l[quer[i].ss]-1)/2;
    	//cout<<query(2,r[quer[i].ss])-query(2,l[quer[i].ss]-1)<<endl;
    }
    rep(i,q){
    	cout<<wow[i]<<" ";
    }
    cout<<endl;

    return 0;  
    
}