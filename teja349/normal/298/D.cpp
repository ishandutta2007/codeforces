
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
map< int,int > mapi;
map< int,int >::iterator it,itr;
int main(){
	std::ios::sync_with_stdio(false);
	int n,m,k,val,i;
	cin>>n>>m>>k;
	rep(i,n){
		cin>>val;
		if(mapi.find(val)!=mapi.end()){
			mapi[val]++;
		}
		else{
			mapi[val]=1;
		}
	}
	rep(i,m){
		cin>>val;
		if(mapi.find(val)!=mapi.end()){
			mapi[val]--;
		}
		else{
			mapi[val]=-1;
		}


	}
	ll sumi=0;
	it=mapi.end();
	itr=mapi.begin();
	//--itr;
	it--;
	
	
	// if(it==itr){
	// 	cout<<"daads";
	// }
	//cout<<mapi.size()<<endl;
	for(;it!=itr;it--){
		//cout<<"gd";
		sumi+=it->ss;
		if(sumi>0)
		{
			cout<<"YES"<<endl;
			return 0;
		}

	}
	sumi+=it->ss;
	if(sumi>0)
	{
		cout<<"YES"<<endl;
		return 0;
	}

	cout<<"NO"<<endl;
	return 0;
}