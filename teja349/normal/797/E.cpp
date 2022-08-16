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
int a[123456],ans[123456],n;
int val,lol[123456];
vector<vii> vec(1000);
int compute(int value){
	if(value>n){
		return 0;
	}
	if(lol[value]!=-1){
		return lol[value];
	}
	lol[value]=1+compute(value+a[value]+val);
	//cout<<lol[value]<<endl;
	return lol[value];
}
int main(){
    std::ios::sync_with_stdio(false); 
    //int n;
    cin>>n;
    int i;
    f(i,1,n+1){
    	cin>>a[i];
    }
    int q;
    cin>>q;
    rep(i,q){
    	int p,k;
    	cin>>p>>k;
    	if(k>=500){
    		int haha=0;
	    	while(p<=n){
	    		p=p+k+a[p];
	    		haha++;
	    	}
	    	ans[i]=haha;
    	}
    	else{
    		vec[k].pb(mp(p,i));
    		
    	}
    	
    }
    int j;
    rep(i,503){
    	if(vec[i].empty())
    		continue;
    	rep(j,n+10){
    		lol[j]=-1;
    	}
    	//cout<<lol[0]<<endl;
    	val=i;
    	rep(j,vec[i].size()){
    		//cout<<compute(vec[i][j].ff);
    		ans[vec[i][j].ss]=compute(vec[i][j].ff);
    	}

    }
    rep(i,q){
    	cout<<ans[i]<<endl;
    }


    
}