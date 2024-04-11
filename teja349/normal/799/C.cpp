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
vii vecc,vecd;
vii::iterator it;
int haha[123456];
int main(){
    std::ios::sync_with_stdio(false); 
    int n,c,d;
    int i,val,val1;
    char ch;
    cin>>n>>c>>d;
    rep(i,n){
    	cin>>val>>val1;
    	cin>>ch;
    	if(ch=='C'){
    		vecc.pb(mp(val1,val));
    	}
    	else{
    		vecd.pb(mp(val1,val));
    	}

    }
    sort(vecc.begin(),vecc.end());
    sort(vecd.begin(),vecd.end());
    int maxi=0,lol1=-1,lol2=-1;
    if(vecc.size()>=2){
    	haha[0]=vecc[0].ss;
	    f(i,1,vecc.size()){
	    	haha[i]=max(haha[i-1],vecc[i].ss);
	    }
	    fd(i,vecc.size()-1,1){
	    	val=vecc[i].ff;
	    	it=upper_bound(vecc.begin(),vecc.end(),mp(c-val+1,0));
	    	if(it!=vecc.begin()){
	    		it--;
	    		val=it-vecc.begin();
	    		val=min(val,i-1);
	    		maxi=max(maxi,vecc[i].ss+haha[val]);
	    	}
	    }
    }
    if(vecd.size()>=2){
    	haha[0]=vecd[0].ss;
	    f(i,1,vecd.size()){
	    	haha[i]=max(haha[i-1],vecd[i].ss);
	    }
	    fd(i,vecd.size()-1,1){
	    	int val=vecd[i].ff;
	    	it=upper_bound(vecd.begin(),vecd.end(),mp(d-val+1,0));
	    	if(it!=vecd.begin()){
	    		it--;
	    		val=it-vecd.begin();
	    		val=min(val,i-1);
	    		maxi=max(maxi,vecd[i].ss+haha[val]);
	    	}
	    }
    }
    rep(i,vecc.size()){
    	if(vecc[i].ff<=c){
    		lol1=max(lol1,vecc[i].ss);
    	}
    }
    rep(i,vecd.size()){
    	if(vecd[i].ff<=d){
    		lol2=max(lol2,vecd[i].ss);
    	}
    }
    if(lol1!=-1 && lol2!=-1){
    	maxi=max(maxi,lol1+lol2);
    }
   	cout<<maxi<<endl;


    
}