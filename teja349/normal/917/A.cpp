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
int dp[5123][5123];
int n;
string s;
vector<vi> vec(5123);
int main(){
    std::ios::sync_with_stdio(false);
    //string s;

    cin>>s;
    n=s.length();
    int i,j,k;
    int ans=0;
    fd(i,s.length()-2,0){
    	if(s[i]=='('||s[i]=='?'){
    		if(s[i+1]==')'||s[i+1]=='?'){
    			dp[i][i+1]=1;
    			vec[i].pb(i+1);
    			ans++;
    			f(j,0,vec[i+2].size()){
    				dp[i][vec[i+2][j]]=1;
    			}
    		}
    	}
    	else{
    		continue;
    	}
    	for(j=i+3;j<s.length();j+=2){
    		if(dp[i][j]==1){
    			vec[i].pb(j);
    			ans++;
    			continue;
    		}
    		if(s[j]==')'||s[j]=='?'){
    			dp[i][j]=dp[i+1][j-1];
    		}
    		if(dp[i][j]==1){
    			vec[i].pb(j);
    			ans++;
    			f(k,0,vec[j+1].size()){
    				dp[i][vec[j+1][k]]=1;

    			}
    		}
    	}
    }
    cout<<ans<<endl;
    return 0;  
    
}