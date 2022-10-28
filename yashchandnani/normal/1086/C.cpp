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
int m1[26],m2[26],ans[26];
int cp1[26],cp2[26];
vi g[26];
bool chk(int a,int b){
	if(m1[a]!=-1&&m1[a]!=b) return 0;
	if(m2[b]!=-1&&m2[b]!=a) return 0;
	return 1;
}
void stor(int k){
	rep(i,k) cp1[i] = m1[i],cp2[i]=m2[i];
}
void rec(int k){
	rep(i,k) m1[i]=cp1[i],m2[i]=cp2[i];
}
void solve(){
	int k;cin>>k;
	string s,a,b;cin>>s>>a>>b;
	rep(i,26) m1[i]=-1,m2[i]=-1;
	int ix = sz(s);
	rep(i,sz(s)){
		if(a[i]!=b[i]) {
			ix = i;
			break;
		}
		int ss = s[i]-'a',aa=a[i]-'a';
		if(m1[ss]!=-1&&m1[ss]!=aa){
			cout<<"NO\n";
			return;
		}
		if(m2[aa]!=-1&&m2[aa]!=ss){
			cout<<"NO\n";
			return;
		}
		m1[ss]=aa;m2[aa]=ss;
	}
	bool fg = 0;
	if(ix<sz(s)){
		int aa = a[ix]-'a',bb=b[ix]-'a',ss=s[ix]-'a';
		repA(i,aa+1,bb-1){
			if(chk(ss,i)){
				m1[ss]=i,m2[i]=ss;
				fg = 1; break;
			}
		}
		if(!fg&&chk(ss,aa)){
			stor(k);
			m1[ss]=aa,m2[aa]=ss;
			fg=1;
			repA(i,ix+1,sz(s)-1){
				int ss = s[i]-'a',aa=a[i]-'a';
				bool fg2=0;
				repD(j,k-1,aa+1){
					if(chk(ss,j)){
						m1[ss]=j,m2[j]=ss;
						fg2=1;
						break;
					}
				}
				if(fg2) break;
				if(chk(ss,aa)){
					m1[ss]=aa,m2[aa]=ss;
				}
				else {
					fg=0;
					break;
				}
			}
			if(!fg) rec(k);
		}
		if(!fg&&chk(ss,bb)){
			m1[ss]=bb,m2[bb]=ss;
			fg=1;
			repA(i,ix+1,sz(s)-1){
				int ss = s[i]-'a',aa=b[i]-'a';
				bool fg2=0;
				repA(j,0,aa-1){
					if(chk(ss,j)){
						m1[ss]=j,m2[j]=ss;
						fg2=1;
						break;
					}
				}
				if(fg2) break;
				if(chk(ss,aa)){
					m1[ss]=aa,m2[aa]=ss;
				}
				else {
					fg=0;
					break;
				}
			}
		}
	}
	else fg=1;
	if(fg){
		cout<<"YES\n";
		vi g1;
		rep(i,k) if(m2[i]==-1) g1.pb(i);
		rep(i,k) if(m1[i]==-1){
			m1[i]=g1.back();
			g1.pop_back();
		}
		rep(i,k) cout<<char(m1[i]+'a');
		cout<<'\n';
	}
	else {
		cout<<"NO\n";
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) solve();
	
	
	return 0;
}