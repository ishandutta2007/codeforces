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
ll compute(ll n){
	ll low=2;
	ll high=n-1;
	ll ans=n-1;
	ll mid,val1,val2,left;
	while(low<=high){
		mid=(high+low)/2;
		val1=(mid+mid-1);
		val2=(mid)*(mid+1)/2;
		left=n-1-mid;
		if(left<val1){
			//ans=left;
			high=mid-1;
		}
		else if(left>=val2){
			ans=max(ans,left+val2);
			low=mid+1;
		}
		else{
			ans=max(ans,2*left);
			high=mid-1;
		}
	}
	return ans;
}
int lol[120];
int main(){
    std::ios::sync_with_stdio(false);
	int q;
	cin>>q;
	lol[1]=0;
	lol[2]=1;
	lol[3]=2;
	lol[4]=3;
	lol[5]=4;
	lol[6]=6;
	while(q--){
		ll n;
		cin>>n;
		if(n<7){
			cout<<lol[n]<<endl;
			continue;
		}
		cout<<compute(n)<<endl;

	}
    
}