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
int mapi[123456],posi[123456],inv[123456];
int pr[123456],a[123456],sasa[12345];
vi impo,lol;
vii vectp;
int pooh=0;
int flag=0;
int setit(int i){
	
	int elem=inv[i];
	//cout<<posi[elem]<<" "<<i<<endl;
	if(posi[elem]==i){
		return 0;
	}

	
	int move=posi[elem]-i+1;
	
	if(move<=400){
		if(move%2)
			move=2;
		//sasa[3]=3;
		int newpos=posi[elem]-sasa[move]+1;

		vectp.pb(mp(newpos,posi[elem]));
		posi[a[newpos]]=posi[elem];
		swap(a[posi[elem]],a[newpos]);

		posi[elem]=newpos;
		setit(i);
		return 0;

	}
	vi::iterator it;
	it=lower_bound(impo.begin(),impo.end(),move);
	it--;
	int haha=*it;
	int newpos=posi[elem]-haha+1;
	vectp.pb(mp(newpos,posi[elem]));
	posi[a[newpos]]=posi[elem];
	swap(a[posi[elem]],a[newpos]);

	posi[elem]=newpos;
	setit(i);
	return 0;

}
int main(){
    std::ios::sync_with_stdio(false);
    int n,i,j;
    cin>>n;
    for(i=2;i*i<=123456;i++){
    	if(pr[i])
    		continue;
    	for(j=i*i;j<123444;j+=i){
    		pr[j]=1;
    	}
    }
    f(i,2,123456){
    	if(!pr[i]){
    		impo.pb(i);
    	}
    }
    
    lol.pb(0);
    f(i,2,400){
    	if(!pr[i]){
    		lol.pb(i);
    	}
    }
    rep(i,lol.size()){
    	rep(j,lol.size()){
    		sasa[lol[i]+lol[j]]=lol[i];
    		
    	}
    }
    //cout<<sasa[293]<<endl;
    //cout<<sasa[297]<<endl;
    //breturn 0;

    rep(i,n){
    	cin>>a[i];
    	a[i]--;
    	mapi[a[i]]=1;
    	posi[a[i]]=i;
    }
    int co=0;
    rep(i,n){
    	mapi[i]=co++;
    	inv[co-1]=i;
    }
    //return 0;
    rep(i,n){
    	//cout<<i<<endl;
    	
    	setit(i);
    	flag=0;
    	
    }

    //return 0;
    cout<<vectp.size()<<endl;
    
    //cout<<endl;
    rep(i,vectp.size()){
    	cout<<vectp[i].ff+1<<" "<<vectp[i].ss+1<<endl;
    }

    return 0;      

}