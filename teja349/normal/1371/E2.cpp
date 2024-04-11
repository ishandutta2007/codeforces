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
int a[123456],b[123456],c[123456],haha[123456],pre[123456];
map<int,int> mapi;
main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n,p;
    cin>>n>>p;
    int i,j;
    rep(i,n){
    	cin>>a[i];
    	mapi[a[i]]++;
    }
    int counter=0;
    int mini=0,sofar=0;
    map<int,int>::iterator it;
    for(it=mapi.begin();it!=mapi.end();it++){
    	b[counter]=it->ff;
    	c[counter]=it->ss;
    	if(sofar<b[counter]){
    		mini+=b[counter]-sofar;
    		sofar=b[counter];
    	}
    	if(counter==0){
    		haha[0]=c[0];
    	}
    	else{
    		haha[counter]=c[counter]+haha[counter-1];
    	}
    	sofar+=c[counter];
    	counter++;
    }

    int m=counter;
    if(m==1){
    	cout<<0<<endl;
    	return 0;
    }
    pre[0]=0;
    f(i,1,m){
    	pre[i]=pre[i-1]+b[i-1]-b[i]+c[i];
    }
    int maxi=pre[m-1];
    int val,gao;
    //cout<<mini<<endl;
    set<int> seti;
    fd(i,m-1,1){
    	val=maxi-pre[i];
    	if(val<0)
    		val=0;
    	val+=c[i];
    	val=p-val-1;
    	val=min(val,haha[i-1]);
    	gao=haha[i-1]-b[i]+b[i-1];
    	
    	if(gao<=val && haha[i-1]<p){
    		f(j,max(b[i-1],mini),b[i-1]+val-gao+1){
    			seti.insert(j);
    		}
    	}
    	maxi=max(maxi,pre[i]);
    }
    cout<<seti.size()<<endl;
    set<int>::iterator it1;
    for(it1=seti.begin();it1!=seti.end();it1++){
    	cout<<*it1<<" ";
    }
    cout<<endl;
    return 0;   
}