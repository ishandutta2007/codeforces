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


/** Z Algorithm **/
const int MAXN =5e5+5;
int z[MAXN];
int z_algo_construct(string s){
	int l=0,r=0;
	int i,n=s.length();
	f(i,1,s.length()){
		if(i>r){
			l=r=i;
			while (r < n && s[r-l] == s[r]) r++;
   			z[i] = r-l; r--;   			
		}
		else{
			int k=i-l;
			if(z[k]<r-i+1) z[i] = z[k];	
			else{
				l=i;
				while(r < n && s[r-l]==s[r])r++;
				z[i] = r-l; r--;
			}		
		}

	}
	return 0;
	
}
int dp[51234];
int n,a,b;
string s;
int visit[51234];
int compute(int pos){
	if(pos==n){
		return 0;
	}
	int i=pos;
	if(visit[i])
		return dp[i];
	visit[i]=1;
	string gg="";
	
	f(i,pos,n){
		gg+=s[i];
	}
	gg+='@';
	rep(i,pos){
		gg+=s[i];
	}
	i=pos;
	int haha=n-pos+1;
	dp[i]=compute(i+1)+a;
	z_algo_construct(gg);
	int maxi=0;
	f(i,haha,gg.length()){
		maxi=max(maxi,z[i]);
	}
	if(maxi>0){
		dp[pos]=min(dp[pos],compute(pos+maxi)+b);
	}
	return dp[pos];
}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
  	cin>>n>>a>>b;
  	cin>>s;
  	cout<<compute(0)<<endl;
    return 0;   
}