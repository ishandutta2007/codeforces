// Princess Consuela BananaHammock
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i=0;i<e;++i)
#define forsn(i,s,e) for(int i=s;i<e;++i)
#define rforn(i,s) for(int i=s;i>=0;--i)
#define rforsn(i,s,e) for(int i=s;i>=e;--i)
#define ln '\n'

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
const int LIM=2e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int tests = 1; 
	cin>>tests;

	while(tests -- ){
		ll p, q;
		ll op;
		cin>>p>>q;
		op = p;
		ll mi = p;
		forsn(i,2,1e5){
			if((q%i) == 0){
				ll c = 1;
				ll num = 0;
				while((q%i) == 0){
					num++;
					q /= i;
				}
				ll num2 = 0;
				while((p%i) == 0){
					num2++;
					p /= i;
				}
				forn(j,num2-num+1){
					c *= i;
				}
				mi = min(mi, c);
			}
		}
		if(q>1){
			ll num1 = 1;
			ll num2 = 0;
			while((p%q) == 0){
				p /= q;
				num2++;
			}
			ll c = 1;
			forn(j,num2-num1+1){
				c *= q;
			}
			mi = min(mi, c);
		}
		cout<<op/mi<<ln;


	}

	return 0;
}