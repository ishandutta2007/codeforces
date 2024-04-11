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
int aa[123456],dsu[123456],bb[123456],w[123456],ans[123456];
map<int,int> mapi;
map<ll,int> mapid;
vector<vi> lol(123456);
vector< vii > vec(123456); 
int timer=0; 
int find(int u){
	if(dsu[u]<0)
		return u;
	dsu[u]=find(dsu[u]);
	return dsu[u];
}
int merge(int u,int v){
	if(u==v)
		return 0;
	if(dsu[u]<dsu[v]){
		dsu[v]=u;
	}
	else if(dsu[v]<dsu[u]){
		dsu[u]=v;
	}
	else{
		dsu[u]=v;
		dsu[v]--;
	}
	return 0;
}
int visit[123456],pre[123456],low[123456];
vector<set<int> > adjbrig(123456);
int dfs(int cur,int par){
	visit[cur]=1;
	pre[cur]=timer++;
	low[cur]=pre[cur];
	set<int> ::iterator it;
	for(it=adjbrig[cur].begin();it!=adjbrig[cur].end();it++){
		if(!visit[*it]){
			dfs(*it,cur);
			low[cur]=min(low[cur],low[*it]);
		}
		else {
			if(*it!=par){
				low[cur]=min(low[cur],pre[*it]);
			}
		}
	}
	return 0;
}
set<int> lolli;
int main(){
    std::ios::sync_with_stdio(false);
    ll iinf=inf;
    int n,m,i,j;
    cin>>n>>m;
    int counter=0;
    rep(i,n+12){
    	dsu[i]=-1;
    }
    rep(i,m){
    	cin>>aa[i]>>bb[i]>>w[i];
    	mapi[w[i]]=0;
    }
    map<int,int>::iterator it;
    for(it=mapi.begin();it!=mapi.end();it++){
    	it->ss=counter++;
    }
    rep(i,m){
    	w[i]=mapi[w[i]];
    	vec[w[i]].pb(mp(aa[i],bb[i]));
    	lol[w[i]].pb(i);
    }
   // return 0;
    ll u,v,temp;
    rep(i,counter){
    	mapid.clear();
    	lolli.clear();
    	//cout<<i<<" "<<counter<<endl;
    	rep(j,vec[i].size()){
    		u=find(vec[i][j].ff);
    		v=find(vec[i][j].ss);
    		if(u==v){
    			ans[lol[i][j]]=0;
    		}
    		else{
    			temp=max(u,v);
    			v=min(u,v);
    			u=temp;
    			u*=iinf;
    			u+=v;
    			mapid[u]++;
    			
    		}
    	}
    	rep(j,vec[i].size()){
    		u=find(vec[i][j].ff);
    		v=find(vec[i][j].ss);
    		if(u!=v){
    			lolli.insert(u);
    			lolli.insert(v);
    			adjbrig[u].insert(v);
    			adjbrig[v].insert(u);
    			temp=max(u,v);
    			v=min(u,v);
    			u=temp;
    			u*=inf;
    			u+=v;
    			
    			if(mapid[u]>1){
    				ans[lol[i][j]]=1;
    			}
    			else{
    				ans[lol[i][j]]=2;
    			}
    			
    		}
    	}
    	set<int>::iterator it1;
    	//cout<<*(lolli.begin())<<endl;
    	//return 0;
    	for(it1=lolli.begin();it1!=lolli.end();it1++){
    		timer=0;
    		if(visit[*it1]==0){
    			dfs(*it1,-1);
    		}
    	}
    	//return 0;
    	for(it1=lolli.begin();it1!=lolli.end();it1++){
    		adjbrig[*it1].clear();
    		visit[*it1]=0;
    	}

    	//return 0;
    	rep(j,vec[i].size()){
    		u=find(vec[i][j].ff);
    		v=find(vec[i][j].ss);
    		if(u!=v){
    			
    			
    			if(pre[u]>pre[v]){
    				swap(u,v);
    			}
    			if(pre[u]>=low[v]){
    				ans[lol[i][j]]=1;
    			}
    			
    		}
    	}

    	//return 0;
    	rep(j,vec[i].size()){
    		u=find(vec[i][j].ff);
    		v=find(vec[i][j].ss);
    		merge(u,v);
    	}

    	
    }
    rep(i,m){
    	if(ans[i]==0){
    		cout<<"none"<<endl;
    	}
    	else if(ans[i]==1){
    		cout<<"at least one"<<endl;
    	}
    	else
    		cout<<"any"<<endl;
    }

}