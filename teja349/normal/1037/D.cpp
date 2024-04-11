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
vector<vi> adj(212345);
int a[212345],b[212345],used[212345];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i,j,k,u,v;
    rep(i,n-1){
    	cin>>u>>v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    rep(i,n){
    	cin>>a[i];
    	b[i]=a[i];
    }
    sort(b,b+n);
    rep(i,n){
    	if(b[i]!=i+1){
    		cout<<"No"<<endl;
    		return 0;
    	}
    }
    if(a[0]!=1){
    	cout<<"No"<<endl;
    	return 0;
    }
    //cout<<"dasd"<<endl;
    set<int> seti;
    queue<int> q1;
    q1.push(1);
    i=1;
    int flag;
    int cur,siz;
	while(!q1.empty()){
		cur=q1.front();
		used[cur]=1;
		q1.pop();
		//cout<<cur<<endl;
		flag=0;
		seti.clear();
		rep(j,adj[cur].size()){
			if(!used[adj[cur][j]]){
				
				//cout<<adj[cur][j]<<endl;
				seti.insert(adj[cur][j]);
			}
			else{
				flag=1;
			}
		}
		siz=adj[cur].size();
		if(flag)
			siz--;
		rep(k,siz){
			if(seti.find(a[i])!=seti.end()){
				//cout<<siz<<endl;
				q1.push(a[i]);
				i++;
			}
			else{
				cout<<"No"<<endl;
				return 0;
			}

		}

	}
	assert(i==n);
	cout<<"Yes"<<endl;
	return 0;
    
    return 0;   
}