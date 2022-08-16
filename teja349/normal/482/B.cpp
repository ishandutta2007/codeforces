
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
//setbase - cout << setbase (16); cout << 100 << endl; Prlls 64
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



ll update(ll l,ll r,ll val);
ll compute();
ll check();

ll n,m,c[100007]={0},seg[400009]={0},a[100007][33]={0},b[100007][33]={0};
vector< pair<ll,pll> > vec;

int main(){
	std::ios::sync_with_stdio(false); 
	ll i,l,r,val;
	cin>>n>>m;
	while(m--){
		cin>>l>>r>>val;
		update(l,r,val);

		l--,r--;
		vec.pb(mp(val,mp(l,r)));
		
	}

	compute();

	if(check())
		return 0;
	//cout<<a[1][0]<<endl;
	rep(i,n){
		cout<<c[i]<<" ";
	}
}
ll update(ll l,ll r,ll val){
	ll i;
	for(i=31;i>=0;i--){
		a[l][i]+=val&(1<<i);
		a[r+1][i]-=val&(1<<i);
	}
	return 0;
}
ll compute(){
	ll i,j;
	for(i=1;i<=n;i++){
		fd(j,31,0){
			b[i][j]=a[i][j]+b[i-1][j];
		}
	}
	for(i=1;i<=n;i++){
		fd(j,31,0){
			if(b[i][j]!=0){

				c[i-1]|=1<<j;
			}
		}
	}

}


ll make_tree(ll node,ll s,ll e){
	if(s==e){
		seg[node]=c[s];
		return 0;
	}
	ll mid=(s+e)/2;

	make_tree(2*node,s,mid);
	make_tree(2*node+1,mid+1,e);
	seg[node]=seg[2*node] & seg[2*node+1];
	return 0;

}
ll query(ll node,ll s,ll e,ll l,ll r){
	if(l<=s && e<=r){
		return seg[node];
	}
	if(s>r ||e<l){
		return -1;
	}
	ll mid=(s+e)/2;
	ll val1=query(2*node,s,mid,l,r);
	ll val2=query(2*node+1,mid+1,e,l,r);
	return (val1&val2);
}

ll check(){
	ll i;
	make_tree(1,0,n-1);
	rep(i,vec.size()){
		tri pp=vec[i];

		if(query(1,0,n-1,(pp.ss).ff,(pp.ss).ss)!=pp.ff){
			//cout<<query()

			//cout<<query(1,0,n-1,(pp.ss).ff,(pp.ss).ss)<<endl;
			
				cout<<"NO"<<endl;
				return 1; 
			
		}
	}
	cout<<"YES"<<endl;
	return 0;


}