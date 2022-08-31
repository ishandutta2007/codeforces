
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
int dist[500],visit[500]={0};
set<int>::iterator it;
queue<int> que;
vector< set<int> > adj(500),adj1(500);
int bfs(){
	int counti=0;
	while(!que.empty()){
		int val=que.front();
		que.pop();
		if(val==-1){
			counti++;
			if(!que.empty())
			que.push(-1);
			continue;
		}
		//cout<<val<<"  ";
		dist[val]=counti;
		//cout<<dist[val]<<endl;
		for(it=adj[val].begin();it!=adj[val].end();it++){
			if(visit[*it]!=1){
				visit[*it]=1;
				que.push(*it);
			}
		}
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	int n,m,i,u,v,j;
	cin>>n>>m;
	rep(i,n+4){
		dist[i]=1000;
	}
	rep(i,m){
		cin>>u>>v;
		adj[u].insert(v);
		adj[v].insert(u);

	}
	if(adj[1].find(n)!=adj[1].end()){
		f(i,1,n+1){
			f(j,1,n+1){
				if(i!=j && adj[i].find(j)==adj[i].end()){
					adj1[i].insert(j);
				}
			}
			adj[i].clear();
		}
		//cout<<"Dasads";
		f(i,1,n+1){
			for(it=adj1[i].begin();it!=adj1[i].end();it++){
				adj[i].insert(*it);
			}

		}


	}
	visit[1]=1;
	que.push(1);
	que.push(-1);
	bfs();
	if(dist[n]==1000){
		cout<<-1<<endl;
	}
	else{
		cout<<dist[n]<<endl;
	}
}