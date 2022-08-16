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
vector<vi> adj(1000105);
int a[223456],two[212345];
ll haha[1234567];
ll ans[1234567];
int main(){
   // std::ios::sync_with_stdio(false);
    int n,i,j;
    cin>>n;
    rep(i,n){
    	scanf("%d",&a[i]);
    }
    for(i=2;i<=1000014;i++){
    	for(j=i;j<=1000014;j+=i){
    		adj[j].pb(i);    		
    	}
    }
    //return 0;
    rep(i,n){
    	rep(j,adj[a[i]].size()){
    		haha[adj[a[i]][j]]++;
    	}
    }
    //return 0;
    two[0]=1;
    for(i=1;i<=212345;i++){
    	two[i]=two[i-1]*2;
    	if(two[i]>=mod)
    		two[i]-=mod;
    	//two[i]%=mod;
    }

    for(i=2;i<=1000004;i++){
    	if(haha[i]>0)
    		ans[i]=two[haha[i]-1]*haha[i];
    	else
    		haha[i]=0;
    	ans[i]%=mod;    	
    }
    ll sumi=0;
    for(i=1000004;i>=2;i--){
    	sumi+=i*ans[i];
    	sumi%=mod;
    	if(ans[i]==0){
    		continue;
    	}
    	rep(j,adj[i].size()){
    		ans[adj[i][j]]-=ans[i];
    		if(ans[adj[i][j]]<0){
    			ans[adj[i][j]]+=mod;
    		}
    	}
    }
   cout<<sumi<<endl;


    return 0;      

}