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
ll cnt[1234],rota[1234]; 
ll getlevel(ll val){
	ll i=0;
	while(val>0){
		i++;
		val/=2;
	}
	return i-1;
}
ll getpos(ll x,ll lev){
	ll st=cnt[lev];
	ll posi;
	st-=rota[lev];
	if(st<cnt[lev]){
		st+=cnt[lev];
	}
	
		posi=x-st+cnt[lev];
	if(posi<cnt[lev]){
		posi+=cnt[lev];
	}
	return posi;
}
ll getval(ll posi,ll lev){
	posi-=cnt[lev];
	ll st=cnt[lev];
	
	st-=rota[lev];
	if(st<cnt[lev]){
		st+=cnt[lev];
	}
	st+=posi;
	if(st>=2*cnt[lev]){
		st-=cnt[lev];
	}
	return st;
}
int main(){
    std::ios::sync_with_stdio(false);
    ll q;
    cin>>q;
    ll i=0;
    ll haha=1;
    ll diinf=inf;
    diinf*=inf;
    diinf*=2;
    //cout<<diinf<<endl;
    while(1){
    	cnt[i]=haha;
    	if(cnt[i]>=diinf)
    		break;
    	i++;

    	haha*=2;
    }
    

    ll typ,x,k,lev;
    while(q--){
    	cin>>typ;
    	//cout<<typ<<endl;
    	if(typ==1){
    		cin>>x>>k;
    		lev=getlevel(x);
    		//k%=cnt[lev];
    		k%=cnt[lev];
    		k+=cnt[lev];
    		k%=cnt[lev];
    		rota[lev]+=k;
    		rota[lev]%=cnt[lev];
    	}
    	else if(typ==2){

    		cin>>x>>k;
    		
    		lev=getlevel(x);

    		k%=cnt[lev];
    		k+=cnt[lev];
    		k%=cnt[lev];
    		if(k==0)
    			continue;
    		
    		i=lev;
    		while(i<=61){
    			//cout<<k<<endl;
    			rota[i]+=k;
    			rota[i]%=cnt[i];
    			if(k>=diinf)
    				break;

    			k*=2;
    			i++;
    		}

    	}
    	else{
    		cin>>x;
    		ll lev=getlevel(x);
    		ll val=getpos(x,lev);
    		while(lev>=0){
    			cout<<getval(val,lev)<<" ";
    			//val+=cnt[lev]+1;
    			val/=2;
    			lev--;

    		}
    		cout<<endl;
    	}
    }
    return 0;  
    
}