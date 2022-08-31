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
#define int ll
// find_by_order()  // order_of_key
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int getpow(int a,int b){
	int res=1;
	while(b){
		if(b%2){
			res*=a;
			res%=mod;
		}
		a*=a;
		a%=mod;
		b/=2;
	}
	return res;
}
int pop[123];
int getpowee(int val){
	if(val>20){
		return inf;
	}
	else
		return pop[val];
}
int getmul(int val1,int val2){
	return val1*val2;
}
int a[1234567];
main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	int n,p;
    	cin>>n>>p;
    	
    	int i,j;
    	rep(i,n){
    		cin>>a[i];
    	}
    	if(p==1){
    		cout<<n%2<<endl;
    		continue;
    	}
    	pop[0]=1;
    	f(i,1,23){
    		pop[i]=pop[i-1]*p;
    		if(pop[i]>inf)
    			pop[i]=inf;
    	}
    	sort(a,a+n);
    	int cnt=1;
    	int cur=a[n-1];
    	fd(i,n-2,0){
    		int cnt1=getmul(cnt,getpowee(cur-a[i]));
    		if(cnt1>n){
    			break;
    		}
    		cnt=cnt1;
    		cur=a[i];
    		if(cnt==0){
    			cnt++;
    		}
    		else{
    			cnt--;
    		}
    	}
    	int val=getpow(p,cur);
    	val*=cnt;
    	val%=mod;
    	rep(j,i+1){
    		val-=getpow(p,a[j]);
    		val%=mod;
    	}
    	val+=mod;
    	val%=mod;
    	cout<<val<<endl;
    }
    return 0;   
}