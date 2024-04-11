
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
vector< vi > vec(200);
vector< set<int> > adj(200);
int visit[200]={0};
int dfs(int i){
	set<int>::iterator it;
	visit[i]=1;
	for(it=adj[i].begin();it!=adj[i].end();it++){
		if(!visit[*it]){
			dfs((*it));
		}

	}
	return 0;
}
int main(){
	std::ios::sync_with_stdio(false);
	int n,m,i,j,k,lan,flag=0;
	cin>>n>>m;
	rep(i,n){
	
		cin>>k;
		if(k!=0)
			flag=1;
		rep(j,k){
			cin>>lan;
			lan--;
			vec[lan].pb(i);
		}

	}
	if(!flag){
		cout<<n<<endl;
		return 0;
	}
	rep(i,m){
		rep(j,vec[i].size()){
			f(k,j+1,vec[i].size()){
				adj[vec[i][j]].insert(vec[i][k]);
				adj[vec[i][k]].insert(vec[i][j]);
			}
		}
	}
	int counti=0;
	rep(i,n){
		if(!visit[i]){
			counti++;
			dfs(i);
		}
	}
	cout<<counti-1;
}