#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <sys/time.h>
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
typedef long long H;
static const H M = INT_MAX;
static H C; // initialized below

// Arithmetic mod M. "typedef H K;" instead if you think
// test data is random. (Haha, good luck.)
struct K {
	H x; K(H x=0) : x(x) {}
	K operator+(K o) { H y = x + o.x; return y - (y >= M) * M; }
	K operator*(K o) { return x*o.x % M; }
	H operator-(K o) { H y = x - o.x; return y + (y < 0) * M; }
};

struct HashInterval {
	vector<K> ha, pw;
	HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
		pw[0] = 1;
		rep(i,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	timeval tp;
	gettimeofday(&tp, 0);
	C = tp.tv_usec;
	pre();
	string s,t;cin>>s>>t;
	int cnt0=0,cnt1=0;
	trav(i,s) if(i==s[0]) cnt0++; else cnt1++;
	HashInterval h(t);
	int ans = 0;
	repA(i,1,sz(t)-1){
		int x = i;
		if((sz(t)-1ll*cnt0*x)<=0) break;
		if((sz(t)-1ll*cnt0*x)%cnt1) continue;
		int y = (sz(t)-1ll*cnt0*x)/cnt1;
		assert(cnt0*x+cnt1*y==sz(t));
		assert(x>0&&y>0);
		int cur0=0,cur1=0;
		H val1,val2;
		bool vis0=0,vis1=0;
		bool fg = 0;
		rep(j,sz(s)){
			int st = cur0*x+cur1*y;
			int en = st;
			if(s[j]==s[0]) en+=x;
			else en+=y;
			H val = h.hashInterval(st,en);
			if(s[j]==s[0]) {
				cur0++;
				if(!vis0) val1=val,vis0=1; 
				else if(val1!=val){
					fg=1;
					break;
				}
			}
			else{
				cur1++;
				if(!vis1) val2=val,vis1=1;
				else if(val2!=val){
					fg=1;
					break;
				}
			}
		}
		if(!fg&&val1!=val2) ans++;
	}
	cout<<ans;
	
	
	
	return 0;
}