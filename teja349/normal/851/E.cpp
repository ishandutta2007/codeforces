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
map<ll,ll> dp;
map<ll,ll> mapi;

ll grundy(ll val){
	if(val==1){
		return 0;
	}
	set<ll> seti;
	seti.clear();
	ll haha,papa;
	if(dp.find(val)!=dp.end()){
		return dp[val];
	}		
	ll i=1;
	while(val>=(1LL<<i)){
		haha=val%(1LL<<i);
		papa=val/(1LL<<i);
		seti.insert(grundy(haha|papa));
		i++;
	}
	rep(i,10000){
		if(seti.find(i)==seti.end()){
			dp[val]=i;
			return i;
		}
	}

}
vector<vl> vec(123);
ll factorise(ll ind,ll val){
	ll i;
	for(i=2;i*i<=val;i++){
		while(val%i==0){
			val/=i;
			vec[ind].pb(i);
			mapi[i]=0;
		}
	}
	if(val!=1){
		mapi[val]=0;
		vec[ind].pb(val);
	}
	return 0;
}
ll a[123];
ll lol[123456];
int main(){
    std::ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    ll i;
    rep(i,n){
    	cin>>a[i];
    }
    rep(i,n){
    	factorise(i,a[i]);
    }
    ll coutner=1;
    map<ll,ll>::iterator it;
    for(it=mapi.begin();it!=mapi.end();it++){
    	it->ss=coutner++;
    	//inv[it->ss-1]=it->ff;
    }
    //return 0;
    ll prev,counti,j;
    rep(i,n){
    	if(vec[i].empty())
    		continue;
    	//cout<<":Daads";
    	sort(vec[i].begin(),vec[i].end());
    	prev=vec[i][0];
    	counti=1;

    	f(j,1,vec[i].size()){
    		if(vec[i][j]!=prev){
    				//cout<<counti<<endl;
    				lol[mapi[prev]]|=(1LL<<counti);
    			
    			prev=vec[i][j];
    			counti=1;
    		}
    		else{
    			counti++;
    		}
    	}
    	lol[mapi[prev]]|=(1LL<<counti);

    }
    //return  0;
    ll ans=0;
    f(i,1,coutner){
    	//cout<<lol[i]<<endl;
    	ans^=grundy(lol[i]);
    }
    if(!ans)
    {	
    	cout<<"Arpa"<<endl;
    }
    else{
    	cout<<"Mojtaba"<<endl;
    }
    return 0;  
    
}