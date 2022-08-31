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
vector<vl> vec(10);
ll w[123456],c[123456];
pair<ll, pii > dp[312345]; 
int main(){
    std::ios::sync_with_stdio(false);
    ll n,m,i,j,haha=0;
    cin>>n>>m;

    rep(i,n){
    	cin>>w[i]>>c[i];
    	vec[w[i]].pb(c[i]);
    }
    rep(i,4){
    	sort(vec[i].begin(),vec[i].end());
    	reverse(vec[i].begin(),vec[i].end());
    }

    dp[0]=mp(0,mp(0,0));
    if(vec[1].empty()){
    	dp[1]=mp(0,mp(0,0));
    }
    else{
    	dp[1]=mp(vec[1][0],mp(1,0));
    }
    f(i,2,m+2){
    	dp[i]=dp[i-1];
    	if(dp[i-1].ss.ff < vec[1].size()){
    		haha=dp[i-1].ss.ff;
    		if(dp[i].ff < dp[i-1].ff + vec[1][haha]){
    			dp[i].ff = dp[i-1].ff + vec[1][haha];
    			dp[i].ss=mp(dp[i-1].ss.ff+1,dp[i-1].ss.ss);
    		}
    	}
    	if(dp[i-2].ss.ss < vec[2].size()){
    		haha=dp[i-2].ss.ss;
    		if(dp[i].ff < dp[i-2].ff + vec[2][haha]){
    			dp[i].ff = dp[i-2].ff + vec[2][haha];
    			dp[i].ss=mp(dp[i-2].ss.ff,dp[i-2].ss.ss+1);
    		}
    	}
    	//cout<<i<<" "<<dp[i].ff<<" "<<dp[i].ss.ff<<" "<<dp[i].ss.ss<<endl;
    }
    ll sumi=0;
    j=0;
    ll maxi=0;
    while(m>=0){
    	maxi=max(dp[m].ff+sumi,maxi);
    	if(j==vec[3].size())
    		break;
    	sumi+=vec[3][j];
    	j++;
    	m-=3;
    }
    cout<<maxi<<endl;


    
}