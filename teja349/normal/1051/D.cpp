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
#define mod (998244353)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout) 
#define primeDEN 727999983
//cout<<fixed<<setprecision(15)<<ans;
 
template <typename T>
void printvec(vector<T>& vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}


ll dp[1234][2123][2][2];
int main(){
    std::ios::sync_with_stdio(false);
    int n,kkk;
    cin>>n>>kkk;
    int i,j,val,comp,p,q,k;
    dp[0][1][0][0]=1;
    dp[0][2][1][0]=1;
    dp[0][2][0][1]=1;
    dp[0][1][1][1]=1;
    rep(i,n-1){
    	rep(comp,2*n+2){
    		rep(k,2){
    			rep(j,2){
    				if(!dp[i][comp][j][k])
    					continue;
    				//cout<<"dasd"<<endl;
    				rep(q,2){
    					rep(p,2){
    					
    						val=comp;
    						if(p!=j && p!=q){
    							val++;
    						}
    						else if(p!=j && p==q && q!=k)
    							val++;
    						if(p!=q && q!=k)
    							val++;
    						dp[i+1][val][p][q]+=dp[i][comp][j][k];
    						dp[i+1][val][p][q]%=mod;
    					}
    				}
    			}
    		}
    	}
    }
    ll ans=0;
    rep(i,2){
    	rep(j,2){
    		ans+=dp[n-1][kkk][i][j];
    	}
    }
    ans%=mod;
    cout<<ans<<endl;
    return 0;   
}