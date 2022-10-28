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
string s[300009],t[300009];
string ops[6] = {"AG","AT","AC","GC","GT","CT"};
string ops2[6] = {"CT","GC","GT","AT","AC","GA"};
int tot[6][2];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	int m;cin>>m;
	rep(i,n) cin>>s[i],t[i]=s[i];
	int ans =0,ansix1,ansix2;
	rep(op,6){
		rep(i,n){
			if(i%2){
				int cnt1=0;
				rep(j,m){
					if(j%2&&s[i][j]==ops[op][0]) cnt1++;
					if(j%2==0&&s[i][j]==ops[op][1]) cnt1++;
				}
				int cnt2=0;
				rep(j,m){
					if(j%2&&s[i][j]==ops[op][1]) cnt2++;
					if(j%2==0&&s[i][j]==ops[op][0]) cnt2++;
				}
				tot[op][0]+=max(cnt1,cnt2);
			}
			else{
				int cnt1=0;
				rep(j,m){
					if(j%2&&s[i][j]==ops2[op][0]) cnt1++;
					if(j%2==0&&s[i][j]==ops2[op][1]) cnt1++;
				}
				int cnt2=0;
				rep(j,m){
					if(j%2&&s[i][j]==ops2[op][1]) cnt2++;
					if(j%2==0&&s[i][j]==ops2[op][0]) cnt2++;
				}
				tot[op][0]+=max(cnt1,cnt2);
			}
		}
		if(tot[op][0]>ans) ans=tot[op][0],ansix1=0,ansix2=op;
	}
	rep(op,6){
		rep(j,m){
			if(j%2){
				int cnt1=0;
				rep(i,n){
					if(i%2&&s[i][j]==ops[op][0]) cnt1++;
					if(i%2==0&&s[i][j]==ops[op][1]) cnt1++;
				}
				int cnt2=0;
				rep(i,n){
					if(i%2&&s[i][j]==ops[op][1]) cnt2++;
					if(i%2==0&&s[i][j]==ops[op][0]) cnt2++;
				}
				tot[op][1]+=max(cnt1,cnt2);
			}
			else{
				int cnt1=0;
				rep(i,n){
					if(i%2&&s[i][j]==ops2[op][0]) cnt1++;
					if(i%2==0&&s[i][j]==ops2[op][1]) cnt1++;
				}
				int cnt2=0;
				rep(i,n){
					if(i%2&&s[i][j]==ops2[op][1]) cnt2++;
					if(i%2==0&&s[i][j]==ops2[op][0]) cnt2++;
				}
				tot[op][1]+=max(cnt1,cnt2);
			}
		}
		if(tot[op][1]>ans) ans=tot[op][1],ansix1=1,ansix2=op;
	}
	if(ansix1){
		int op = ansix2;
		rep(j,m){
			if(j%2){
				int cnt1=0;
				rep(i,n){
					if(i%2&&s[i][j]==ops[op][0]) cnt1++;
					if(i%2==0&&s[i][j]==ops[op][1]) cnt1++;
				}
				int cnt2=0;
				rep(i,n){
					if(i%2&&s[i][j]==ops[op][1]) cnt2++;
					if(i%2==0&&s[i][j]==ops[op][0]) cnt2++;
				}
				if(cnt1>cnt2){
					rep(i,n) {
						if(i%2) t[i][j] = ops[op][0];
						else t[i][j]=ops[op][1];
					}
				}
				else{
					rep(i,n) {
						if(i%2) t[i][j] = ops[op][1];
						else t[i][j]=ops[op][0];
					}
				}
			}
			else{
				int cnt1=0;
				rep(i,n){
					if(i%2&&s[i][j]==ops2[op][0]) cnt1++;
					if(i%2==0&&s[i][j]==ops2[op][1]) cnt1++;
				}
				int cnt2=0;
				rep(i,n){
					if(i%2&&s[i][j]==ops2[op][1]) cnt2++;
					if(i%2==0&&s[i][j]==ops2[op][0]) cnt2++;
				}
				if(cnt1>cnt2){
					rep(i,n) {
						if(i%2) t[i][j] = ops2[op][0];
						else t[i][j]=ops2[op][1];
					}
				}
				else{
					rep(i,n) {
						if(i%2) t[i][j] = ops2[op][1];
						else t[i][j]=ops2[op][0];
					}
				}
			}
		}
	}
	else{
		int op = ansix2;	
		rep(i,n){
			if(i%2){
				int cnt1=0;
				rep(j,m){
					if(j%2&&s[i][j]==ops[op][0]) cnt1++;
					if(j%2==0&&s[i][j]==ops[op][1]) cnt1++;
				}
				int cnt2=0;
				rep(j,m){
					if(j%2&&s[i][j]==ops[op][1]) cnt2++;
					if(j%2==0&&s[i][j]==ops[op][0]) cnt2++;
				}
				if(cnt1>cnt2){
					rep(j,m){
						if(j%2) t[i][j] = ops[op][0];
						else t[i][j] = ops[op][1];
					}
				}
				else{
					rep(j,m){
						if(j%2==0) t[i][j] = ops[op][0];
						else t[i][j] = ops[op][1];
					}
				}
			}
			else{
				int cnt1=0;
				rep(j,m){
					if(j%2&&s[i][j]==ops2[op][0]) cnt1++;
					if(j%2==0&&s[i][j]==ops2[op][1]) cnt1++;
				}
				int cnt2=0;
				rep(j,m){
					if(j%2&&s[i][j]==ops2[op][1]) cnt2++;
					if(j%2==0&&s[i][j]==ops2[op][0]) cnt2++;
				}
				if(cnt1>cnt2){
					rep(j,m){
						if(j%2) t[i][j] = ops2[op][0];
						else t[i][j] = ops2[op][1];
					}
				}
				else{
					rep(j,m){
						if(j%2==0) t[i][j] = ops2[op][0];
						else t[i][j] = ops2[op][1];
					}
				}
			}
		}
	}
	rep(i,n) cout<<t[i]<<'\n';
	return 0;
}