#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
using pii = pair<int,int>; 
using db = double; 
using vi = vector<int>; 
using vl = vector<ll>; 
#define fir first
#define sec second
#define pb push_back
#define lowbit(x) ((x)&(-(x))) 

ll n,k,a,b;

ll cnt(ll p) {
	return n*k/__gcd(p,n*k);
}

ll x,y; 

void refresh(ll t) {
	x = min(x,t); 
	y = max(y,t); 
}

int main() {
	scanf("%lld%lld%lld%lld",&n,&k,&a,&b);
	x = n*k; y=0; 
	for(ll i=k*2;i<=n*k+k;i+=k){
		ll t = cnt(i+a+b);
		refresh(t); 
		t = cnt(i-a+b);
		refresh(t); 
		t = cnt(i+a-b);
		refresh(t); 
		t = cnt(i-a-b);
		refresh(t); 
	} 
	cout<<x<<' '<<y<<endl; 
}