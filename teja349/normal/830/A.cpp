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
int n,k;
ll pl[12345],key[12345],pos; 
int check(ll val){
	int i=0;
	set<ll> seti;
	rep(i,n){
		if(abs(pos-pl[i])>val)
			//cout<<"DSAads";
			//cout<<pos<<endl;
			return -1;

	}
	rep(i,k){
		seti.insert(key[i]);
	}
	set<ll>::iterator it;
	i=0;
	while(i<n){
		ll val1=pl[i]+pos-val+1;
		val1/=2;
		ll valhigh=(val+pl[i]+pos)/2;
		it=seti.lower_bound(val1);
		if(it!=seti.end() && *it<=valhigh){
			seti.erase(it);
		}
		else{
			//cout<<"bttg";
			return -1;
		}
		i++;
		
	}
	
	return 1;

}
int main(){
    std::ios::sync_with_stdio(false);
     
     cin>>n>>k;
     cin>>pos;
     int i;
     rep(i,n){
     	cin>>pl[i];
     }
     sort(pl,pl+n);
     rep(i,k){
     	cin>>key[i];
     }
     sort(key,key+k);
    //ll pos;
     
     ll low=0;
     ll high=inf;
 		high*=10000;
 		ll mid;
 		ll ans=-1;
 		//cout<<check(50)<<endl;
 		//return 0;
 	while(low<=high){
 		mid=(low+high)/2;
 		if(check(mid)==1){
 			ans=mid;
 			high=mid-1;
 		}
 		else{
 			low=mid+1;
 		}
 	}
 	cout<<ans<<endl;    
    
}