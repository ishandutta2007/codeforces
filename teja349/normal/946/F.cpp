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
int  visit[120][120][120];
ll dp[120][120][120];
ll boo[1234],haha[1234];
 ll n,x;
string s;
ll compute(int ind,int l,int r){
	if(ind==0 || ind==1){
		if(l<r){
			return 0;
		}
		else if(l>r){
			if(r==n-1)
				return 2;
			return 1;
		}
		else{
			if((s[l]-'0')==ind)
				return 1;
			return 0;
		}
	}
	//cout<<ind<<" "<<l<<" "<<r<<endl;
	if(visit[ind][l][r])
		return dp[ind][l][r];
	visit[ind][l][r]=1;
	int i;
	ll ans=0;
	if(l==0)
		ans=haha[ind-1]*compute(ind-2,l,r);
	else ans=compute(ind-2,l,r);
	ans%=mod;
	
	f(i,l,r){
		ans+=compute(ind-1,l,i)*compute(ind-2,i+1,r);
		
		ans%=mod;
	}
	if(r==n-1){
		ans+=compute(ind-1,l,r)*haha[ind-2];
		ans%=mod;
	}
	else{
		ans+=compute(ind-1,l,r);
		ans%=mod;
	}

	dp[ind][l][r]=ans;
	return ans;

}
ll twopow(ll b){
	ll ans=1,a=2;
	while(b>0){
		if(b%2){
			ans*=a;
			ans%=mod;
		}
		a*=a;
		a%=mod;
		b/=2;
	}
	return ans;
}
int main(){
    std::ios::sync_with_stdio(false);
   
    cin>>n>>x;
    int i=0;
    boo[0]=1;
    boo[1]=1;
    f(i,2,123){
    	boo[i]=boo[i-1]+boo[i-2];
    	boo[i]%=(mod-1);
    }
    rep(i,123){
    	haha[i]=twopow(boo[i]);
    }

    cin>>s;
    //return 0;
    cout<<compute(x,0,n-1)<<endl;
    return 0;  
    
}