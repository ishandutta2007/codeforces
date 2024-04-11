#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;


#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
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
ll lo=1,hi;
ll n,k;
void hf(){
	ll mid = (lo+hi)/2;
	cout<<lo<<' '<<mid<<endl;
	string s;cin>>s;
	if(s=="Yes"){
		hi = mid;
	}
	else lo = mid+1;
}

void inc(){
	lo = max(1ll,lo-k);
	hi =min(n,hi+k);
}
bool chk(){
	ll m = rand()%(hi-lo+1) +lo;
	cout<<m<<' '<<m<<endl;
	string s;cin>>s;
	if(s=="Yes"){
		return 1;
	}
	return 0;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	srand(time(0));
	cin>>n>>k;
	hi = n;
	while(1){
		if(hi-lo>100) hf();
		else if(chk()) break;
		inc();
	}
	return 0;
}