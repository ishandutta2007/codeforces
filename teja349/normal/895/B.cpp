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
ll a[123456],in[123456],out[123456];
map<ll,ll> baba,wow;
int main(){
    std::ios::sync_with_stdio(false);
    ll i, n,x,k,ans=0;
    cin>>n>>x>>k;
    rep(i,n){
    	cin>>a[i];
    }
    sort(a,a+n);
    rep(i,n){
    	
    	
    	in[i]=a[i]/x;
    	if(a[i]%x)
    		in[i]++;
    	out[i]=a[i]/x;

    }
    fd(i,n-1,0){
    	wow[out[i]]++;
    	if(wow.find(in[i]+k-1)!=wow.end())
    		ans+=wow[in[i]+k-1];
    }
    map<ll,ll>::iterator it;
    if(k==1){
    	rep(i,n){
    		if(a[i]%x==0){
    			baba[a[i]]++;

    		}
    	}
    	for(it=baba.begin();it!=baba.end();it++){
    		ans+=(it->ss)*(it->ss-1)/2;
    	}
    }
    else if(k==0){
    	rep(i,n){
    		if(a[i]%x){
    			baba[a[i]]++;

    		}
    	}
    	for(it=baba.begin();it!=baba.end();it++){
    		ans+=(it->ss)*(it->ss-1)/2;
    	}
    }
    cout<<ans<<endl;



    return 0;  
    
}