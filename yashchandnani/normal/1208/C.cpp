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
int a[1009][1009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	int x = 0;
	rep(j,n/2){
		rep(i,n/4){
			a[4*i][2*j] = x;
			a[4*i][2*j+1] = x+4;
			a[4*i+1][2*j] = x+1;
			a[4*i+1][2*j+1] = x+5;
			a[4*i+2][2*j] = x+2;
			a[4*i+2][2*j+1] = x+6;
			a[4*i+3][2*j] = x+3;
			a[4*i+3][2*j+1] = x+7;
			x+=8;
		}
	}
	rep(i,n) {
		rep(j,n) cout<<a[i][j]<<' ';
		cout<<'\n';
	}
	return 0;
}