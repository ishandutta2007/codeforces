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

vector< vi > adj(212345);
int good[212345],len[212345];

int dfs(int cur,int prev){
	set<int> seti;
	set<int>::iterator it;
	int i;
	good[cur]=1;

	rep(i,adj[cur].size()){
		if(adj[cur][i]!=prev){
			dfs(adj[cur][i],cur);
		}
	}
	rep(i,adj[cur].size()){
		if(adj[cur][i]!=prev){
			if(!good[adj[cur][i]]){
				good[cur]=0;
			}
			else{
				if(seti.size()!=2)
				seti.insert(len[adj[cur][i]]);
			}
		}
	}
	int val=seti.size();
	if(good[cur]==1){
		if(seti.size()==2){
			good[cur]=0;
			len[cur]=-1;
		}
		else if(seti.size()==1){
			len[cur]=*(seti.begin())+1;
		}
		else{
			len[cur]=0;
		}
	}
	else{
		len[cur]=-1;
	}
	return 0;
}

int finded(int val){
	while(val%2==0){
		val/=2;
	}
	cout<<val<<endl;

	return 0;
}

int dfs2(int cur,int prev){
	map<int,int> mapi;
	mapi.clear();
	map < int,int >::iterator it;
	int i,ind,flag=0;
	rep(i,adj[cur].size()){
		if(!good[adj[cur][i]]){
			flag++;
			ind=i;
			//break;
		}
		else{
			mapi[len[adj[cur][i]]]++;
		}
	}
	//cout<<mapi.size()<<endl;
	if(mapi.size()>2 || flag>1)
	{
		cout<<-1<<endl;
		exit(0);

	}
	if(flag==0 && mapi.size()<3){
		int sumi=0;
		for(it=mapi.begin();it!=mapi.end();it++){
			sumi+=it->ff;
		}
		sumi+=mapi.size();
		//cout<<cur<<endl;
		finded(sumi);
		exit(0);
	}
	if(flag==1 && mapi.size()==2){
		cout<<-1<<endl;
		exit(0);
	}
	if(flag==1 ){
		int sumi=0;
		for(it=mapi.begin();it!=mapi.end();it++){
			sumi+=it->ff;
		}
		if(mapi.size()==1)
			len[cur]=1+sumi;
		else
			len[cur]=0;
		//cout<<sumi<<endl;
		good[cur]=1;
		dfs2(adj[cur][ind],prev);
	}

	return 0;



}


int main(){
	std::ios::sync_with_stdio(false);
	int n,i,u,v;
	cin>>n;
	rep(i,n-1){
		cin>>u>>v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(0,-1);
	dfs2(0,-1);
	cout<<-1<<endl;
	return 0;
}