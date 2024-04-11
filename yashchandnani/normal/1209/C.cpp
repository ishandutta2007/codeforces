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
int ans[200009];
char p[200009];
void solve(){
	int n;cin>>n;
	string s,t1,t2;cin>>s;
	p[n-1]=s[n-1];
	char x = '9';
	repD(i,n-2,0){
		p[i] = min(p[i+1],s[i]);
		if(s[i]!=p[i]){
			x=min(x,s[i]);
		}
	}
	rep(i,n){
		if(s[i]<x) ans[i]=1,t1+=s[i];
		else if(s[i]>x) ans[i]=2,t2+=s[i];
		else if(s[i]==p[i]) ans[i]=1,t1+=s[i];
		else ans[i]=2,t2+=s[i];
	}
	t1+=t2;
	repA(i,1,n-1){
		if(t1[i]<t1[i-1]) {
			cout<<'-'<<'\n';
			return;
		}
	}
	rep(i,n) cout<<ans[i];
	cout<<'\n';

}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) solve();	
	return 0;
}