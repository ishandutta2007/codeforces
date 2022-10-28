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
map<int,pii> par;
map<int,int> siz;
pii cal(int x){
	pii ans = mp(0,x);
	while(par.find(x)!=par.end()){
		ans.fst^=par[x].fst;
		ans.snd = x = par[x].snd;
	}
	return ans;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	int last  =0;
	rep(i,n){
		int t,l,r;cin>>t>>l>>r;
		l = l^last;
		r=r^last;
		if(l>r) swap(l,r);
		r++;
		if(t==1){
			int x;cin>>x;
			pii l1 = cal(l);
			pii r1 = cal(r);
			x = x^l1.fst^r1.fst^last;
			if(l1.snd!=r1.snd){
				if(siz[r1.snd]==0) siz[r1.snd]=1;
				if(siz[l1.snd]==0) siz[l1.snd]=1;
				if(siz[l1.snd]<siz[r1.snd]){
					par[l1.snd] = mp(x,r1.snd);
					siz[r1.snd]+=siz[l1.snd];
				}
				else{
					par[r1.snd] = mp(x,l1.snd);
					siz[l1.snd]+=siz[r1.snd];
				}
			}
		}
		else{
				pii l1 = cal(l);
				pii r1 = cal(r);
				if(l1.snd==r1.snd){
					last = l1.fst^r1.fst;
					cout<<last<<'\n';
				}
				else {
					last=1;
					cout<<-1<<'\n';
				}
		}
		
	}
	return 0;
}