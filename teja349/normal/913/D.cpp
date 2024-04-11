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
ll n,T;
int a[212345],t[212345];   
int check(int val){
	vi vec;
	vec.clear();
	ll i,ans=0;
	rep(i,n){
		if(a[i]>=val){
			vec.pb(t[i]);
		}
	}
	if(vec.size()<val){
		return 0;
	}
	sort(vec.begin(),vec.end());
	rep(i,val){
		ans+=vec[i];
	}
	if(ans<=T)
		return 1;
	return 0;

}
int retw(int val){
	vii vec;
	vec.clear();
	int i;
	rep(i,n){
		if(a[i]>=val){
			//cout<<i<<endl;
			vec.pb(mp(t[i],i));
		}
	}
	
	sort(vec.begin(),vec.end());
	rep(i,val){
		cout<<vec[i].ss+1<<" ";
	}
	
	return 0;

}
int main(){
    std::ios::sync_with_stdio(false);
    
    cin>>n>>T;
    int i;
    rep(i,n){
    	cin>>a[i]>>t[i];
    }
    int low=1;
    int high=n;
    int ans=0,mid;
    while(low<=high){
    	mid=(low+high)/2;
    	if(check(mid)){
    		ans=mid;
    		low=mid+1;
    	}
    	else{
    		high=mid-1;
    	}
    }
    cout<<ans<<endl;
    cout<<ans<<endl;
    retw(ans);
    return 0;  
    
}