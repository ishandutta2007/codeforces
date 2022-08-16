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
int primes[20]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59} ;
vector<vi> adj(100),badj(100),lol(100);
int dp[20][(1<<17)+10];
int par[20][(1<<17)+10],a[120],b[120];
int check(int mask,int val){
	int i,haha;
	rep(i,lol[val].size()){
		haha=(1<<lol[val][i]);
		if(mask&haha){
			return -1;
		}
		else{
			mask|=haha;
		}
	}
	return mask;
}
int compute(int n,int mask){
	if(n==-1)
		return 0;
	if(dp[n][mask]!=-1)
		return dp[n][mask];
	int i,maxi=0,val;
	rep(i,n+1){
		maxi+=b[i]-1;
	}
	
	val=1;
	int value;
	f(i,2,60){
		int new_mask=check(mask,i);
		if(new_mask!=-1)
		{
			value=abs(b[n]-i)+compute(n-1,new_mask);
			if(value<maxi){
				maxi=value;
				val=i;
			}
		}
	}
	
	par[n][mask]=val;
	dp[n][mask]=maxi;
	return dp[n][mask];

}
int answ[120];
int main(){
    std::ios::sync_with_stdio(false); 
    int n,i,j;
    cin>>n;
   	int maama=n;
    rep(i,n){
    	cin>>a[i];
    	adj[a[i]].pb(i);
    }

    rep(i,17){
    	f(j,2,61){
    		if(j%primes[i]==0){
    			lol[j].pb(i);
    		}
    	}
    	rep(j,(1<<17)+5){
    		dp[i][j]=-1;
    	}
    }
    sort(a,a+n);
    rep(i,max(n-17,0)){
    	//haha[i]=1;
    	badj[a[i]].pb(1);
    }
    j=0;
    f(i,max(n-17,0),n){
    	b[j]=a[i];
    	j++;
    }
   // cout<<min(16,n-1)<<endl;
    //return 0;
    compute(min(16,n-1),0);
    //return 0;
    n=min(16,n-1);
   	int mask=0;
    while(n>=0){
    	//cout<<par[n][mask]<<endl;
    	answ[n]=par[n][mask];
    	if(answ[n]==1){
    		rep(i,n){
    			answ[i]=1;
    		}

    		break;
    	}
    	mask=check(mask,par[n][mask]);
    	n--;
    }

    rep(i,min(17,maama)){
    	//cout<<b[i]<<endl;
    	badj[b[i]].pb(answ[i]);
    	//cout<<answ[i]<<endl;
    }

    rep(i,32){
    	
    	rep(j,adj[i].size()){
    		answ[adj[i][j]]=badj[i][j];
    	}
    }
    rep(i,maama){
    	cout<<answ[i]<<" ";
    }

}