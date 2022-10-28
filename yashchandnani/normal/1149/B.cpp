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
vi a[3],b[3];
int dp[259][259][259];
int nxt[200009][30];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	int q;cin>>q;
	string s;cin>>s;
	rep(j,27){
		nxt[sz(s)+1][j] = sz(s)+1;
		nxt[sz(s)][j] = sz(s)+1;
		repD(i,n-1,0){
			if(s[i]-'a'==j) nxt[i][j]=i+1;
			else nxt[i][j] = nxt[i+1][j];
		}
	}
	rep(i,q){
		char c,d;int x;
		cin>>c>>x;x--;
		if(c=='+') {
			cin>>d;
			a[x].pb(int(d-'a'));
			if(x==1){
				repA(j,sz(a[1]),sz(a[1])){
					repA(k,0,sz(a[2])){
						repA(l,0,sz(a[0])){
							dp[l][j][k] = n+1;
							if(l) dp[l][j][k] = min(dp[l][j][k],nxt[dp[l-1][j][k]][a[0][l-1]]);
							if(j) dp[l][j][k] = min(dp[l][j][k],nxt[dp[l][j-1][k]][a[1][j-1]]);
							if(k) dp[l][j][k] = min(dp[l][j][k],nxt[dp[l][j][k-1]][a[2][k-1]]);
						}
					}
				}
			}
			if(x==2){
				repA(j,0,sz(a[1])){
					repA(k,sz(a[2]),sz(a[2])){
						repA(l,0,sz(a[0])){
							dp[l][j][k] = n+1;
							if(l) dp[l][j][k] = min(dp[l][j][k],nxt[dp[l-1][j][k]][a[0][l-1]]);
							if(j) dp[l][j][k] = min(dp[l][j][k],nxt[dp[l][j-1][k]][a[1][j-1]]);
							if(k) dp[l][j][k] = min(dp[l][j][k],nxt[dp[l][j][k-1]][a[2][k-1]]);
						}
					}
				}
			}
			if(x==0){
				repA(j,0,sz(a[1])){
					repA(k,0,sz(a[2])){
						repA(l,sz(a[0]),sz(a[0])){
							dp[l][j][k] = n+1;
							if(l) dp[l][j][k] = min(dp[l][j][k],nxt[dp[l-1][j][k]][a[0][l-1]]);
							if(j) dp[l][j][k] = min(dp[l][j][k],nxt[dp[l][j-1][k]][a[1][j-1]]);
							if(k) dp[l][j][k] = min(dp[l][j][k],nxt[dp[l][j][k-1]][a[2][k-1]]);
						}
					}
				}
			}
		}
		else a[x].pop_back();
		if(dp[sz(a[0])][sz(a[1])][sz(a[2])]<=n) cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}