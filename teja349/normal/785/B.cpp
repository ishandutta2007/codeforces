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
vii vec1,vec2,vec3,vec4;
int main(){
	std::ios::sync_with_stdio(false);
	int i,n,m,l,r,ans=0;
	cin>>n;
	rep(i,n){
		cin>>l>>r;
		vec1.pb(mp(l,r));
		vec2.pb(mp(r,l));

	}
	cin>>m;
	rep(i,m){
		cin>>l>>r;
		vec3.pb(mp(l,r));
		vec4.pb(mp(r,l));

	}
	
	pii par1=*min_element(vec2.begin(),vec2.end());
	pii par2=*max_element(vec3.begin(),vec3.end());
	ans=max(ans,par2.ff - par1.ff);
	par1=*min_element(vec4.begin(),vec4.end());
	 par2=*max_element(vec1.begin(),vec1.end());
	ans=max(par2.ff - par1.ff,ans);
	cout<<ans<<endl;

}