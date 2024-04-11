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
int dp[123][123],res[123][123],c[123][123];
int n;
int mult(int a[123][123],int b[123][123]){
	int i,j,k;
	rep(i,n){
		rep(j,n){
			c[i][j]=0;
		}
	}
	rep(i,n){
		rep(j,n){
			rep(k,n){
				c[i][j]+=a[i][k]*b[k][j];
				c[i][j]%=mod;
			}
		}
	}
	rep(i,n){
		rep(j,n){
			a[i][j]=c[i][j];
		}
	}

	return 0;
}
int a[123],b[123],invn;
int getprob(int val){
	val*=invn;
	val%=mod;
	return val;
}
int getpow(int a,int b){
	int res=1;
	while(b){
		if(b%2){
			res*=a;
			res%=mod;
		}
		b/=2;
		a*=a;
		a%=mod;
	}
	return res;
}
main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
	int k;
	cin>>n>>k;
	int i;
	invn=getpow(n*(n-1)/2,mod-2);
	int zero=0,one=0,wrong=0;
	rep(i,n){
		cin>>a[i];
		if(a[i]==0)
			zero++;
		else
			one++;
		b[i]=a[i];
	}
	sort(b,b+n);
	//int wrong=0;
	int j;
	rep(i,n){
		if(a[i]!=0 && b[i]==0)
			wrong++;
	}
	rep(i,n){
		rep(j,n){
			if(abs(i-j)>1){
				continue;
			}
			if(i==j){
				dp[i][j]+=getprob(zero*(zero-1)/2+one*(one-1)/2);
				dp[i][j]+=getprob(zero*(zero-1)/2-j*(j-1)/2-(zero-j)*(zero-j-1)/2);
				swap(zero,one);
				dp[i][j]+=getprob(zero*(zero-1)/2-j*(j-1)/2-(zero-j)*(zero-j-1)/2);
				swap(zero,one);
			}
			else if(i<j){
				
					
				dp[i][j]+=getprob(j*j);

			}
			else{
				dp[i][j]+=getprob((zero-j)*(one-j));
			}
			dp[i][j]%=mod;
		}
	}
	rep(i,n){
		rep(j,n){
			res[i][j]=0;
		}
		res[i][i]=1;
	}
	while(k){
		if(k%2){
			mult(res,dp);
		}
		k/=2;
		mult(dp,dp);
	}
	//cout<<wrong<<endl;
	cout<<res[0][wrong]<<endl;

    return 0;   
}