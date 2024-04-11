// teja349
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


//helper functions
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
ll ans=0;
int elem=0;
int coun[512345];
vector<vi> adj(512345);
int a[212345];
int pres[212345];
int remov(int val){
	val=a[val];
	elem--;
	int i,j,value,haha=0;
	fd(i,adj[val].size()-1,0){
		coun[adj[val][i]]--;
		haha+=coun[adj[val][i]];
		value=adj[val][i];
		rep(j,adj[value].size()-1){
			coun[adj[value][j]]-=coun[value];
		}
	}
	rep(i,adj[val].size()){
		value=adj[val][i];
		rep(j,adj[value].size()-1){
			coun[adj[value][j]]+=coun[value];
		}
	}
	ans-=elem-haha;
}
int add(int val){
	val=a[val];
	//cout<<val<<"dsas    ";
	int i,j,value,haha=0;
	fd(i,adj[val].size()-1,0){
		//coun[adj[val][i]]--;
		// if(val==6){
		// 	cout<<adj[val][i]<<" ds  ";
		// }
		
		haha+=coun[adj[val][i]];
		value=adj[val][i];
		rep(j,adj[value].size()-1){
			coun[adj[value][j]]-=coun[value];
		}
	}
	rep(i,adj[val].size()){
		value=adj[val][i];
		rep(j,adj[value].size()-1){
			coun[adj[value][j]]+=coun[value];
		}
		coun[value]++;
	}
	//cout<<haha<<endl;
	ans+=elem-haha;
	elem++;
}

int main(){
	//std::ios::sync_with_stdio(false);
	int n,q;
	cin>>n>>q;
	int i,j;
	rep(i,n){
		scanf("%d",&a[i]);
	}
	
	for(i=2;i<=512335;i++){
		for(j=i;j<=512335;j+=i){
			adj[j].pb(i);
		}
	}
	int val;
	while(q--){
		scanf("%d",&val);
		val--;
		if(pres[val]==1){
			remov(val);
			pres[val]=0;
		}
		else{
			add(val);
			pres[val]=1;
		}
		cout<<ans<<'\n';
	}

	return 0;  
}