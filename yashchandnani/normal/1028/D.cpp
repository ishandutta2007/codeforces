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

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	set<int> a,b,c;
	ll ways = 1;
	rep(i,n){
		string s;cin>>s;
		int x;cin>>x;
		if(s=="ADD"){
			if(!a.empty()&&x<*a.rbegin()) a.insert(x);
			else if(!b.empty()&&x>*b.begin()) b.insert(x);
			else c.insert(x);
		}
		else{
			if((!a.empty()&&x<*a.rbegin())||(!b.empty()&&x>*b.begin())) ways = 0;
			else {
				if(a.find(x)!=a.end()) a.erase(x);
				else if(b.find(x)!=b.end()) b.erase(x);
				else{
					ways*=2;
					ways%=1000000007;
				}
				trav(i,c) {
					if(i<x) a.insert(i);
					else if(i>x) b.insert(i);
				}
				c.clear();
			}
		}
	}
	ways*=sz(c)+1;
	ways%=1000000007;
	cout<<ways;
	return 0;
}