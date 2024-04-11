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
ll n,m; 
int check(ll val){
	ll val1;
	if(val%2==0){
		val1=val/2;
		val1*=(val+1);
	}
	else{
		val1=(val+1)/2;
		val1*=val;
	}
	if(n-val1<=m+val+1)
		return 1;
	return 0;
}
int main(){
	std::ios::sync_with_stdio(false);

	cin>>n>>m;
	ll ans=m;
	ll low=0;
	if(n<=m){
		cout<<n<<endl;
		return 0;
	}
	ll high=sqrt(n);
	high=sqrt(2*n);
	high=high+20;
	ll ans1=0;
	ll mid=(high+low)/2;
	while(low<=high){
		if(check(mid)){
			ans1=mid;
			high=mid-1;
		}
		else{
			low=mid+1;
		}
		mid=(low+high)/2;
	}
	cout<<ans1+m+1<<endl;
}