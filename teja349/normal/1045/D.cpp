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
#define flush fflush(stdout) 
#define primeDEN 727999983
// #define double long double
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template <typename T>
void printvec(vector<T>& vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}
double neigh[123456];
vector<vi> adj(123456);
vector<vi> big(123456);
double pr[123456];
int deg[123456];
int rootn=300;
int main(){
    //std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n,i,j,k;
    //cin>>n;
    scanf("%d",&n);
    double sum=1;
   	//double gg=0;
    rep(i,n){
    	//cin>>pr[i];
    	scanf("%lf",pr+i);
    	sum-=pr[i];
    }
    
    rep(i,n-1){
    	int u,v;
    	//cin>>u>>v;
    	scanf("%d",&u);
    	scanf("%d",&v);
    	adj[u].pb(v);
    	adj[v].pb(u);
    	deg[u]++;
    	deg[v]++;
    	//gg+=pr[u]+pr[v]-pr[u]*pr[v];
    }
    
    for(i=0;i<n;i++){
    	for(j=0;j<adj[i].size();j++){
    		if(deg[adj[i][j]]>rootn) big[i].pb(adj[i][j]);
    		else neigh[i]+=pr[adj[i][j]];
    	}
    }
    double ans=0;
    for(i=0;i<n;i++){
    	double temp=neigh[i];
    	for(j=0;j<big[i].size();j++){
    		temp+=pr[big[i][j]];
    	}
    	temp=temp/2;
    	temp=deg[i]-temp;
    	temp=temp*pr[i];
    	ans+=temp;
    }
    //cout<<ans+sum<<endl;
    int q;
    //cin>>q;
    scanf("%d",&q);
    while(q--){
    	int v;
    	double newprob;
    	//cin>>v>>newprob;
    	scanf("%d",&v);
    	scanf("%lf",&newprob);
    	if(deg[v]<=rootn){
    		for(i=0;i<adj[v].size();i++){
    			neigh[adj[v][i]]+=(newprob-pr[v]);
    		}
    	}
    	double temp=neigh[v];
    	for(j=0;j<big[v].size();j++){
    		temp+=pr[big[v][j]];
    	}
    	temp=temp;
    	temp=deg[v]-temp;
    	temp=temp*(newprob-pr[v]);
    	ans+=temp;
    	sum+=pr[v]-newprob;

    	pr[v]=newprob;
    	
    	printf("%0.16lf\n",ans+sum);
    	//cout<<setprecision(20)<<ans+sum<<"\n";
    }
    return 0;   
}