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

map<tri,bool> mapi;
int cnt[1234],nxt[1234];
int compute(int sum,int j,int invalid,int cur){
	if(j==0 && sum==0)
		return 1;	
	if(cur==0){
		return 0;
	}
	if(j<=0)
		return 0;
	if(sum<=0)
		return 0;
	int lef=j;
	if(mapi.find(mp(sum,mp(lef,cur)))!=mapi.end())
		return mapi[mp(sum,mp(lef,cur))];

	int val=0;
	int i;		
	rep(i,cnt[cur]+1){
		if(cur==invalid && i==1)
			break;
		if(compute(sum-i*cur,j-i,invalid,nxt[cur])){
			val=1;
			break;
		}
	}
	mapi[mp(sum,mp(lef,cur))]=val;
	return val;
}

int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
  	int n;
  	cin>>n;
  	int i;
  	int val;
  	rep(i,n){
  		cin>>val;
  		cnt[val]++;
  	}
  	int previ=0;
  	val=0;
  	f(i,1,105){
  		nxt[i]=previ;
  		if(cnt[i])
  			previ=i;
  		if(cnt[i])
  			val++;
  	}
  	int j;
  	int maxi=1;
  	//return 0;
  	//cout<<nxt[101]<<endl;
  	for(i=1;i<105;i++){
  		
  		if(cnt[i]==0)
  			continue;
  		//cout<<i<<endl;
  		mapi.clear();
  		f(j,1,cnt[i]+1){
  			//cout<<j<<endl;
  			if(compute(j*i,j,i,nxt[101])){
  				break;
  			}
  		}
  		if(j==cnt[i]+1 && val==2){
  			maxi=n;
  		}
  		maxi=max(maxi,j-1);
  	}
  	cout<<maxi<<endl;

    return 0;   
}