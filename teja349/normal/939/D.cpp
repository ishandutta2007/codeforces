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
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

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
int dsu[123456];
int par(int u){
	if(dsu[u]<0)
		return u;
	dsu[u]=par(dsu[u]);
	return dsu[u];
}
vii vec;
int merge(int u,int v){
	u=par(u);
	v=par(v);
	if(u==v)
		return 0;
	vec.pb(mp(u,v));
	if(dsu[u]<dsu[v])
		swap(u,v);
	dsu[v]+=dsu[u];
	dsu[u]=v;

}
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    int i;
    rep(i,12345){
    	dsu[i]=-1;
    }
    rep(i,n){
    	if(s1[i]!=s2[i]){
    		merge(s1[i],s2[i]);
    	}
    }
    cout<<vec.size()<<endl;
    rep(i,vec.size()){
    	cout<<(char)vec[i].ff<<" "<<(char)vec[i].ss<<endl;
    }

    return 0;  
    
}