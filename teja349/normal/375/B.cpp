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
int total=0;
vector<vi> vec(5123);
int bit[5123];
string s[5123]; 
int update(int pos){
	total++;
	pos++;
	while(pos<5234){
		bit[pos]++;
		pos+=pos&(-pos);
	}
	return 0;
}
int query(int pos){
	int ans=0;
	while(pos>0){
		ans+=bit[pos];
		pos-=pos&(-pos);
	}
	return total-ans;
}
int main(){
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int i,st,en,j;
    rep(i,n){
    	cin>>s[i];
    	st=-1;
    	en=-1;
    	rep(j,m){
    		if(s[i][j]=='1'){
    			if(st==-1)
    				st=j;
    			en=j;
    		}
    		else{
    			if(st!=-1){
    				//vec.pb(mp(st,en));
    				vec[st].pb(en);
    			}
    			en=-1;
    			st=-1;
    		}

    	}
    	if(st!=-1){
    		vec[st].pb(en);
    	}
    }
    //sort(vec.begin(),vec.end());
    int maxi=0;
    rep(i,m){
    	rep(j,vec[i].size()){
    		
    		update(vec[i][j]);
    	}
    	f(j,i,m){

    		maxi=max(maxi,query(j)*(j-i+1));
    	}
    }
    cout<<maxi<<endl;

    return 0;  
    
}