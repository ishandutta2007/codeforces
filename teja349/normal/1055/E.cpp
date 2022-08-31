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

int n,s,m,k;
int bow=1;
int gg[12345],lol[12345],a[12345];
int visit[1512][1512],dp[1512][1512];

int getsum(int i,int j){
	int val=0;
	if(i!=0)
		val=gg[i-1];
	return gg[j]-val;
}
int compute(int lef,int pos){
	if(pos==n)
		return 0;
	if(lef==0)
		return 0;
	if(visit[lef][pos]==bow)
		return dp[lef][pos];
	visit[lef][pos]=bow;
	dp[lef][pos]=compute(lef,pos+1);
	int val=0;
	if(lol[pos]>=pos)
		val=getsum(pos,lol[pos])+compute(lef-1,lol[pos]+1);
	dp[lef][pos]=max(dp[lef][pos],val);
	return dp[lef][pos];
}
int check(int val){
	bow++;
	int i;
	rep(i,n){
		//cout<<lol[i]<<endl;
		if(a[i]<=val)
			gg[i]=1;
		else
			gg[i]=0;
		if(i>0)
			gg[i]+=gg[i-1];
	}
	if(compute(m,0)>=k)
		return 1;
	return 0;
}

int inv[12345];
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin>>n>>s>>m>>k;
    int i;
    map<int,int> mapi;
    map<int,int>::iterator it;
    rep(i,n){
    	cin>>a[i];
    	mapi[a[i]]=0;
    }
    int counter=0;
    for(it=mapi.begin();it!=mapi.end();it++){
    	it->ss=counter++;
    	inv[counter-1]=it->ff;
    }
    rep(i,n){
    	a[i]=mapi[a[i]];
    }
    int l,r;
    vii vec;
    rep(i,s){
    	cin>>l>>r;
    	l--;
    	r--;
    	vec.pb(mp(l,r));
    }
    sort(all(vec));
    int j=0,sofar=-1;
    rep(i,n){
    	while(j<s && vec[j].ff<=i){
    		if(vec[j].ss>sofar){
    			sofar=vec[j].ss;
    		}
    		j++;
    	}
    	lol[i]=sofar;
    }
    // cout<<check(0)<<endl;
    // return 0;
    int low=0;
    int high=counter-1;
    int mid,ans=-1;
    while(low<=high){
    	mid=(low+high)/2;
    	if(check(mid)){
    		ans=mid;
    		high=mid-1;
    	}
    	else{
    		low=mid+1;
    	}
    }
    if(ans!=-1)
    	ans=inv[ans];
    cout<<ans<<endl;
    return 0;
}