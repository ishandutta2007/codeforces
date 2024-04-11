
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
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prlls xxx77
//setprecision - cout << setprecision (4) << f << endl; Prlls x.xxxx


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
ll group[1000*1000+7]={0};
ll arr[1000*1000+3]={0};
ll factor[1000*100*10+6];
ll counti=1;
int main(){
	std::ios::sync_with_stdio(false);
	ll n,m;
	cin>>n>>m;

	ll i,j;
	factor[0]=1;
	f(i,1,1000*100*10+5){
		factor[i]=factor[i-1]*i;
		factor[i]%=mod;
	}
	//cout<<factor[25]<<endl;
	rep(j,n){
		ll num;
		map<ll,ll> mapi;
		mapi.clear();
		map<ll ,ll >::iterator it;
		viii vec;
		vec.clear();
		ll val;
		cin>>num;
		rep(i,num){
			cin>>val;
			if(mapi.find(val)==mapi.end()){
				mapi[val]=1;
			}
			else{
				mapi[val]++;
			}
		}
		for(it=mapi.begin();it!=mapi.end();it++){
			vec.pb(mp(it->ss,mp(group[it->ff],it->ff)));
		}
		ll prev,prev1;
		sort(vec.begin(),vec.end());
		prev=group[vec[0].ss.ss];
		group[vec[0].ss.ss]=counti++;

		f(i,1,vec.size()){
			prev1=group[vec[i].ss.ss];
			if(vec[i-1].ff!=vec[i].ff){
				group[vec[i].ss.ss]=counti++;
			}
			else if(group[vec[i].ss.ss]!=prev){

				group[vec[i].ss.ss]=counti++;
			}
			else{

				group[vec[i].ss.ss]=group[vec[i-1].ss.ss];
			}
			prev=prev1;
		}
		

		

	}
	f(i,1,m+1){
		//cout<<group[i]<<endl;
		arr[group[i]]++;
	}
	ll value=1;
	rep(i,1000*1000+2){
		//cout<<arr[i]<<endl;
		value*=factor[arr[i]];
		value%=mod;
	}
	cout<<value<<endl;
}