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

vector<vi> vec(512345);
int a[512345],b[512345],c[512345],d[512345],sumi[512345];
main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    int i;
    rep(i,n){
    	cin>>a[i];
    }
    sort(a,a+n);
    int ans=0,cur=0;
    fd(i,n-1,0){
    	ans+=cur;
    	cur+=a[i];
    }
    if(k==0){
    	cout<<ans<<endl;
    	return 0;
    }
    int sofar=0,cur1=0;
    fd(i,n-1,0){
    	if(a[i]<0)
    		break;
    	sofar+=cur1;
    	cur1+=a[i];
    }
    int left=i+1;
    if(left==0){
    	cout<<ans<<endl;
    	return 0;
    }
    b[0]=0;
    c[0]=0;
    int j=1;
    fd(i,left-1,0){
    	b[j]=b[j-1]+c[j-1];
    	c[j]=c[j-1]+a[i];
    	j++;
    }
    k++;
    rep(i,left){
    	sumi[i/k]+=a[i];
    	vec[i/k].pb(sumi[i/k]);
    }
    sumi[0]=0;
    f(i,1,left+2){
    	sumi[i]*=i;
    	sumi[i]+=sumi[i-1];
    }
    k--;
    int gg,lol,haha,bow,wow;
    f(i,1,left){
    	gg=left-i;
    	lol=gg/k;
    	haha=gg%k;
    	bow=0;
    	if(haha!=0)
    		bow=1;
    	if(i<lol+bow){
    		continue;
    	}
    	wow=i-(lol+bow);
    	if(haha!=0)
    		haha++;
    	int vali=sofar+i*cur1+b[wow]+(lol+bow)*c[wow];
    	if(lol>0)
    		vali+=sumi[lol-1];
    	if(haha>0)
    		vali+=vec[lol][haha-1]*(lol);
    	//cout<<i<<" "<<vali<<endl;
    	ans=max(ans,vali);
    }
    cout<<ans<<endl;


    return 0;
}