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

ll seg[412345],a[123456];
ll n,k;	
map <ll,ll> mapi, previ;

ll update(ll node,ll s,ll e,ll p,ll val){
	if(s==e){
		seg[node]=val;
		//cout<<val<<endl;
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

ll neginff;
int add(ll i){
	mapi[a[i]]++;
	if(mapi[a[i]]==1){
		update(1,0,n-1,i,a[i]);
		previ[a[i]]=i;
		//cout<<i<<endl;
	}
	else if(mapi[a[i]]==2){
		//cout<<"huuu";
		//cout<<neginff<<"sdf"<<endl;
		update(1,0,n-1,previ[a[i]],neginff);
		//update(1,0,n-1,i,neginff);
		//cout<<neginff<<endl;
	}
	return 0;
}
int removed(ll i){
	mapi[a[i]]--;
	if(mapi[a[i]]==1){
		update(1,0,n-1,i,a[i]);
		previ[a[i]]=i;
	}
	else if(mapi[a[i]]==0){

		update(1,0,n-1,previ[a[i]],neginff);
	}
	return 0;
}
int main(){

	std::ios::sync_with_stdio(false);
	neginff=-1*inf;int i;

	
	cin>>n>>k;
	rep(i,n){
		cin>>a[i];

	}
	rep(i,4*n+50){
		seg[i]=neginff;
	}
	rep(i,k){
		add(i);
	}

	
	if(seg[1]==neginff)
		cout<<"Nothing"<<endl;
	else
		cout<<seg[1]<<endl;
	f(i,k,n){
		
		add(i);

		removed(i-k);
		if(seg[1]==neginff)
			cout<<"Nothing"<<endl;
		else
			cout<<seg[1]<<endl;
	}
}