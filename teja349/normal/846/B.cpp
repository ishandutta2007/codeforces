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
ll n,k,m,ans;
ll t[12345];
ll solve(int val){
	ll haha,lol=n-val,val1=m-ans*val;
	if(val1<0)
		return 0;
	else
		haha=val*(k+1);
	int i=0;
	while(i<k){
		if(val1<0)
			break;
		haha+=min(val1/t[i],lol);
		val1-=lol*t[i];
		i++;
	}
	return haha;
}
int main(){
    std::ios::sync_with_stdio(false);
    
    cin>>n>>k>>m;
    int i;
    rep(i,k){
    	cin>>t[i];
    	ans+=t[i];

    }
    sort(t,t+k);
    ll maxi=0;
    rep(i,n+1){
    	maxi=max(solve(i),maxi);
    }
    cout<<maxi<<endl;
    return 0;  
    
}