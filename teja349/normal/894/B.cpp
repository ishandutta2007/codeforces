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
ll powe(ll a,ll b){
	ll ans=1;
	while(b>0){
		if(b%2)
			ans*=a;
		ans%=mod;
		a*=a;
		a%=mod;
		b/=2;
	}
	return ans;
}
int main(){
    std::ios::sync_with_stdio(false);
    ll n,m,k;
    cin>>n>>m>>k;
    m--;
    n--;
    ll val=(m-n);
    val=abs(val);
    if(k==-1 && val%2){
    	cout<<0<<endl;
    	return 0;
    }
    ll a=2;
    a=powe(a,m);
    a=powe(a,n);
    cout<<a<<endl;
    return 0;  
    
}