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
#define inf (1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false); 
ll pr[1234568];
ll preprocess(){
	ll i,j;
	for(i=2;i<1234567;i++){
		if(pr[i])
			continue;
		pr[i]=i;
		for(j=i*i;j<1234567;j+=i){
			if(!pr[j])
				pr[j]=i;
		}
	}

	return 0;
}  
vl vec;
set<ll> seti;
ll getfactors(ll val){
	seti.clear();
	while(val!=1){
		seti.insert(pr[val]);
		val/=pr[val];
	}
	set<ll>::iterator it;
	for(it=seti.begin();it!=seti.end();it++){
		vec.pb(*it);
	}
	seti.clear();
	return 0;
}
ll sig;
ll getnumber(ll num){
	ll i=0,boo=1;
	sig=0;
	while(num>0){
		if(num%2){
			boo*=vec[i];
			sig^=1;
		}
		i++;
		num/=2;
	}
	if(!sig)sig=-1;
	return boo;
}
ll compute(ll p,ll val){
	ll sz=vec.size();
	ll i,ans=0,lol;
	f(i,1,(1<<sz)){
		lol=getnumber(i);
		ans+=sig*(val-val/lol);
	}	
	return ans;
}
int main(){
    std::ios::sync_with_stdio(false);
    ll t;
    cin>>t;
    preprocess();
    while(t--){
    	
    	ll x,p,k;
    	cin>>x>>p>>k;
    	if(p==1){
    		cout<<x+k<<endl;
    		continue;
    	}
    	vec.clear();
    	getfactors(p);
    	ll val=compute(p,x);
    	ll low=x+1;
    	ll high=inf;
    	high*=inf;
    	ll mid,ans,val1;
    	while(low<=high){
    		mid=(low+high)/2;
    		val1=compute(p,mid);
    		if(val1-val<k){
    			low=mid+1;
    		}
    		else{
    			//cout<<val1<<" "<<mid<<endl;
    			ans=mid;
    			high=mid-1;
    		}

    	}
    	cout<<ans<<endl;

    }
    return 0;  
    
}