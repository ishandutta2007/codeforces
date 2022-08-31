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
int k;
string s,a,b;
int used[123],taken[123],remtaken[123],remused[123];
#define endl '\n'

int printans(){
	int i=0;
	int j=0;
	rep(i,k){
		if(taken[i]!=-1)
			continue;
		while(used[j])
			j++;
		taken[i]=j;
		used[j]=1;
	}
	cout<<"YES"<<endl;
	string ans="";
	rep(i,k){
		ans+=(char)('a'+taken[i]);
	}
	cout<<ans<<endl;
	return 0;
}
int lefsolve(int i){
	if(i==s.length()){
		return 1;	
	}
	int val=s[i]-'a';
	if(taken[val]!=-1){
		if(taken[val]>a[i]-'a'){
			return 1;
		}
		if(taken[val]<a[i]-'a'){
			return 0;
		}
		else if(taken[val]==a[i]-'a'){
			return lefsolve(i+1);
		}
	}
	else{
		int flag=0,j;
		f(j,a[i]-'a'+1,k){
			if(!used[j])
			{
				flag=1;
				break;
			}
		}
		if(flag){
			taken[val]=j;
			used[j]=1;
			return 1;
		}
		if(!used[a[i]-'a']){
			taken[val]=a[i]-'a';
			used[a[i]-'a']=1;
			return lefsolve(i+1);
		}
		return 0;
	}
}
int rightsolve(int i){
	if(i==s.length()){
		return 1;	
	}
	int val=s[i]-'a';
	if(taken[val]!=-1){
		if(taken[val]<b[i]-'a'){
			return 1;
		}
		if(taken[val]>b[i]-'a'){
			return 0;
		}
		else if(taken[val]==b[i]-'a'){
			return rightsolve(i+1);
		}
	}
	else{
		int flag=0,j;
		f(j,0,b[i]-'a'){
			if(!used[j])
			{
				flag=1;
				break;
			}
		}
		if(flag){
			taken[val]=j;
			used[j]=1;
			return 1;
		}
		if(!used[b[i]-'a']){
			taken[val]=b[i]-'a';
			used[b[i]-'a']=1;
			return rightsolve(i+1);
		}
		return 0;
	}
}
// int createtest(){
// 	k=26;
// 	int i;
// 	rep(i,k){
// 		vec.pb(i);
// 	}
// 	int len=10;
// 	a="";
// 	rep(i,len){
// 		a+=getff();
// 	}
// 	int val=getrand(0,len-1);
// 	s="";
// 	rep(i,val){
// 		s+=a[i];
// 	}
// 	s+=(a[i])
// 	rep(i,k){

// 	}
// }
int solve(){
	
	cin>>k;
	
	cin>>s>>a>>b;
	int i;
	rep(i,k){
		used[i]=0;
		taken[i]=-1;
	}
	int j,val;
	rep(i,a.length()){
		if(a[i]==b[i]){
			val=s[i]-'a';
			if(taken[val]==-1){
				if(used[a[i]-'a']){
					cout<<"NO"<<endl;
					return 0;
				}
				taken[val]=a[i]-'a';
				used[a[i]-'a']=1;
			}
			else{
				if(taken[val]!=a[i]-'a'){
					cout<<"NO"<<endl;
					return 0;
				}
			}
		}
		else{
			break;
		}
	}
	if(i==s.length()){
		printans();
		return 0;
	}
	val=s[i]-'a';
	if(taken[val]!=-1){
		if(taken[val]>b[i]-'a'){
			cout<<"NO"<<endl;
			return 0;
		}
		if(taken[val]<a[i]-'a'){
			cout<<"NO"<<endl;
			return 0;
		}
		if(taken[val]==a[i]-'a'){
			if(lefsolve(i+1)){
				printans();
				return 0;
			}
			cout<<"NO"<<endl;
			return 0;
		}
		if(taken[val]==b[i]-'a'){
			if(rightsolve(i+1)){
				printans();
				return 0;
			}
			cout<<"NO"<<endl;
			return 0;
		}
		printans();
		return 0;
	}
	else{
		int flag=0;
		f(j,a[i]-'a'+1,b[i]-'a'){
			if(!used[j]){
				flag=1;
				break;
			}
		}
		if(flag){
			taken[val]=j;
			used[j]=1;
			printans();
			return 0;
		}
		if(used[a[i]-'a']==0){
			rep(j,k){
				remtaken[j]=taken[j];
				remused[j]=used[j];
			}
			taken[val]=a[i]-'a';
			used[a[i]-'a']=1;
			if(lefsolve(i+1)){
				printans();
				return 0;
			}
			rep(j,k){
				taken[j]=remtaken[j];
				used[j]=remused[j];
			}
		}
		if(used[b[i]-'a']==0){
			rep(j,k){
				remtaken[j]=taken[j];
				remused[j]=used[j];
			}
			taken[val]=b[i]-'a';
			used[b[i]-'a']=1;
			if(rightsolve(i+1)){
				printans();
				return 0;
			}
			rep(j,k){
				taken[j]=remtaken[j];
				used[j]=remused[j];
			}
		}
		cout<<"NO"<<endl;
		return 0;
	}

}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
  	int t;
  	cin>>t;
  	while(t--){
  		//createtest();
  		solve();
  	}
    return 0;   
}