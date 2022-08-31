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
ll x,y,p,q;
int check(ll val){
	if(p*val-x>=0 && q*val-y>=p*val-x)
		return 1;
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false); 
    int t;
    cin>>t;
    while(t--){
    	//ll x,y,p,q;
    	cin>>x>>y>>p>>q;
    	if(p==0 && x==0){
    		cout<<0<<endl;
    		continue;
    	}
    	if(p==0){
    		cout<<-1<<endl;
    		continue;
    	}

    	ll low=1;
    	ll high =inf;
    	ll mid=(low+high)/2;
    	ll ans=-1;
    	while(low<=high){
    		if(check(mid)){
    			ans=mid;
    			high=mid-1;
    		}
    		else{
    			low=mid+1;
    		}
    		mid=(low+high)/2;
    	}
    	if(ans==-1){
    		cout<<-1<<endl;
    	}
    	else{
    		cout<<q*ans-y<<endl;
    	}
    }
}