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
int n,m;
int a[12][123456],pos[12][123456];
int haha[12],visit[123456];
int findleft(){
	int j;
	while(1){
		rep(j,m){
			if(haha[j]==0)
				return 0;
		}
		haha[0]--;
		int flag=0;
		f(j,1,m){
			haha[j]--;
			if(a[j][haha[j]]!=a[0][haha[0]]){
				flag=1;
			}
		}
		if(flag)
			break;
	}
	rep(j,m){
		haha[j]++;
	}
	return 0;
	
}
int findright(){
	int val=1;
	visit[a[0][haha[0]]]=1;
	int j;
	while(1){
		rep(j,m){
			if(haha[j]==n-1)
				return val;
		}
		val++;
		haha[0]++;
		int flag=0;
		f(j,1,m){
			haha[j]++;
			if(a[j][haha[j]]!=a[0][haha[0]]){
				flag=1;
			}
		}
		if(flag)
			break;
		visit[a[0][haha[0]]]=1;
	}
	val--;
	return val;
	
}

int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin>>n>>m;
    int i;
    int j;
    rep(i,m){
    	rep(j,n){
    		cin>>a[i][j];
    		a[i][j]--;
    		pos[i][a[i][j]]=j;
    	}
    }
    ll ans=0,val;
    rep(i,n){
    	if(visit[i]){
    		continue;
    	}
    	rep(j,m){
    		haha[j]=pos[j][i];
    	}
    	findleft();
    	val=findright();
    	ans+=val*(val+1)/2;
    }
    cout<<ans<<endl;
    return 0;   
}