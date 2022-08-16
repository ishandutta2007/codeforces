
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
vi vec1,vec2;  
int n,l;
int check(){
	int i;
	rep(i,n){
		if(vec1[i]!=vec2[i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	std::ios::sync_with_stdio(false);
	int i;
	cin>>n>>l;
	int val,val1;
	cin>>val1;
	int val2=val1;
	rep(i,n-1){
		cin>>val;
		vec1.pb(val-val1);
		val1=val;
	}
	vec1.pb(l-val1+val2);
	cin>>val1;
	val2=val1;
	rep(i,n-1){
		cin>>val;
		vec2.pb(val-val1);
		val1=val;
	}
	vec2.pb(l-val1+val2);
	rep(i,n+29){
		if(check()==1){
			cout<<"YES";
			return 0;
		}
		val1=vec1[0];
		vec1.erase(vec1.begin());
		vec1.pb(val1);
	}
	cout<<"NO";
	return 0;
}