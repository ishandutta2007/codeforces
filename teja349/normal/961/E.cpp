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
int bit[212345],total=0;
int update(int pos,int val){
	total+=val;
	while(pos<212345){
		bit[pos]+=val;
		pos+=pos&(-pos);
	}
	return 0;
}
int query(int pos){
	int ans=0;
	while(pos>0){
		ans+=bit[pos];
		pos-=pos&(-pos);
	}
	return ans;
}
int a[212345];
vii vec;
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    f(i,1,n+1){
    	cin>>a[i];
    	update(i,1);
    	vec.pb(mp(a[i],i));
    }
    sort(all(vec));
    int j=0;
    ll ans=0;
    f(i,1,n+1){
    	while(j<n && vec[j].ff<i){
    		update(vec[j].ss,-1);
    		j++;
    	}
    	ans+=query(max(min(n+10,a[i]),i))-query(i);
    }
    cout<<ans<<endl;



    return 0;  
    
}