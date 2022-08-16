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
ll val1,val2;
ll n,m,k;
int check(ll val){
	val1=0;
	val2=0;
	ll i;
	f(i,1,n+1){
		val2+=min(val/i,m);
		
		val1+=min((val-1)/i,m);
	}
	return 0;

}
int main(){
	std::ios::sync_with_stdio(false);
	
	cin>>n>>m>>k;
	ll high=n*m+1;
	ll low=1;
	ll mid=(low+high)/2;
	while(low<=high){
		check(mid);
		//cout<<val1<<" "<<val2<<"  "<<mid<<endl;
		if(val1>=k){
			high=mid-1;
		}
		else if(val2<k){
			low=mid+1;
		}
		else{
			cout<<mid<<endl;
			return 0;
		}
		mid=(low+high)/2;

	}

	return 0;
}