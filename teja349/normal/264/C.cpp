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
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx


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

ll seg[412345],dp[123456][3],v[123456],c[123456],c1[123456],c0[123456];


ll update(ll node,ll s,ll e,ll p,ll val){
	if(s==e){
		seg[node]=val;
		return 0;
	}
	ll mid=(s+e)/2;
	if(p<=mid){
		update(2*node,s,mid,p,val);
	}
	else{
		update(2*node+1,mid+1,e,p,val);
	}
	seg[node]=max(seg[2*node],seg[2*node+1]);
	return 0;
}


ll query(ll node,ll s,ll e,ll l,ll r){
	if(l>e || r<s){
		return 0;
	}
	if(l<=s && e<=r){
		return seg[node];
	}
	ll mid=(s+e)/2;
	ll a=query(2*node,s,mid,l,r);
	ll b=query(2*node+1,mid+1,e,l,r);
	return max(a,b);


}



int main(){
	std::ios::sync_with_stdio(false);
	ll n,q;
	cin>>n>>q;
	ll i;
	rep(i,n){
		cin>>v[i];
		//cin>>c[i];
	}
	rep(i,n){
		cin>>c[i];
	}
	ll a,b;
	while(q--){

		vll vec(3);
		vec[0].ff=0;
		vec[0].ss=-1;
		vec[1]=vec[0];
		rep(i,n+3){
			
			c1[i]=0;
			c0[i]=0;
		}
		cin>>a>>b;
		ll ans=0;
		fd(i,n-1,0){
			//ll value = (max(query(1,0,n+2,0,c[i]-1),query(1,0,n+2,c[i]+1,n+1)));
			//return 0;

			//	cout<<value<<endl;
			ll value;
			if(c[i]!=vec[0].ss){
				value=vec[0].ff;
			}
			else{
				value=vec[1].ff;
			}
			value=max(value,c0[c[i]]);
			dp[i][0]=v[i]*a + value;
			dp[i][1]=v[i]*b + value;
			ans=max(ans,dp[i][1]);
			//cout<<i<<"  "<<dp[i][0]<<"  "<<dp[i][1]<<endl;
			if(vec[0].ff<dp[i][1]){
				if(vec[0].ss==c[i]){
					vec[0].ff=dp[i][1];
				}
				else{
					vec[1]=vec[0];
					vec[0].ff=dp[i][1];
					vec[0].ss=c[i];
				}
			}
			else if(dp[i][1]>vec[1].ff){
				if(vec[0].ss!=c[i]){
					vec[1].ff=dp[i][1];
					vec[1].ss=c[i];
				}
			}
			c0[c[i]]=max(c0[c[i]],dp[i][0]);

		}
		cout<<ans<<endl;
		
	}
}