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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
using namespace __gnu_pbds;

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
#define flush fflush(stdout) 
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// find_by_order()  // order_of_key
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
#define int ll

int a[123456];
int fact[123456],inv[123456];
int getpow(int a,int b){
	int ans=1;
	while(b){
		if(b%2){
			ans*=a;
			ans%=mod;
		}
		a*=a;
		a%=mod;
		b/=2;
	}
	return ans;
}
int getinverse(int val){
	return getpow(val,mod-2);
}
int getncr(int n,int r){
	int val=fact[n];
	val*=inv[r];
	val%=mod;
	val*=inv[n-r];
	val%=mod;
	return val;
}
main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    int i;
    fact[0]=1;
    inv[0]=1;
    f(i,1,123456){
    	fact[i]=fact[i-1]*i;
    	fact[i]%=mod;
    	inv[i]=getinverse(fact[i]);
    }
    ll sumi=0;
    rep(i,n){
    	cin>>a[i];
    	sumi+=a[i];
    }
    if(sumi%n!=0){
    	cout<<0<<endl;
    	return 0;
    }
    sumi/=n;
    int gg=n;
    ll sofar=1;
    int wow=0,haha=0;
    int cnt=0;
    map<int,int> map1,map2;
    map<int,int>::iterator it;
    rep(i,n){
    	if(a[i]==sumi){
    		cnt++;
    	}
    	if(a[i]<sumi){
    		wow++;
    		map1[a[i]]++;
    	}
    	if(a[i]>sumi){
    		haha++;
    		map2[a[i]]++;
    	}
    }
    sofar=getncr(n,cnt);
    int lef=n-cnt;
    for(it=map1.begin();it!=map1.end();it++){
		sofar*=inv[it->ss];
		sofar%=mod;
	}
	for(it=map2.begin();it!=map2.end();it++){
		sofar*=inv[it->ss];
		sofar%=mod;
	}
    if(haha<=1 || wow<=1){
    	sofar*=fact[lef];
    	sofar%=mod;
    }
    else{
    	sofar*=2;
    	sofar%=mod;
    	sofar*=fact[wow];
    	sofar%=mod;
    	sofar*=fact[haha];
    	sofar%=mod;
    }
    cout<<sofar<<endl;

    return 0;
}