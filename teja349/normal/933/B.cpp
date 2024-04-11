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
ll haha[123456];
int main(){
    std::ios::sync_with_stdio(false);
    ll p,k;
    cin>>p>>k;
    haha[0]=1;
    ll i=0,p1=p;
    while(p1>0){
    	haha[i]=p1%k;
    	p1/=k;
    	i++;
    }
    ll val;
    rep(i,1000){
    	if(haha[i]>=k){
			val=haha[i];
			haha[i]=haha[i]%k;
			haha[i+1]+=val/k;
		}
    	if(i%2==1){
    		if(haha[i]!=0){
    			val=haha[i];
    			haha[i]=k-haha[i];
    			haha[i+1]++;
    		}
    	}
    }
    ll maxi=0;
    rep(i,1000){
    	if(haha[i])
    		maxi=i;
    }
    cout<<maxi+1<<endl;
    rep(i,maxi+1){
    	cout<<haha[i]<<" ";

    }
    return 0;
    
    return 0;  
    
}