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
vi vec,vec1;
int a[123456],haha[123456],load[123456];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i,init;
    rep(i,n){
    	cin>>a[i];

    }
    rep(i,n){
    	
    	init=i;
    	while(i+1<n && a[i+1]<a[i]){
    		i++;
    		//vec.pb(init);
    	}
    	haha[init]=i+1;
    	if(init!=i){
    		vec.pb(init);
    	}
    	//back[i+1]=init;
    	
    }

    int steps=0;
    while(1){
    	//cout<<haha[0]<<endl;
    	if(vec.size()==0){
    		cout<<steps<<endl;
    		return 0;
    	}
    	steps++;
    	fd(i,vec.size()-1,0){
    		init=vec[i];
	    	if(haha[init]!=n && a[haha[init]]<a[init]){
	    		vec1.pb(init);
	    		load[haha[init]]=-1;
	    		load[init]=1;
	    		haha[init]=haha[haha[init]];
	    	}

	    }
	    vec.clear();
	    fd(i,vec1.size()-1,0){
	    	if(load[vec1[i]]==1)
	    		vec.pb(vec1[i]);
	    }
	    vec1.clear();

    }

   
    
}