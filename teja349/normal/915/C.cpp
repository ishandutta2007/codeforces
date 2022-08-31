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
ll haha[100],dig[100],ten[100];   
ll getans(){
	ll i,j;
	ll ans=0;
	fd(i,9,0){
		rep(j,haha[i]){
			ans*=10;
			ans+=i;
		}
	}
	return ans;
}
int main(){
    std::ios::sync_with_stdio(false);
    ll a,b;
    cin>>a>>b;
    ll b1=b;
    ll cntb=0;
    while(b1>0){
    	dig[cntb]=b1%10;
    	cntb++;
    	b1/=10;
    }
    ll a1=a;
    ll cnta=0;
    ll i,j;
    while(a1>0){
    	cnta++;
    	haha[a1%10]++;
    	a1/=10;
    }
    ten[0]=1;
    f(i,1,19){
    	ten[i]=ten[i-1]*10;
    }
    if(cnta<cntb){
    	fd(i,9,0){
    		rep(j,haha[i]){
    			cout<<i;
    		}
    	}
    	cout<<endl;
    	return 0;
    }
    ll flag=1,previ=0,ans=0,elem,val;
    fd(i,cntb-1,0){
    	elem=-1;
    	f(j,flag,dig[i]){
    		if(haha[j])
    			elem=j;
    	}
    	if(elem!=-1){
    		haha[elem]--;
	    	
	    	val=getans();
	    	ans=max(ans,previ+elem*ten[i]+val);
	    	haha[elem]++;
    	}
    	flag=0;
    	if(haha[dig[i]]){
    		haha[dig[i]]--;
    		previ+=dig[i]*ten[i];
    		if(i==0){
    			ans=max(ans,previ);
    		}
    	}
    	else{

    		//booh=1;
    		break;
    	}
    }
    cout<<ans<<endl;

    return 0;  
    
}