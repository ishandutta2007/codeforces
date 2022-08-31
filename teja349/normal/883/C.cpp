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

int main(){
    std::ios::sync_with_stdio(false);
    ll f,T,t0;
    cin>>f>>T>>t0;
    ll a1,a2,p1,p2,t1,t2;
    cin>>a1>>t1>>p1;
    cin>>a2>>t2>>p2;
    ll haha=min(t0,t1);
    haha=min(haha,t2);
    if(haha*f>T) {
    	cout<<-1<<endl;
    	return 0;
    }
    if(f*t0<=T){
    	cout<<0<<endl;
    	return 0;
    }
    ll ans=inf;
    ans*=ans;
    if(t1>t2){
    	swap(a2,a1);
    	swap(t2,t1);
    	swap(p2,p1);
    }
    ll val = f/a1;
    if(f%a1)
    	val++;
    if(f*t1<=T)
    	ans=val*p1;
    ll X=f/a1;
    X+=3;
    val=f*t0-T;
    ll val1=a1*(t0-t1);
    ll val2=a2*(t0-t2);
    ll i;
    ll y;
    

    if(t1<t0 && t2<t0){
    	rep(i,X){
    		haha=val-i*(val1);
    		if(haha<0){
    			y=0;
    		}
    		else{
    			y=haha/val2;
    			if(haha%val2)
    				y++;
    		}
    		if(a1*i+a2*y<=f){
    			ans=min(ans,p1*i+p2*y);
    		}
	    	haha=f-a1*i;
	    	haha=max(haha,(ll)0);
	    	y=haha/a2;
	    	if(haha%a2)
	    		y++;
	    	//cout<<haha<<endl;
	    	//y=max(0,y);
	    	if(a1*i*t1+haha*t2<=T){
	    		ans=min(ans,p1*i+p2*y);
	    	}
	    }
	    cout<<ans<<endl;
    }
    else if(t1>=t0){
    	val=(f*t0-T);
    	val/=(t0-t2);
    	if((f*t0-T)%(t0-t2))
    		val++;
    	val1=val/a2;
    	if(val%a2)
    		val1++;
    	cout<<val1*p2<<endl;
    }
    else {
    	swap(a2,a1);
    	swap(t2,t1);
    	swap(p2,p1);
    	val=(f*t0-T);
    	val/=(t0-t2);
    	if((f*t0-T)%(t0-t2))
    		val++;
    	val1=val/a2;
    	if(val%a2)
    		val1++;
    	cout<<val1*p2<<endl;
    }
    
    return 0;  
    
}