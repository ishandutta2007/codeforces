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
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
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
#define tri pair<ll,pll>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< tri >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false); 
pqueue pq;
map<pll,ll > mapi;
ll n,m,r,k;
ll valid(ll a,ll b){
	if(a<0 || a>=n ||b<0 || b>=m)
		return 0;
	if(mapi.find(mp(a,b))!=mapi.end())
		return 0;
	mapi[mp(a,b)]=1;
	return 1;
}
ll valueat(ll a,ll b){

	ll haha=r;
	ll lol=1;
	ll ans=1;
	haha=min(haha,a+1);
	lol=max(lol,r+1-(n-a));
	ans*=(haha-lol+1);
	haha=r;
	lol=1;
	
	haha=min(haha,b+1);
	lol=max(lol,r+1-(m-b));
	ans*=(haha-lol+1);
	//cout<<a<<" "<<b<<" "<<lol*haha<<endl;
	return ans;
}
int main(){
    std::ios::sync_with_stdio(false);
    
    cin>>n>>m>>r>>k;
    mapi[mp(n/2,m/2)]=1;
    tri papa=mp(valueat(n/2,m/2),mp(n/2,m/2));
    pq.push(papa);
    ll u,v,i,j;
    //cout<<k<<":dassda"<<endl;
    double ans=0;
    ll val=(n-r+1)*(m-r+1);
    while(k>0){
    	papa=pq.top();
    	pq.pop();
    	ans+=papa.ff;

    	u=papa.ss.ff;
    	v=papa.ss.ss;
    	f(i,-1,2){
    		f(j,-1,2){
    			if(valid(u+i,v+j)){
    				papa=mp(valueat(u+i,v+j),mp(u+i,v+j));
    				pq.push(papa);
    			}
    		}
    	}
    	k--;
    }
    ans/=(n-r+1);
    ans/=(m-r+1);
    cout<<setprecision(22)<<ans<<endl;
    return 0;  
    
}