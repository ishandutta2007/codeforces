// teja349
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


//helper functions
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


int main(){
	std::ios::sync_with_stdio(false);
	int n,x;
	int i;
	cin>>n>>x;
	if(n==1){
		cout<<"YES"<<endl;
		cout<<x<<endl;
		return 0;
	}	
	if(n==2){
		if(x==0)
			cout<<"NO"<<endl;
		else{
			cout<<"YES"<<endl;
			cout<<0<<" "<<x<<endl;
		}
		return 0;
	}
	cout<<"YES"<<endl;
	cout<<(1<<17)+(1<<18)<<" "<<(1<<17)<<" ";
	int ans=(1<<18);
	rep(i,n-3){
		cout<<i<<" ";
		ans^=i;
	} 
	ans^=x;
	cout<<ans<<endl;

	return 0;  
}