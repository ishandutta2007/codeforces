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
int ans;
int par[1234567];
int temp[1234567];
int subtree[1234567];
int hasin[1234567]={0};
int hasinit[1234567];
vector<vi> adj(1000*1000+10);


int dfs(int cur,int prev){
	subtree[cur]=temp[cur];

	if(adj[cur].size()==0){
		if(subtree[cur]==ans){
		hasin[cur]=1;
		hasinit[cur]=cur;
	}
		return 0;
	}

	int i,counti=0;

	vi vec;
	rep(i,adj[cur].size()){
		dfs(adj[cur][i],cur);
		subtree[cur]+=subtree[adj[cur][i]];

	}
	//cout<<counti<<endl;
	rep(i,adj[cur].size()){
		if(hasin[adj[cur][i]]){
			//hasin[cur]=1;
			counti++;
			vec.pb(hasinit[adj[cur][i]]);
		}
		
	}

	if(counti>=2){
		cout<<vec[0]<<" "<<vec[1]<<endl;
		exit(0);
	}
	if(counti==1){
		hasin[cur]=1;
		hasinit[cur]=vec[0];

	}

	if(hasin[cur]==1 && subtree[cur]==2*ans && prev!=-1){
		cout<<hasinit[cur]<<" "<<cur<<endl;
		exit(0);
	}
	if(subtree[cur]==ans){
		hasin[cur]=1;
		hasinit[cur]=cur;
	}
	return 0;


}

int main(){
	std::ios::sync_with_stdio(false);
	int n,i;
	int root;
	cin>>n;
	f(i,1,n+1){
		cin>>par[i]>>temp[i];
		ans+=temp[i];

		if(par[i]==0){
			root=i;
		}
		else{
			adj[par[i]].pb(i);
		}

	}
	if(ans%3!=0){
		cout<<-1<<endl;
		return 0;
	}
	ans/=3;

	dfs(root,-1);
	cout<<-1<<endl;
	return 0;
}