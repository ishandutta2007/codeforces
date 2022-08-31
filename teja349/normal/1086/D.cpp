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
ordered_set setr,setp,sets;
int calcs(){
	ordered_set::iterator it,it1;
	int ans=0;
	int val2,val1;
	if(setr.empty()){
		return sets.size();
	}
	if(setp.empty()){
		if(setr.empty()){
			return sets.size();
		}
		else{
			return 0;
		}
	}
	if(sets.empty())
		return 0;
	it=setp.begin();
	it1=setp.end();
	it1--;
	val1=*it;
	val2=*it1;
	it=setr.upper_bound(val1);

	if(it==setr.begin()){
		ans+=sets.order_of_key(val1);
	}
	else{
		it=setr.begin();
		ans+=sets.order_of_key(*it);
	}
	it=setr.upper_bound(val2);
	if(it==setr.end()){
		ans+=(int)sets.size()-(int)sets.order_of_key(val2);
	}
	else{
		it=setr.end();
		it--;
		ans+=(int)sets.size()-(int)sets.order_of_key(*it);
	}
	ans+=(int)sets.order_of_key(val2)-(int)sets.order_of_key(val1);
	return ans;
}

int calcr(){
	ordered_set::iterator it,it1;
	int ans=0;
	int val2,val1;
	if(setp.empty()){
		return setr.size();
	}
	if(sets.empty()){
		if(setp.empty()){
			return setr.size();
		}
		else{
			return 0;
		}
	}
	if(setr.empty())
		return 0;
	it=sets.begin();
	it1=sets.end();
	it1--;
	val1=*it;
	val2=*it1;
	it=setp.upper_bound(val1);
	if(it==setp.begin()){
		
		ans+=setr.order_of_key(val1);
	}
	else{
		it=setp.begin();
		ans+=setr.order_of_key(*it);
	}
	it=setp.upper_bound(val2);
	if(it==setp.end()){
		ans+=(int)setr.size()-(int)setr.order_of_key(val2);
	}
	else{
		it=setp.end();
		it--;
		ans+=(int)setr.size()-(int)setr.order_of_key(*it);
	}
	ans+=(int)setr.order_of_key(val2)-(int)setr.order_of_key(val1);
	return ans;
}

int calcp(){
	ordered_set::iterator it,it1;
	int ans=0;
	int val2,val1;
	if(sets.empty()){
		return setp.size();
	}
	if(setr.empty()){
		if(sets.empty()){
			return setp.size();
		}
		else{
			return 0;
		}
	}
	if(setp.empty())
		return 0;
	it=setr.begin();
	it1=setr.end();
	it1--;
	val1=*it;
	val2=*it1;
	it=sets.upper_bound(val1);
	if(it==sets.begin()){
		
		ans+=setp.order_of_key(val1);
	}
	else{
		it=sets.begin();
		ans+=setp.order_of_key(*it);
	}
	it=sets.upper_bound(val2);
	if(it==sets.end()){
		ans+=(int)setp.size()-(int)setp.order_of_key(val2);
	}
	else{
		it=sets.end();
		it--;
		ans+=(int)setp.size()-(int)setp.order_of_key(*it);
	}
	ans+=(int)setp.order_of_key(val2)-(int)setp.order_of_key(val1);
	//cout<<(int)setp.order_of_key(val2)-(int)setp.order_of_key(val1)<<endl;
	return ans;
}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
  	int n,q,i;
  	cin>>n>>q;
  	string s;
  	cin>>s;
  	rep(i,n){
  		if(s[i]=='R')
  			setr.insert(i);
  		else if(s[i]=='P')
  			setp.insert(i);
  		else
  			sets.insert(i);
  	}
  	int pos;
  	char ch;
  	int j;
  	//cout<<calcp()<<endl;
  	cout<<calcs()+calcp()+calcr()<<endl;
  	rep(j,q){
  		cin>>pos>>ch;
  		pos--;
  		i=pos;
  		if(s[i]=='R')
  			setr.erase(i);
  		else if(s[i]=='P')
  			setp.erase(i);
  		else
  			sets.erase(i);
  		s[i]=ch;
  		if(s[i]=='R')
  			setr.insert(i);
  		else if(s[i]=='P')
  			setp.insert(i);
  		else
  			sets.insert(i);
  		cout<<calcs()+calcp()+calcr()<<endl;
  	}
    return 0;   
}