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
bool ask(int x,int y){
	cout<<"? "<<x<<' '<<y<<endl;
	string a;
	cin>>a;
	assert(a!="e");
	return a=="x";
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	string s;cin>>s;
	while(s=="start"){
		int lo =2,hi=1e9;
		if(ask(0,1)){
			cout<<"! "<<1<<endl;
		}
		else{
			int st = 1,en=2;
			while(!ask(st,en)) {
				st=2*st,en=2*en;
				if(en>1e9) break;
			}
			lo = st+1,hi = en;
			while(lo<hi){
				int mid = (lo+hi)/2;
				if(ask(st,mid)) hi=mid;
				else lo = mid+1;
			}
			cout<<"! "<<lo<<endl;
		}
		cin>>s;
	}
	
	return 0;
}