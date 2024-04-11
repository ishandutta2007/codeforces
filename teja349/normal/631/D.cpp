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

vii vec,vect,vecs;

int lcp[1234567];
int computelcp(){
	int i=1;
	int len=vecs.size();
	int j=0;
	while(i<len){
		if(vecs[i]==vecs[j]){
			lcp[i]=j+1;
			i++;
			j++;
		}
		else{
			if(j==0){
				lcp[i]=0;
				i++;
			}
			else{
				j=lcp[j-1];
			}
		}
	}
	return 0;
}
int meet[1234567];

int gao(string s,int &val1,int &val2){
	int i=0;
	val1=0;
	while(s[i]!='-'){
		val1*=10;
		val1+=s[i]-'0';
		i++;
	}
	i++;
	val2=s[i];
	return 0;
}

signed main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
  	int n,m;
  	cin>>n>>m;
  	int i,j;
  	int siz=0;
  	int val1,val2;
  	string ch;
  	//int siz=0;
  	rep(i,n){
  		cin>>ch;
  		gao(ch,val1,val2);
  		if(vec.empty()){
  			siz++;
  			vec.pb(mp(val1,val2));
  		}
  		else if(vec[siz-1].ss==val2){

  			vec[siz-1].ff+=val1;
  		}
  		else{
  			siz++;
  			vec.pb(mp(val1,val2));
  		}
  	}
  	siz=0;
  	rep(i,vec.size()){
  		vect.pb(vec[i]);
  	}
  	vec.clear();
  	//char ch;
  	rep(i,m){
  		cin>>ch;
  		gao(ch,val1,val2);
  		if(vec.empty()){
  			siz++;
  			vec.pb(mp(val1,val2));
  		}
  		else if(vec[siz-1].ss==val2){
  			vec[siz-1].ff+=val1;
  		}
  		else{
  			siz++;
  			vec.pb(mp(val1,val2));
  		}
  	}
  	int cnt=0;
  	if(vec.size()==1){
  		val1=vec[0].ff;
  		val2=vec[0].ss;
  		//cout<<val1<<endl;
  		rep(i,vect.size()){
  			if(vect[i].ss==val2 && vect[i].ff>=val1){
  				cnt+=vect[i].ff-val1+1;
  				//cout<<vect[i].ff<<endl;
  			}
  		}
  		cout<<cnt<<endl;
  		return 0;
  	}
  	f(i,1,vec.size()-1){
  		vecs.pb(vec[i]);
  	}
  	computelcp();

  	i=0;
  	j=0;
  	int gg=vect.size();
  	int len=vecs.size();
  	if(!vecs.empty()){
  		while(i<gg){
	  		if(vect[i]==vecs[j]){
	  			i++;
	  			j++;
	  		}
	  		else{
	  			if(j==0){
	  				i++;
	  			}
	  			else{
	  				j=lcp[j-1];
	  			}
	  		}
	  		if(j==len){
	  			j=lcp[j-1];
	  			meet[i]=1;
	  		}
	  	}
  	}
  	else{
  		f(i,1,gg){
  			meet[i]=1;
  		}

  	}
  	rep(i,gg){
  		if(meet[i]){
  			if(vec[len+1].ss==vect[i].ss && vec[len+1].ff<=vect[i].ff){
  				if(vec[0].ss==vect[i-len-1].ss && vec[0].ff<=vect[i-len-1].ff)
  					cnt++;
  			}
  		}
  	}
  	cout<<cnt<<endl;

    return 0;   
}