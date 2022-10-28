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
bool ans[3][25][163];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n){
		rep(j,n){
			int x;cin>>x;
			if(x){
				int r = (9*i+j)*2+1;
				if(i<j){
					ans[2][3*i+1][r]=1;
					ans[2][3*j-1][r]=1;
					ans[0][3*i+1][r] = 1;
					ans[0][3*j-1][r] = ans[0][3*j-2][r] = 1;
					repA(k,3*i+1,3*j-2) ans[1][k][r] = 1;
				}
				else{
					ans[2][3*i-1][r]=1;
					ans[2][3*j+1][r]=1;
					ans[0][3*i-1][r] = 1;
					ans[0][3*j+1][r] = ans[0][3*j+2][r] = 1;
					repD(k,3*i-1,3*j+2) ans[1][k][r] = 1;
				}
			}
		}
	}
	cout<<25<<' '<<163<<' '<<3<<'\n';	
	rep(i,163) {
		rep(j,25){
			if(j%3==0&&i==0&&j<3*n) cout<<j/3+1;
			else if(j%3==0||ans[2][j][i]) cout<<'.';
		else cout<<'#';
	}
	cout<<'\n';
	}
	rep(l,2){
		rep(i,163){
			rep(j,25){
				if(ans[l][j][i]) cout<<'.';
				else cout<<'#';
			}
			cout<<'\n';
		}
	}
	
	return 0;
}