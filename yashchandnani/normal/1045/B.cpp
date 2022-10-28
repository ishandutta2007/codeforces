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
vi p[2];
void manacher(const vi& s) {
	int n = sz(s);
	p[0]  = vi(n+1,0);
	p[1]  = vi(n,0);
	rep(z,2) for (int i=0,l=0,r=0; i < n; i++) {
		int t = r-i+!z;
		if (i<r) p[z][i] = min(t, p[z][l+t]);
		int L = i-p[z][i], R = i+p[z][i]-!z;
		while (L>=1 && R+1<n && s[L-1] == s[R+1])
			p[z][i]++, L--, R++;
		if (R>r) l=L, r=R;
	}
}
bool check(int i,int j){
	if(i<j) swap(i,j);
	if((i-j+1)%2){
		int k = (i+j)/2;
		if(p[1][k]>=(i-j+1)/2) return 1;
		return 0;
	}
	else{
		int l = (i-j+1)/2;
		if(p[0][(i+j+1)/2]>=l) return 1;
		return 0;
	}
}
bool chk(int i,int j){
	if(i>=j) return 1;
	else return check(i,j-1);
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,m;cin>>n>>m;
	vi a(n);
	rep(i,n) cin>>a[i];
	if(n==1){
		cout<<1<<'\n';
		cout<<(a[0]*2)%m;
		return 0;
	}
	vi d(n-1);
	rep(i,n-1) d[i] = a[i+1]-a[i];
	manacher(d);
	vi fns;
	rep(i,n){
		if(i<n-1) {if(chk(0,i)&&chk(i+1,n-1)&&(a[0]+a[i])%m==(a[i+1]+a.back())%m) fns.pb((a[0]+a[i])%m);}
		else {
			if(chk(0,n-1)) fns.pb((a[0]+a[n-1])%m);
		}
	}
	sort(all(fns));
	cout<<sz(fns)<<'\n';
	trav(i,fns) cout<<i<<' ';
	return 0;
}