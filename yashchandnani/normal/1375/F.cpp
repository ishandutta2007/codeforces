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


}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	ll a,b,c;cin>>a>>b>>c;
	cout<<"First"<<endl;
	ll mx = max({a,b,c});
	cout<<mx<<endl;
	int p;cin>>p;
	if(p==0) return 0;
	if(p==1) a+=mx;
	if(p==2) b+=mx;
	if(p==3) c+=mx;
	ll a1 = min({a,b,c}),a3=max({a,b,c}),a2 = a+b+c-a1-a3;
	ll x = a2-a1,y=a3-a2;
	cout<<x+2*y<<endl;
	mx=x+2*y;
    cin>>p;
	if(p==0) return 0;
	if(p==1) a+=mx;
	if(p==2) b+=mx;
	if(p==3) c+=mx;
	a1 = min({a,b,c}),a3=max({a,b,c}),a2 = a+b+c-a1-a3;
	x = a2-a1,y=a3-a2;
	assert(x==y);
	cout<<x<<endl;
	cin>>p;
	assert(p==0);
	return 0;
}