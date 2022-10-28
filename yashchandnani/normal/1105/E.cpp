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
int t=1;
bitset<40> fg[40],N[40];
vector<pair<int,bitset<40>>> v;
int ans;
void Br(bitset<40> R,bitset<40> P){
	if(int(P.count())==0){
		ans = max(ans,(int)R.count());
	}
	int i = P._Find_first();
	int u =i;
	while(i<t-1){
		if(!N[u][i]){
			R[i]=1;
			Br(R,P&N[i]);
			P[i]=0;
			R[i]=0;
		}
		i = P._Find_next(i);
	}
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	int mm;cin>>mm;
	rep(i,mm) fg[i].set();
	set<int> cur;
	map<string,int> m;
	rep(i,n){
		int x;cin>>x;
		if(x==1) cur.clear();
		else{
			string s;cin>>s;
			if(m[s]==0) m[s]=t,t++;
			int y= m[s]-1;
			trav(i,cur){
				fg[i][y]=0;
				fg[y][i]=0;
			}
			cur.insert(y);
		}
	}
	bitset<40> b,c;b.set();
	rep(i,t-1){
		rep(j,t-1){
			if(fg[i][j]&&i!=j) N[i][j]=1;
		}
	}
	Br(c,b);
	cout<<ans;
	return 0;
}