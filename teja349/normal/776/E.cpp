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
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx


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
int p[1234567]={0};
vl primes;

ll powerer(ll a,ll b){
	ll ans=1;
	if(b%2==1){
		ans*=a;
	}
	//ans%=mod;
	while(b/2!=0){
		b=b/2;
		a=a*a;
		//a%=mod;
		if(b%2==1){
			ans*=a;
			//ans%=mod;
		}

	}
	//ans%=mod;
	return ans;
} 
ll phi(ll val){
	ll i,counti;
	ll ans=1;
	rep(i,primes.size()){
		if(val==1){
			return ans;
		}
		counti=0;
		while(val%primes[i]==0){
			counti++;
			val/=primes[i];
		}
		if(counti!=0){
			ll value=powerer(primes[i],counti-1)*(primes[i]-1);
			//value%=mod;
			ans*=value;
			//ans%=mod;
		}


	}
	if(val!=1){
		ans*=(val-1);
	}
	//ans%=mod;
	return ans;
}
int main(){
	std::ios::sync_with_stdio(false);
	ll i,j;
	for(i=2;i*i<2000000;i++){
		if(p[i])
			continue;
		
		for(j=i*i;j<1000*1000+46;j+=i){
			p[j]=1;
		}

	}
	f(i,2,1000*1000+45){
		if(!p[i])
			primes.pb(i);
	}
	ll n,k;
	cin>>n>>k;
	k++;
	k/=2;
	rep(i,k){
		if(n==1)
			break;	
		n=phi(n);
	}
	n%=mod;
	cout<<n<<endl;

}