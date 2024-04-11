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
int iinf;
int x[123],y[123];
int manhattan(int i,int j){
	return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
int mult(int ax,int x,int bx){
	if(x>iinf/ax)
		return iinf;
	int val=ax*x+bx;
	if(val>=iinf)
		return iinf;
	return val;
}
main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
	int ax,ay,bx,by;
	cin>>x[0]>>y[0]>>ax>>ay>>bx>>by;
	int xs,ys,t;
	cin>>xs>>ys>>t;
	iinf = inf;
	iinf*=inf;
	iinf/=10;
	int i=0;
	int val;
	while(1){
		val=mult(ax,x[i],bx);
		if(val==iinf)
			break;
		x[i+1]=val;
		val=mult(ay,y[i],by);
		if(val==iinf)
			break;
		y[i+1]=val;
		i++;
	}	
	int n = i+1;
	x[n]=xs;
	y[n]=ys;
	int maxi=0,ans=0;
	int j,k;
	rep(i,n){
		rep(j,n){
			if(manhattan(i,n)+manhattan(i,j)<=t){
				ans=abs(i-j)+1;
			}
			else{
				ans=0;
			}
			maxi=max(ans,maxi);
		}
	}
	rep(i,n){
		rep(j,i){
			f(k,i+1,n){
				if(manhattan(i,n)+manhattan(i,j)+manhattan(j,k)<=t){
					ans=abs(i-k)+1;
				}
				else{
					ans=0;
				}
				maxi=max(ans,maxi);
				if(manhattan(i,n)+manhattan(i,k)+manhattan(j,k)<=t){
					ans=abs(i-k)+1;
				}
				else{
					ans=0;
				}
				maxi=max(ans,maxi);
			}
		}
	}
	cout<<maxi<<endl;
    return 0;   
}