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

int cnt[123];
int a[123][123];
bitset<300> bad[(1<<17)+10];
int badd[(1<<17)+10];
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
  	int n,p;
  	cin>>n>>p;
  	string s;
  	cin>>s;
  	int i,j,k;
  	rep(i,s.length()){
  		cnt[s[i]-'a']++;
  	}
  	rep(i,p){
  		rep(j,p){
  			cin>>a[i][j];
  		}
  	}
  	int ch1,ch2,last,val;
  	rep(i,p){
  		f(j,i,p){
  			if(a[i][j]==1)
  				continue;
  			ch1='a'+i;
  			ch2='a'+j;
  			last=-1;
  			val=0;
  			int haha=i*17+j;
  			rep(k,s.length()){
  				if(s[k]==ch1){
  					if(last==ch2){
  						bad[val][haha]=1;
  					}
  					last=ch1;
  					val=0;
  				}
  				else if(s[k]==ch2){
  					if(last==ch1){
  						bad[val][haha]=1;
  					}
  					last=ch2;
  					val=0;
  				}
  				else{
  					val|=(1<<(s[k]-'a'));
  				}

  			}
  		}
  	}
  	int mini=s.length(),ans;
  	f(i,1,(1<<p)){
  		rep(j,p){
  			if(i&(1<<j)){
  				bad[i]|=bad[i^(1<<j)];
  			}
  		}
  		rep(j,p){
  			if((1<<j)&i)
  				continue;
  			f(k,j,p){
  				if((1<<k)&i)
  					continue;
  				if(bad[i][j*17+k]){
  					badd[i]=1;
  					break;
  				}
  			}
  		}
  		if(badd[i])
  			continue;
  		badd[i]=1;
  		rep(j,p){
  			if(i&(1<<j) && !badd[i^(1<<j)]){
  				badd[i]=0;
  			}
  		}
  		if(!badd[i]){
  			//cout<<i<<endl;
  			ans=0;
  			rep(j,p){
  				if(i&(1<<j)){
  					ans+=cnt[j];
  				}
  			}
  			mini=min(mini,n-ans);
  		}
  	}
  	cout<<mini<<endl;

    return 0;   
}