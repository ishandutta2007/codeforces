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
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx


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
int timer=0;
vector<vi> adj(123456);
int arr[223456],st[123456],en[123456];
ll siz[123456],ans[123456],c[123456];
int cnt[123456]={0};
ll haha=0,sumi=0;
int dfssize(int cur,int prev){
	siz[cur]=1;
	timer++;
	st[cur]=timer;
	arr[timer]=cur;
	
	int i;
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=prev){
			dfssize(adj[cur][i],cur);
			siz[cur]+=siz[adj[cur][i]];
		}
	}	
	en[cur]=timer;
	return 0;
}  

int sub(int cur){
	int i;
	f(i,st[cur],en[cur]+1){
		cnt[c[arr[i]]]--;
	}

}
int add(int cur){
	int i;
	f(i,st[cur],en[cur]+1){
		cnt[c[arr[i]]]++;
		if(cnt[c[arr[i]]]==haha){
			sumi+=c[arr[i]];
			//cout<<"hii"<<endl;
		}
		else if(cnt[c[arr[i]]]==haha+1){
			haha++;
			sumi=c[arr[i]];
			//cout<<"hii";
		}
	}
	return 0;
}
int dfs(int cur,int prev,int keep){
	int i;
	int mx=-1,bigchild=-1;
	//cout<<"ggd";
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=prev){
			if(mx<siz[adj[cur][i]]){
				mx=siz[adj[cur][i]];
				bigchild=adj[cur][i];
			}
		}
	}
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=prev && adj[cur][i]!=bigchild){
			dfs(adj[cur][i],cur,0);
		}
	}
	if(bigchild!=-1){
		dfs(bigchild,cur,1);
	}
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=prev && adj[cur][i]!=bigchild){
			add(adj[cur][i]);
		}

	}
	cnt[c[cur]]++;
	if(cnt[c[cur]]==haha){

		sumi+=c[cur];
	}
	else if(cnt[c[cur]]==haha+1){
		//cout<<"mee";
		haha++;
		sumi=c[cur];
	}
	ans[cur]=sumi;



	if(keep==0){
		sumi=0;
		haha=0;
		sub(cur);
	}
	return 0;


}
int main(){
	std::ios::sync_with_stdio(false);
	int n,i,u,v;
	cin>>n;
	rep(i,n){
		cin>>c[i];
	}
	rep(i,n-1){
		cin>>u>>v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfssize(0,-1);
	//return 0;
	dfs(0,-1,1);
	rep(i,n){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}