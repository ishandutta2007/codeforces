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
typedef pair<pii, pii> pi;
typedef vector<int> vi;

void pre(){


}

void solve(){


}
string s[309][309],t[309][309];
int c[309][2],d[309][2];
vector<pi> ans;
void mov(int x1,int y1,int x2,int y2){
	ans.pb(mp(mp(x1,y1),mp(x2,y2)));
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,m;cin>>n>>m;
	rep(i,n) {
		rep(j,m) {
			cin>>s[i][j];
			reverse(all(s[i][j]));
		}
	}
	rep(i,n) {
		rep(j,m) {
		cin>>t[i][j];
		reverse(all(t[i][j]));
		}
	}
	rep(i,n){
		rep(j,m){
			trav(k,s[i][j]) if(!((k=='0'&&j==0)||(k=='1'&&j==1))) d[i][k-'0']++;
			trav(k,t[i][j]) if(!((k=='0'&&j==0)||(k=='1'&&j==1)))c[i][k-'0']++;
		}
	}
	rep(i,n){
		rep(j,m){
			trav(k,s[i][j]){
				if(k=='0') {
					if(j==0) {
						if(i==0) {
							mov(i,j,1,0);d[1][0]++;
						}
						else mov(i,j,0,0);
					}
					else mov(i,j,i,0);
				}
				else {
					if(j==1){
						if(i==0){
							mov(i,j,1,1); d[1][1]++;
						}
						else mov(i,j,0,1);
					}
					else mov(i,j,i,1);
				}
			}
		}
	}
	repA(i,1,n-1){
		rep(k,d[i][0]) mov(i,0,0,0);
	}
	repA(i,1,n-1){
		rep(k,d[i][1]) mov(i,1,0,1);
	}
	trav(i,t[0][0]) if(i=='0') c[1][0]++;
	trav(i,t[0][1]) if(i=='1') c[1][1]++;
	repA(i,1,n-1){
		rep(k,c[i][0]) mov(0,0,i,0);
	}
	repA(i,1,n-1){
		rep(k,c[i][1]) mov(0,1,i,1);
	}
	rep(i,n){
		rep(j,m){
			trav(k,t[i][j]){
				if(k=='0') {
					if(j==0) {
						if(i==0){
							mov(1,0,i,j);
						}
						else mov(0,0,i,j);
					}
					else mov(i,0,i,j);
				}
				else{
					if(j==1){
						if(i==0){mov(1,1,i,j);}
						else mov(0,1,i,j);
					}
					else mov(i,1,i,j);
				}
			}
		}
	}
	cout<<sz(ans)<<'\n';
	trav(i,ans) cout<<i.fst.fst+1<<' '<<i.fst.snd+1<<' '<<i.snd.fst+1<<' '<<i.snd.snd+1<<'\n';
	return 0;
}