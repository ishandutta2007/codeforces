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
int n;
int dp[123465];
string s;
int dig(int val){
	int su=0;
	while(val>0){
		su++;
		val/=10;
	}
	return su;
}
int compute(int val){
	int rem[12345];
	int i=val;
	rem[i]=i;
	int j=i;
	i++;
	//cout<<"Das"<<endl;
	while(i<n){
		if(s[j]==s[i]){
			rem[i]=j+1;
			j++;
			i++;
		}
		else{
			if(j==val){
				rem[i]=j;
				i++;
			}
			else{
				j=rem[j-1];
			}
		}

	}

	int len=0;
	f(i,val,n){
		len++;
		rem[i]-=val;
		
			if(len%(len-rem[i])==0){
				if(val==0){
					dp[i]=min(dig(len/(len-rem[i]))+(len-rem[i]),dp[i]);
				}
				else{
					dp[i]=min(dp[val-1]+dig(len/(len-rem[i]))+(len-rem[i]),dp[i]);
				}
			}
			else{
				rem[i]=0;
				if(val==0){
					dp[i]=min(dig(len/(len-rem[i]))+(len-rem[i]),dp[i]);
				}
				else{
					dp[i]=min(dp[val-1]+dig(len/(len-rem[i]))+(len-rem[i]),dp[i]);
				}
			}

		
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin>>s;
    
    
    int i;
    n=s.length();
    rep(i,n){
    	dp[i]=inf;
    }
    //dp[0]=0;
    rep(i,n){
    	//cout<<i<<endl;
    	compute(i);
    	

    }	
    cout<<dp[n-1]<<endl;
    return 0;      

}