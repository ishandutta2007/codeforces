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

ll inv[1000203],mult[1000203],invmult[1000203];
ll gcd(ll a,ll b){
	while(b!=0){
		
		a=a%b;
		swap(a,b);
	}
	return a;
}

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

ll combination(ll n,ll r){
	if(r==0)
		return 1;
	if(n<r)
		return 0;
	ll ans=1;
	ans*=mult[n];
	ans%=mod;
	ans*=invmult[r];
	ans%=mod;
	ans*=invmult[n-r];
	ans%=mod;
	return ans;
}

ll initcombi(){
	int i;
	f(i,1,1000201){
		ll x,y;
		ll val=extend_gcd(mod,i,x,y);
		if(y>0)
			inv[i]=y%mod;
		else{
				inv[i]=(y+mod)%mod;
		}
	}
	mult[0]=1;
	f(i,1,1000201){
		mult[i]=mult[i-1]*i;
		mult[i]%=mod;
	}
	invmult[0]=1;
	f(i,1,1000201){
		invmult[i]=invmult[i-1]*inv[i];
		invmult[i]%=mod;
	}
	return 0;
}

int pr[1000200];
ll two[1000200];
ll factor(int x,int y){
	int prev=-1;
	ll ans=1,cnt=0;

	while(x!=1){
		//cout<<x<<endl;
		if(prev!=pr[x]){
			
			ans*=combination(y+cnt-1,cnt);
			prev=pr[x];
			cnt=1;
			ans%=mod;
		}
		else{
			cnt++;
		}
		x/=pr[x];

	}
	ans*=combination(y+cnt-1,cnt);
	ans%=mod;
	return ans;
}

// do initcombi();

int main(){
    std::ios::sync_with_stdio(false);
    initcombi();
    ll i,j,k;
	f(i,2,1000020){
		//cout<<pr[i]<<" "<<i<<endl;
		if(pr[i])
			continue;
		pr[i]=i;
		for(j=i*i;j<1000020;j+=i){
			if(!pr[j])
				pr[j]=i;
		}
	}

	int q;
	cin>>q;
	ll x,y,ans,val;
	two[0]=1;
	f(i,1,1000020){
		two[i]=two[i-1]*2;
		two[i]%=mod;
	}
	rep(j,q){
		cin>>x>>y;
		ans=0;
		ans=factor(x,y);
		ans*=two[y-1];
		ans%=mod;
		cout<<ans<<endl;
	}
	
    return 0;  
    
}