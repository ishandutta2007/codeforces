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
vector<vi> vec(212345);
int a[212345],b[212345];
vi adj;
int main(){
    std::ios::sync_with_stdio(false); 
    int n,i;
    cin>>n;
    rep(i,n){
    	cin>>a[i];
    	b[a[i]]++;
    	vec[a[i]].pb(i+1);	
    }
   	i=0;
   	int counti=0;
   	while(counti<n){
   		while(i>=0 && b[i]==0){
   			i-=3;
   		}
   		if(i<0){
   			cout<<"Impossible"<<endl;
   			return 0;
   		}
   		b[i]--;
   		adj.pb(vec[i][b[i]]);
   		i++;

   		

   		counti++;
   	}
   	cout<<"Possible"<<endl;
   	rep(i,adj.size()){
   		cout<<adj[i]<<" ";
   	}	
   	return 0;

}