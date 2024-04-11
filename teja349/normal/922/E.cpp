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
ll dp[21234],dpnew[21234],sumi=0,c[1234],cost[1234];
ll n,w,b,x;
ll update(ll pos){
	ll i=0;
	ll j=1;
	ll maxc=c[pos];
	ll payoff=cost[pos];
	ll profit=-1*cost[pos],pres;

	while(i<sumi){
		if(dp[i]<0)
			break;
		//cout<<i<<" "<<dp[i]<<endl;
		while(j<sumi && j-i<=maxc){
			//cout<<j<<endl;
			pres=dp[i];
			//cout<<pres<<endl;
			if(pres+(j-i-1)*profit>=payoff){
				if(dp[j]<pres+(j-i)*profit){
					dpnew[j]=pres+(j-i)*profit;
				}
				else{

					i=j;
				}
				j++;
			}
			else{
				break;
			}
		}
		i++;
	}
	rep(i,sumi){
		dp[i]=max(dp[i],dpnew[i]);
		//dp[i]=min(dp[i],w);
		dpnew[i]=-100;
	}



}

int main(){
    std::ios::sync_with_stdio(false);
    
    cin>>n>>w>>b>>x;
    ll i;
    rep(i,n){
    	cin>>c[i];
    	sumi+=c[i];
    }
    rep(i,n){
    	cin>>cost[i];
    }
    sumi+=12;
    rep(i,sumi+100){
    	dp[i]=-100;
    	dpnew[i]=-100;
    }
    dp[0]=w;
    ll j;
    rep(i,n){
    	update(i);
    	//break;
    	//cout<<"Dasdsads"<<endl;
    	//return 0;
    	rep(j,sumi+3){
    		if(dp[j]>0){
    			dp[j]+=x;
    			dp[j]=min(dp[j],w+j*b);

    		}
    	}
    }
    int val=0;
    rep(i,sumi){
    	if(dp[i]>=0){
    		val=i;
    	}
    }
    cout<<val<<endl;
    return 0;  
    
}