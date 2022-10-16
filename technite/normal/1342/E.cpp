#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define pb push_back
#define mp make_pair
typedef long long ll;
ll R = 998244353;
 
ll power(ll x, ll y)  
{  
    ll res = 1;
    x = x % R;
    if (x == 0) return 0;
    while (y > 0)  
    {  
        if (y%2==1)  
            res = (res*x) % R;  
        y/=2;
        x = (x*x) % R;
    }  
    return res;  
} 
 
ll modInverse(ll n) { 
    return power(n, R-2);
} 
ll ncr(ll n, ll r) 
{ 
	if (r==0) return 1; 
    	vector<ll>fac(n+1,1); 
    	for (ll i=1 ; i<=n; i++) 
		fac[i] = fac[i-1]*i%R; 
    	return ((fac[n]*modInverse(fac[r]) % R)*modInverse(fac[n-r])%R)%R;
} 
void printvector(vector<int> v)
{
	for (int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<"\n";
}
int main()
{
	ll n,k;cin>>n>>k;
	if(k>=n){
		cout<<0<<'\n';
		return 0;
	}
	ll o = n-k;
	ll C = 1;
	ll sum=0;
	for(ll i=0;i<o;i++){
		ll extra = (C*power(o-i,n))%R;
		if(i%2==0){
			sum=((sum+extra)%R);
		}
		else{
			sum=((sum-extra+R)%R);	
		}
		C = (C*(o-i))%R;
		C = (C*(modInverse(i+1))) %R;
	}	
	ll temp = (sum*ncr(n,k))%R;
	if(k>0){
		cout<<(temp*2)%R<<'\n';
	}
	else{
		cout<<temp<<'\n';
	}
}