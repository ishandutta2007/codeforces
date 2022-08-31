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
#define infds (1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
ll iinf;
ll a[1234567];
ll nexti[1234567],fuck[1234567];
ll calc(ll x,ll y,ll k){
	//cout<<k<<endl;
	ll val,ans=0;
	val=k*iinf;
	ans=k*(iinf)*(iinf+1)/2+iinf+1;
	//cout<<ans<<endl;
	ans%=mod;
	x++;
	y++;
	ans-=k*(iinf)*(iinf+1)/2+iinf+1-x*(iinf+1);
	
	ans%=mod;
	val=x/k;
	if(x%k==0)
		val--;
	//cout<<<<endl;
	ans+=k*(val)*(val+1)/2+val+1-x*(val+1);
	ans%=mod;
	swap(x,y);
	ans-=k*(iinf)*(iinf+1)/2+iinf+1-x*(iinf+1);
	ans%=mod;
	val=x/k;
	if(x%k==0)
		val--;

	ans+=k*(val)*(val+1)/2+val+1-x*(val+1);
	ans%=mod;
	x+=y;
	//x--;
	ans+=k*(iinf)*(iinf+1)/2+iinf+1-x*(iinf+1);
	ans%=mod;
	val=x/k;
	if(x%k==0)
		val--;

	ans-=k*(val)*(val+1)/2+val+1-x*(val+1);
	ans--;
	ans%=mod;
	ans+=mod;
	ans%=mod;

	return ans;

}
int main(){
    std::ios::sync_with_stdio(false);
    iinf =infds;
    ll n,k;
    cin>>n>>k;
    ll i;
    rep(i,n){
    	cin>>a[i];
    }
    stack<ll> st;
    i=0;
    while(i<n){
    	if(!st.empty()){
    		while(!st.empty() && a[st.top()]<a[i]){
    			nexti[st.top()]=i;
    			st.pop();
    		}
    	}
    	st.push(i);
    	i++;
    		
    }
    while(!st.empty()){
    	nexti[st.top()]=n;
    	st.pop();
    }
    i=n-1;
    while(i>=0){
    	if(!st.empty()){
    		while(!st.empty() && a[st.top()]<=a[i]){
    			fuck[st.top()]=i;
    			st.pop();
    		}
    	}
    	st.push(i);
    	i--;
    }
    while(!st.empty()){
    	fuck[st.top()]=-1;
    	st.pop();
    }
    ll x,y;
    ll ans=0;
    ll haha;
    rep(i,n){
    	x=i-fuck[i]-1;
    	y=nexti[i]-i-1;
    	
    	haha=calc(x,y,k-1);
    	//cout<<x<<" "<<y<<" "<<haha<<endl;
    	haha%=mod;
    	ans+=haha*a[i];
    	ans%=mod;
    }
    cout<<ans<<endl;
    return 0;   
}