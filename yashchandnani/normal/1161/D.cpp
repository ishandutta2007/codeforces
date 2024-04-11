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
bool dbg;
struct UF {
	vi e;
	vi val;
	UF(int n) : e(n, -1),val(n,0) {}
	bool same_set(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { if(e[x] < 0 ) return  x;
		else {	int gg=e[x] ;e[x] = find(e[x]),val[x] ^= val[gg];
			return e[x]; }
	}
	bool join(int a, int b,int w) {
		int aa = a,bb=b;
		a = find(a), b = find(b);
		if (a == b){
			if(val[aa]^w!=val[bb]) return false;
			else return true;
		}
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;val[b] = w^val[aa]^val[bb];
		return true;
	}
};

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	string s;cin>>s;
	ll fns =0;
	repA(i,1,sz(s)-1){
		UF dsu(sz(s)+i+2);
		bool fg=0;
		repA(j,1,i/2){
			if(!dsu.join(sz(s)+j,sz(s)+i+1-j,0)) fg=1;
		}
		repA(j,1,sz(s)/2){
			if(!dsu.join(j,sz(s)+1-j,0)) fg=1;
		}
		repA(j,1,sz(s)){
			if(j<=sz(s)-i&&s[j-1]!='?'){
				if(s[j-1]=='1'){
					if(!dsu.join(j,sz(s)+1+i,0)) fg=1;
				}
				else{
					if(!dsu.join(0,j,0)) fg=1;
				}
			}
			else{
				if(s[j-1]=='0'){
					if(!dsu.join(j,j+i,0)) fg=1;	
				}
				if(s[j-1]=='1'){
					if(!dsu.join(j,j+i,1)) fg=1;	
				}
			}
		}
		if(!dsu.join(sz(s)+1+i,sz(s)+1,0)) fg=1;
		if(dsu.same_set(0,sz(s)+1+i)&&dsu.val[0]^dsu.val[sz(s)+1+i]!=1) fg=1;
		if(fg) continue;
		bool vis[2009];
		fill(vis);
		ll ans = 1;
		repA(j,1,sz(s)+i){
			if(!dsu.same_set(j,0)&&!dsu.same_set(j,sz(s)+i+1)&&!vis[dsu.find(j)]){
				vis[dsu.find(j)]=1;
				ans = ans*2%998244353;
			}
		}
		fns=(fns+ans)%998244353;
	}
	cout<<fns;
	return 0;
}