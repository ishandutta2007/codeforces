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
#define flush fflush(stdout) 
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int ll
int pr[312345],mu[312345];
int a[312345];
int getfac(int val){
	int previ=0,ans=1;
	while(val!=1){
		if(pr[val]!=previ){
			previ=pr[val];
			ans*=previ;
		}
		val/=pr[val];
	}
	return ans;
}
int dp[312345],visit[312345],cnt[312345];
vector<vi> adj(312345);
int compute(int val){
	if(val==1)
		return 1;
	int i;
	if(visit[val])
		return dp[val];
	int mini=inf;
	visit[val]=1;
	rep(i,adj[val].size()){
		if(cnt[adj[val][i]]!=0)
			mini=min(mini,compute(val/adj[val][i])+1);
	}
	dp[val]=mini;
	return dp[val];

}
int haha[312345];
signed main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    int i,j,val;
    f(i,1,312345){
    	mu[i]=-1;
    }
    pr[1]=1;
    f(i,2,302345){
    	if(pr[i])
    		continue;
    	for(j=i;j<=302345;j+=i){
    		if(pr[j]==0){
    			pr[j]=i;
    		}
    		if(j%(i*i)==0){
    			mu[j]=0;
    		}
    		mu[j]*=-1;
    	}
    }
    int gg=0;
    rep(i,n){
    	cin>>val;
    	val=getfac(val);
    	if(gg==0){
    		gg=val;
    	}
    	else{
    		gg=__gcd(gg,val);
    	}
    	a[val]++;
    }
    if(gg!=1){
    	cout<<-1<<endl;
    	return 0;
    }
    if(a[1]){
    	cout<<1<<endl;
    	return 0;
    }
    
    f(i,2,302345){
    	for(j=i;j<=302345;j+=i){
    		haha[i]+=a[j]; 		
    		adj[j].pb(i);
    	}
    	//cnt[i]=n-cnt[i];
    }
    f(i,2,302345){
    	for(j=i;j<=302345;j+=i){
    		cnt[j]+=mu[i]*haha[i];
    	}
    	cnt[i]=n-cnt[i];
    }
    int mini=inf;
    f(i,2,300345){
    	if(!a[i])
    		continue;
    	mini=min(mini,compute(i));
    }
    cout<<mini<<endl;
    return 0;   
}