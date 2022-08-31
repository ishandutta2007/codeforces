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
#define pdqueue priority_queue< pii,vii ,greater< pii > >

//std::ios::sync_with_stdio(false);   
set<pii> pq;
ll dp[123],pos[123];
int main(){
    std::ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    ll ans=0;
    int i,val;
    string s;
    ll newans=0;
    cin>>s;
    rep(i,k){
    	pq.insert(mp(-1,i));
    	pos[i]=-1;
    }
    rep(i,s.length()){
    	val=s[i]-'a';
    	pq.erase(mp(pos[val],val));
    	pos[val]=i;
    	pq.insert(mp(pos[val],val));
    	newans=ans-dp[val]+ans+1;
    	newans%=mod;
    	dp[val]=ans+1;
    	dp[val]%=mod;
    	ans=newans;
    }
    //cout<<ans<<endl;
    ll mini,j;
    int m=s.length();
    set<pii>::iterator it;
    rep(i,n){
    	it=pq.begin();
    	val=it->ss;
    	mini=inf;
    	
    	pq.erase(mp(pos[val],val));
    	pos[val]=i+m;
    	pq.insert(mp(pos[val],val));
    	newans=ans-dp[val]+ans+1;
    	newans%=mod;
    	dp[val]=ans+1;
    	dp[val]%=mod;
    	ans=newans;
    }
    ans++;
    ans%=mod;
    ans+=mod;
    ans%=mod;

    cout<<ans<<endl;
    return 0;  
    
}