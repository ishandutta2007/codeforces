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
int val=0;
vi vec;
int a[223456],c[212345],visit[212345],visit2[212345];
int indeg[212345];
int dfs(int cur){
	visit[cur]=1;
	vec.pb(cur);
	if(visit2[a[cur]]){
		val=0;
		return 0;
	}
	if(!visit[a[cur]]){
		dfs(a[cur]);
		return 0;
	}
	int mini=inf;
	int i; 
	fd(i,vec.size()-1,0){
		mini=min(mini,c[vec[i]]);
		if(vec[i]==a[cur])
			break;
	}
	val=mini;
	return 0;

}
int dfs2(int cur){
	visit2[cur]=1;
	if(!visit2[a[cur]]){
		dfs2(a[cur]);
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    rep(i,n){
    	cin>>c[i];
    }
    rep(i,n){
    	cin>>a[i];
    	a[i]--;
    	indeg[a[i]]++;
    }
    ll ans=0;
    rep(i,n){
    	if(!visit2[i]){
    		val=0;
    		vec.clear();
    		dfs(i);
    		//cout<<i<<" "<<val<<endl;
    		ans+=val;
    		dfs2(i);
    	}

    }
    cout<<ans<<endl;

    return 0;     
}