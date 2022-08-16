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

ll check(ll n,ll k){
	ll flag=0;
	ll vasya=0;
	ll nn=n;
	while(n){
		if(flag==0){
			if(n<k){
				vasya+=n;
				n=0;
			}
			else{
				vasya+=k;
				n-=k;
			}

		}
		else{
			n-=n/10;
		}
		flag^=1;

	}
	//cout<<vasya<<endl;
	return (nn<=2*vasya);
}
int main(){
    std::ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    ll low=1;
    ll high=n;
    ll mid;
    ll ans;
    //cout<<check(n,1)<<endl;
    //return 0;
    while(low<=high){
    	mid=(low+high)/2;
    	if(check(n,mid)){
    		ans=mid;
    		high=mid-1;
    	}
    	else{
    		low=mid+1;
    	}
    }
    cout<<ans<<endl;
    return 0;  
    
}