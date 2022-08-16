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
set<pll> seti;
multiset<ll> lolo;
ll who=-1;
ll v[323456];
ll dp[323456];
int main(){
    std::ios::sync_with_stdio(false);
    int k,n;
    cin>>n>>k;
    if(n==1){
    	cout<<0<<endl;
    	return 0;
    }
    int i;
    f(i,1,n+1){
    	cin>>v[i];
    }
    sort(v+1,v+n+1);
   	

    dp[0]=0;
    f(i,1,k){
    	dp[i]=inf;
    }

   set<pll>::iterator it;
   multiset<ll>::iterator it1;
   	pll haha;
   	ll ans=0;
    f(i,k,n+1){
    	//cout<<i<<" "<<who<<endl;
    	ans=inf;
    	haha.ff=dp[i-k]+v[i-k+1];
    	haha.ss=i-k+1;
    	seti.insert(haha);
    	lolo.insert(dp[i-k]);
    	while(!seti.empty()){
    		it=seti.begin();
    		if(it->ff <= v[i]){
    			who=max(who,it->ss);
    			it1=lolo.find(it->ff-v[it->ss]);
    			lolo.erase(it1);
    			seti.erase(it);
    		}
    		else
    			break;


    	}
    	if(!lolo.empty()){
    		ans=*lolo.begin();

    	}
    	if(who!=-1){
    		ans=min(ans,v[i]-v[who]);
    	}
    	dp[i]=ans;

    }
    cout<<dp[n]<<endl;
    return 0;  
    
}