
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
#define pqueue priority_queue< int > //max pq
#define pdqueue priority_queue< int,vi ,greater< int > >  //min pq

//std::ios::sync_with_stdio(false);   
int main(){
	ll n,k,u,v,i;
	ll ans,val,ind;
	vii vec,vec1;
	pqueue pq;
	cin>>n>>k;
	rep(i,n){
		cin>>u>>v;
		vec1.pb(mp(v,u));
		vec.pb(mp(v,u));
	}
	sort(vec.begin(),vec.end());
	rep(i,k){
		pq.push(vec[n-1-i].ss);
	}
	//cout<<pq.top();
	ans=vec[n-k].ff-pq.top();
	ind=k-1;
	f(i,k,n){
		int val=pq.top();
		if(pq.top()>vec[n-i-1].ss){
			pq.pop();
			pq.push(vec[n-1-i].ss);
		}
		if(vec[n-1-i].ff-pq.top()>ans){

			ans= vec[n-1-i].ff-pq.top();
			ind=i;
		}
	}
	int counti=0;
	if(ans<0){
		cout<<0<<endl;
		rep(i,k){
			cout<<i+1<<" ";
		}
		return 0;
	}
	cout<<ans+1<<endl;

	val=vec[n-1-ind].ff-ans;
	rep(i,n){
		if(counti==k)
			break;
		if(vec1[i].ss<=val && vec1[i].ff>=vec[n-1-ind].ff)
		{
			cout<<i+1<<" ";
			counti++;
		}
	}

}