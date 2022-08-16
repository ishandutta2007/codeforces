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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
using namespace __gnu_pbds;

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
#define flush fflush(stdout) 
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// find_by_order()  // order_of_key
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

#define int ll
vi gg1,gg2,gg3;
int perm[312345];
int s[312345],t[312345],diff[312345];
int move(int pos1,int pos2){
	gg1.pb(pos1);
	gg2.pb(pos2);
	if(diff[pos1]<=(s[pos2]-s[pos1])/2){
		gg3.pb(diff[pos1]);
		diff[pos2]+=diff[pos1];
		s[pos2]-=diff[pos1];
		s[pos1]+=diff[pos1];
		diff[pos1]=0;
	}
	else{
		int val=(s[pos2]-s[pos1])/2;
		gg3.pb(val);
		diff[pos2]+=val;
		s[pos2]-=val;
		s[pos1]+=val;
		diff[pos1]-=val;
	}
	return 0;
}
main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    int i;
    int sum1=0,sum2=0;
    vii veci;
    rep(i,n){
   	 	cin>>s[i];
   	 	veci.pb(mp(s[i],i));
    	sum1+=s[i];
    	
    }
    sort(all(veci));
    rep(i,n){
    	perm[i]=veci[i].ss;
    	s[i]=veci[i].ff;
    }
    rep(i,n){
    	cin>>t[i];
    	sum2+=t[i];
    }
    sort(t,t+n);
   	vi vec;
   	rep(i,n){
    	diff[i]=t[i]-s[i];
    	if(diff[i]<0)
    		vec.pb(i);
    }
    if(sum1!=sum2){
    	cout<<"NO"<<endl;
    	return 0;
    }
    int j=0;
    rep(i,n){
    	if(diff[i]==0)
    		continue;
    	if(diff[i]<0){
    		cout<<"NO"<<endl;
    		return 0;
    	}	
    	while(diff[i]){
    		move(i,vec[j]);
    		if(diff[vec[j]]>=0)
    			j++;
    	}
    }
    cout<<"YES"<<endl;
    cout<<gg1.size()<<endl;
    rep(i,gg1.size()){
    	cout<<perm[gg1[i]]+1<<" "<<perm[gg2[i]]+1<<" "<<gg3[i]<<endl;
    }
    return 0;   
}