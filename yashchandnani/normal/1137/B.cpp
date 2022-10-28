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
int pi(const string& s) {
		vi p(sz(s));
			repA(i,1,sz(s)-1) {
						int g = p[i-1];
								while (g && s[i] != s[g]) g = p[g-1];
										p[i] = g + (s[i] == s[g]);
											}
				return p.back();
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	string s,t;cin>>s>>t;
	int x=0,y=0;
	trav(i,s) if(i=='0') x++; else y++;
	int z = pi(t);
	string ans = t;
	trav(i,t){
		if(i=='0') x--;
		else y--;
	}
	if(x<0||y<0){
		cout<<s<<'\n';
		exit(0);
	}
	string m = t.substr(z,sz(t)-z);
	int xx=0,yy=0;
	trav(i,m) if(i=='0') xx++; else yy++;
	while(x>=xx&&y>=yy) ans+=m,x-=xx,y-=yy;
	while(x) ans+="0",x--;
	while(y) ans+="1",y--;
	cout<<ans;
	return 0;
}