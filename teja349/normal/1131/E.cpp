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

string p[123456];
int bad[123456];
int ans[1234],suf[1234],pref[1234];
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
  	int n;
  	cin>>n;
  	int i,j,k;
  	rep(i,n){
  		cin>>p[i];
  	}
  	rep(i,n){
  		bad[i]=0;
  		rep(j,p[i].length()){
  			if(p[i][j]!=p[i][0]){
  				bad[i]=1;
  				break;
  			}
  		}
  	}
  	i=n-1;
  	int cnt=0;
  	rep(j,p[i].length()){
  		if(j==0){
  			cnt=1;
  		}
  		else{
  			if(p[i][j-1]==p[i][j]){
  				cnt++;
  			}
  			else{
  				cnt=1;
  			}
  		}
  		ans[p[i][j]]=max(ans[p[i][j]],cnt);
  	}
  	int val=1;
  	f(j,1,p[i].length()){
  		if(p[i][j]==p[i][j-1]){
  			val++;
  		}
  		else{
  			break;
  		}
  	}
  	pref[p[i][0]]=val;
  	//cout<<val<<endl;
  	int sz=p[i].size();
  	val=1;
  	fd(j,sz-2,0){
  		if(p[i][j]==p[i][j+1]){
  			val++;
  			
  		}
  		else{
  			break;
  		}
  	}
  	suf[p[i][sz-1]]=val;
  	//cout<<val<<endl;
  	int curlen=p[i].length();
  	if(bad[i]==0){
  		fd(i,n-2,0){
  			if(bad[i]==0 && p[i][0]==p[i+1][0]){
  				val=p[i].size();
  				curlen=curlen*(val+1)+val;
  				ans[p[i][0]]=curlen;
  				suf[p[i][0]]=curlen;
  				pref[p[i][0]]=curlen;
  				continue;
  			}
  			if(bad[i]==0){
  				break;
  			}
  			
  			cnt=0;
  			rep(j,p[i].length()){
  				if(j==0 && p[i][j]==p[i+1][0]){
  					cnt=1;
  				}
  				else{
  					if(p[i][j]==p[i][j-1] && p[i][j]==p[i+1][0])
  						cnt++;
  					else if(p[i][j]==p[i+1][0])
  						cnt=1;
  					else
  						cnt=0;
  				}
  				ans[p[i+1][0]]=max(ans[p[i+1][0]],pref[p[i+1][0]]*(cnt+1)+cnt);
  				ans[p[i][j]]=max(1,ans[p[i][j]]);
  			}
  			rep(j,p[i].length()){
  				if(p[i][j]!=p[i+1][0])
  					break;
  			}
  			pref[p[i+1][0]]=pref[p[i+1][0]]*(j+1)+j;
  			sz=p[i].size();
  			fd(j,sz-1,0){
  				if(p[i][j]!=p[i+1][0])
  					break;
  			}
  			j=sz-1-j;
  			suf[p[i+1][0]]=suf[p[i+1][0]]*(j+1)+j;
  			//ans[p[i+1][0]]=max(pref[p[i+1][0]],suf[p[i+1][0]]);
  			i--;
  			break;
  		}
  	}
  	else{
  		i=n-2;
  	}
  	fd(j,i,0){
  		rep(k,p[j].length()){
  			ans[p[j][k]]=max(ans[p[j][k]],1+suf[p[j][k]]+pref[p[j][k]]);
  		}
  	}
  	int maxi=0;
  	rep(i,200){
  		maxi=max(maxi,ans[i]);
  	}
  	cout<<maxi<<endl;
    return 0;   
}