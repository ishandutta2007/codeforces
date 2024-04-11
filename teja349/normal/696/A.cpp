
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
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx
//std::ios::sync_with_stdio(false);   


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


map<ll,ll> map1;

ll find_lca(ll u,ll v){
	while(u!=v){
		if(u>v)
			u/=2;
		else
			v/=2;
	}
	return u;
}
ll update(ll u,ll v,ll c){
	while(u!=v){
		if(map1.find(u)==map1.end())
			map1[u]=0;
		map1[u]+=c;
		u/=2;
	}

}
ll query(ll u,ll v){
	ll ans=0;
	while(u!=v){
		if(map1.find(u)!=map1.end()){
			ans+=map1[u];
		}
		u/=2;
	}
	return ans;
}


int main(){
	ll n,u,v,c;
	cin>>n;
	while(n--){
		ll type;
		cin>>type;
		if(type==1){
			cin>>u>>v>>c;
			ll lca=find_lca(u,v);
			update(u,lca,c);
			update(v,lca,c);
		}
		else{
			cin>>u>>v;
			ll lca=find_lca(u,v);
			ll ans=query(u,lca);
			ans+=query(v,lca);
			cout<<ans<<endl;
		}
	}
	return 0;
}