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
ll p[123456],cnt=0,visit[123456];
vl vec; 
int dfs(int val){
	visit[val]=1;
	cnt++;
	if(!visit[p[val]])
		dfs(p[val]);
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    ll i;
    rep(i,n){
    	cin>>p[i];
    	p[i]--;
    }
   rep(i,n){
   		if(!visit[i]){
   			cnt=0;
   			dfs(i);
   			vec.pb(cnt);
   		}
   }
   sort(vec.begin(),vec.end());
   if(vec.size()==1){
   	cout<<n*n<<endl;
   	return 0;
   }
   ll ans=0;
   rep(i,vec.size()-2){
   	ans+=vec[i]*vec[i];
   }
   n=vec.size();
   ans+=(vec[n-1]+vec[n-2])*(vec[n-1]+vec[n-2]);
   cout<<ans<<endl;
    return 0;  
    
}