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
int p[300009],pos[300009];
vector<pii> ans;
void swap(int i,int j){
	if(i==j) return;
	int ii = p[i],jj = p[j];
	pos[ii] = j,pos[jj] = i;
	p[i] = jj,p[j] = ii;
	ans.pb(mp(i,j));
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	repA(i,1,n) cin>>p[i],pos[p[i]] = i;
	repA(i,1,n/2){
		int ii = n/2+1-i;
		if(pos[ii]>n/2){
			swap(pos[ii],1);swap(1,n);swap(n,ii);
		}
		else swap(pos[ii],n),swap(n,ii);
		ii = n/2+i;
		if(pos[ii]>n/2) swap(pos[ii],1),swap(1,ii);
		else swap(pos[ii],n),swap(n,1),swap(1,ii);
	}
	cout<<sz(ans)<<'\n';
	trav(i,ans) cout<<i.fst<<' '<<i.snd<<'\n';
	return 0;
}