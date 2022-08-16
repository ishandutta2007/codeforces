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

int bit[1234567];
int update(int pos,int val){
	while(pos<1e6+10){
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

int x[123456],a[123456],b[123456];

main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int START =0;
    int END = 1e6;
    int cnt=1;
    int i;
    int y,l,r;
    vii vec,adder,remov;
    rep(i,n){
    	cin>>y>>l>>r;
    	if(l==START && r==END){
    		cnt++;
    	}
    	adder.pb(mp(l,y));
    	remov.pb(mp(r,y));
    }
    sort(all(adder));
    sort(all(remov));
    rep(i,m){
    	cin>>x[i]>>a[i]>>b[i];
    	vec.pb(mp(x[i],i));
    }
    sort(all(vec));
    int j=0,k=0,haha=0,bow;
    rep(bow,vec.size()){
    	int i=vec[bow].ss;
    	while(j<adder.size() && adder[j].ff<=vec[bow].ff){
    		haha++;
    		update(adder[j].ss,1);
    		j++;
    	}
    	while(k<remov.size() && remov[k].ff<vec[bow].ff){
    		haha--;
    		update(remov[k].ss,-1);
    		k++;
    	}
    	if(a[i]==START && b[i]==END){
    		cnt+=haha+1;
    	}
    	else{
    		if(a[i]==0){
    			int val=query(b[i]);
    			cnt+=val;
    			//cout<<val<<endl;
    		}
    		else{
    			int val=haha-query(a[i]-1);
    			cnt+=val;
    			//cout<<val<<endl;
    		}
    	}
    	

    }
    cout<<cnt<<endl;

    return 0;   
}