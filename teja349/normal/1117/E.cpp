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

int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin>>s;
    int n=s.length();
    int i,j,k,cnt=0;
    vi vec1,vec2,vec3;
    map<tri,int> mapi;
  	rep(i,26){
  		rep(j,26){
  			rep(k,26){
  				vec1.pb(i);
  				vec2.pb(j);
  				vec3.pb(k);	
  				mapi[mp(i,mp(j,k))]=cnt;
  				cnt++;
  				if(cnt==n+10)
  				break;		
  			}
  		}
  	}
  	string s1,s2,s3;
  	string x1,x2,x3;
  	rep(i,s.length()){
  		s1+=(char)('a'+vec1[i]);
  		s2+=(char)('a'+vec2[i]);
  		s3+=(char)('a'+vec3[i]);
  	}
  	cout<<"? "<<s1<<endl;
  	cin>>x1;
  	cout<<"? "<<s2<<endl;
  	cin>>x2;
  	cout<<"? "<<s3<<endl;
  	cin>>x3;
  	string ans=s;
  	rep(i,s.length()){
  		//cout<<mapi[mp(x1[i]-'a',mp(x2[i]-'a',x3[i]-'a'))]<<endl;
  		ans[mapi[mp(x1[i]-'a',mp(x2[i]-'a',x3[i]-'a'))]]=s[i];
  	}	
  	cout<<"! "<<ans<<endl;

    return 0;   
}