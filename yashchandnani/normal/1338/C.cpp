#include <bits/stdc++.h>
using namespace std;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void pre(){


}

void solve(){
	ll l = 1;
	ll n ;cin>>n;
	ll r = (n-1)/3;
	ll cnt = 0;
	while(cnt+l<=r){
		cnt+=l;
		l=4*l;
	}
	if(n%3==1){
		cout<<l+r-cnt<<'\n';
	}
	else if(n%3==2){
		l=2*l;
		ll x = r-cnt;
		ll z = 1;
		while(x){
			if(x%4==1){
				l+=2*z;
			}
			else if(x%4==2){
				l+=3*z;	
			}
			else if(x%4==3) l+=z;
			x/=4;
			z=z*4;
		}
		cout<<l<<'\n';
	}
	else{
		l=3*l;
		ll x = r-cnt;
		ll z = 1;
		while(x){
			if(x%4==1){
				l+=3*z;
			}
			else if(x%4==2){
				l+=1*z;	
			}
			else if(x%4==3) l+=2*z;
			x/=4;
			z=z*4;
		}
		cout<<l<<'\n';
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) solve();
	return 0;
}