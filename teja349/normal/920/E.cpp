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
vector<set<int> > newadj(212345);
int visit[212345];
vector <vi > adj(212345);
vi vec,vecans;

set<int> seti;
int cnt=0;
int pos[212345];
int dfs(int cur){
	cnt++;
	visit[cur]=1;
	set<int>::iterator  it;
	for(it=newadj[cur].begin();it!=newadj[cur].end();it++){
		if(!visit[*it]){
			dfs(*it);
		}
	}
	return 0;
}
map<pii,int> mapi;
int main(){
    std::ios::sync_with_stdio(false);
    int n,m;
    int i,j,u,v;
    cin>>n>>m;
    rep(i,m){
    	cin>>u>>v;
    	u--;
    	v--;
    	if(u==v)
    		continue;
    	if(u<v)
    		swap(u,v);
    	if(mapi.find(mp(u,v))!=mapi.end())
    		continue;
    	mapi[mp(u,v)]=1;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    int mini=inf,vert;
    rep(i,n){
    	if(mini>adj[i].size()){
    		mini=adj[i].size();
    		vert=i;
    	}
    	
    }
    int sumi=0;
    rep(i,n){
    	sumi++;
    	pos[i]=vert;
    }
    //cout<<sumi<<endl;
    vec.pb(vert);
    rep(i,adj[vert].size()){
    	sumi--;
    	pos[adj[vert][i]]=adj[vert][i];
    	vec.pb(adj[vert][i]);
    	seti.insert(adj[vert][i]);

    }
    //cout<<sumi<<endl;
    seti.insert(vert);
    set<int>::iterator  it;
    f(i,1,vec.size()){
    	for(it=seti.begin();it!=seti.end();it++){
    		newadj[vec[i]].insert(*it);
    	}
    	cnt=0;
    	rep(j,adj[vec[i]].size()){
    		if(pos[adj[vec[i]][j]]==vert){
    			cnt++;
    			//cout<<adj[vec[i]][j]+1<<endl;
    			continue;
    		}
    		//if(newadj[vec[i]].find(pos[adj[vec[i]][j]])!=newadj[vec[i]].end())
    			newadj[vec[i]].erase(pos[adj[vec[i]][j]]);
    	}
    	//cout<<cnt<<" "<<vec[i]+1<<" "<<vert+1<<" "<<sumi<<endl;
    	if(cnt==sumi){
    		//cout<<cnt<<endl;
    		newadj[vec[i]].erase(vert);
    	}
    	else{
    		newadj[vert].insert(vec[i]);
    	}
    }
    rep(i,vec.size()){
    	if(!visit[vec[i]]){
    		cnt=0;
    		dfs(vec[i]);
    		if(i==0){
	    		cnt+=sumi-1;
	    	}
	    	//ans+=cnt;
	    	vecans.pb(cnt);
    	}
    	
    }
    sort(all(vecans));
    cout<<vecans.size()<<endl;
    rep(i,vecans.size()){
    	cout<<vecans[i]<<" ";
    }
    return 0;



    return 0;  
    
}