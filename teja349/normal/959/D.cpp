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
vector<vi> adj(123456);
int a[123456];
int haha[3234567],pres[3234567];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i,j,k;
    for(i=2;i<123456;i++){
    	for(j=i;j<123456;j+=i){
    		adj[j].pb(i);
    	}
    }
    int val;
    int flag=0;
    rep(i,n){
    	cin>>a[i];
    	//a[i]=2;
    	val=a[i];
    	rep(j,adj[val].size()){
    		if(pres[adj[val][j]])
    		{
    			flag=1;
    			break;
    		}
    	}
    	if(flag==1)
    		break;
    	rep(j,adj[val].size()){
    		pres[adj[val][j]]=1;
    	}
    }
    //cout<<i<<endl;
    int mini=inf;
    f(j,2,123456){
    	if(!pres[j]){
    		if(j>a[i] && !haha[j])
    			mini=min(mini,j);
    		continue;
    	}

    	for(k=j;k<3234567;k+=j){
    		haha[k]=1;
    	}
    }
    int ii;
    rep(ii,adj[mini].size()){
    	j=adj[mini][ii];
    	for(k=j;k<3234567;k+=j)
    		haha[k]=1;
    }
    a[i]=mini;
    i++;
    f(j,2,3234567){
    	if(i>=n)
    		break;
    	if(haha[j])
    		continue;
    	//cout<<i<<" "<<j<<endl;
    	a[i++]=j;
    	for(k=j;k<3234567;k+=j)
    		haha[k]=1;

    }
    rep(i,n){
    	cout<<a[i]<<" ";
    }
    cout<<endl;



    return 0;  
    
}