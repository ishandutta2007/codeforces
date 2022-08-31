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
#define N 55
//std::ios::sync_with_stdio(false);   
int trie[63*100000+5][2]={0};
int counti=1;
int haha[63*100000+5]={0};
ll a[123456],pre[123456],post[123456];
int inserttrie(ll val){
	//cout<<"fdssfd   "<<val<<endl;
	int node=0;
	ll k=N;
	haha[node]++;
	int based;
	while(k>=0){
		based=0;
		if((val&(1LL<<k)) > 0){
			based=1;
		}
		if(trie[node][based]==0){
			trie[node][based]=counti++;
			
		}

		node=trie[node][based];
		haha[node]++;
		k--;
	}
	return 0;
}

int deletetrie(ll val){
	int node=0;
	ll k=N;
	haha[node]--;
	int based;
	while(k>=0){
		based=0;
		if((val&(1LL<<k)) >0){
			based=1;
		}
		
		

		node=trie[node][based];
		// if(haha[node]==0)
		// 	cout<<"bastard"<<endl;
		haha[node]--;
		k--;
	}
	return 0;
}

ll getmax(ll val){
	//cout<<val<<endl;
	int node=0;
	ll k=N;
	ll based;
	ll ans=0;
	while(k>=0){
		based=1;
		if((val&(1LL<<k)) > 0){
			//cout<<(val&(1LL<<k))<<endl;
			//cout<<"dadsda";
			based=0;
		}
		if(trie[node][based]!=0 && haha[trie[node][based]]!=0 ){
			//cout<<"aasdasd";
			node=trie[node][based];
			
			ans|=(1LL<<k);
		}
		else{

			node=trie[node][based^1];
			
		}
		k--;

	}
	return ans;

}
int main(){
	std::ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	int i;
	rep(i,n){
		cin>>a[i];
	}
	ll maxi=max(a[0],a[n-1]);
	pre[0]=a[0];
	f(i,1,n){
		pre[i]=pre[i-1]^a[i];
		maxi=max(maxi,pre[i]);
	}
	post[n-1]=a[n-1];

	fd(i,n-2,0){
		post[i]=post[i+1]^a[i];
		maxi=max(maxi,post[i]);
	}
	//cout<<post[0]<<endl;
	f(i,1,n){
		inserttrie(post[i]);
	}
	//cout<<haha[1]<<endl;
	f(i,0,n-1){
		ll val=getmax(pre[i]);
		//cout<<pre[i]<<"   "<<val<<endl;
		maxi=max(maxi,val);
		//cout<<endl;
		deletetrie(post[i+1]);
		//cout<<maxi<<endl;
	}
	//cout<<(1LL<<50)<<endl;

	cout<<maxi<<endl;
}