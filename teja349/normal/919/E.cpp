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
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);   
ll extend_gcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	ll x1,y1;
	ll ans =extend_gcd(b,a%b,x1,y1);
	x=y1;
	y=x1-(a/b)*y1;

	return ans;
}
ll haha[1234567];
int main(){
    std::ios::sync_with_stdio(false);
    ll a,b,p,lol;
    cin>>a>>b>>p>>lol;
    ll x,y,i=0;
    ll ans=1,flag=0;
    while(!flag || ans!=1){
    	flag=1;
    	haha[i]=ans;
    	ans*=a;
    	ans%=p;
    	i++;
    }
    //cout<<i<<endl;
    //return 0;
    ll per=i;
    extend_gcd(p,per,x,y);
    ll invper=y%p;
    invper+=p;
    invper%=p;
    ll invprim=x%per;
    invprim+=per;
    invprim%=per;
    ll bigmod=p*per,val;
    ans=0;
    //cout<<bigmod<<endl;
    rep(i,per){
    	extend_gcd(p,haha[i],x,y);
    	y%=p;
    	y+=p;
    	y%=p;
    	y*=b;
    	y%=p;
    	x=i;

    	val=x*p*invprim+y*per*invper;
    	val%=bigmod;
    	ans+=lol/bigmod;
    	//cout<<i<<" "<<ans<<endl;
    	if(lol%bigmod>=val){
    		ans++;
    	}
    }
    cout<<ans<<endl;
    return 0;  
    
}