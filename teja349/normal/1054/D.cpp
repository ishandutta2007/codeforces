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
#define flush fflush(stdout) 
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int ll
int a[212345];
int compute(int n){
	int i;
	int x,y,mini=inf;
	mini*=inf;
	rep(i,n+1){
		x=i;
		y=n-i;
		mini=min(mini,x*(x-1)/2+y*(y-1)/2);
	}
	return mini;
}
signed main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    int val=(1LL<<k)-1;
    int i;
    map<int,int> mapi;
    map<int,int>::iterator it;
    mapi[0]++;
    int total=n*(n-1)/2+n;
    
    f(i,1,n+1){
    	cin>>a[i];
    	a[i]^=a[i-1];
    	if(a[i]<(val^a[i])){
    		mapi[a[i]]++;
    	}
    	else{
    		mapi[(val^a[i])]++;
    	}
    }
    int ans=0;
    for(it=mapi.begin();it!=mapi.end();it++){
    	ans+=compute(it->ss);
    }
    total-=ans;
    cout<<total<<endl;
    return 0;   
}