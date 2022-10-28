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
int a[200009],b[200009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	string s,t,tt;cin>>s>>t;
	int l=0,r=0,k,cnt=0;
	repA(i,1,sz(t)-1){
		if(i>r){
			l=r=i;
			while(r<sz(t)&&t[r-l]==t[r]) r++,cnt++;
			a[i] = r-l;
		}
		else{
			k = i-l;
			if(a[k]<r-i){
				a[i]=a[k];
			}
			else{
				l = i;
				while(r<sz(t)&&t[r-l]==t[r]){
					r++;cnt++;
				}
				a[i] = r-l;
			}
		}
		b[i] = cnt;
	}
	b[sz(t)] = cnt;
	tt=t;t+=s;
	l=0,r=0,k,cnt=0;
	repA(i,1,sz(t)-1){
		if(i>r){
			l=r=i;
			while(r<sz(t)&&t[r-l]==t[r]) r++,cnt++;
			a[i] = r-l;
		}
		else{
			k = i-l;
			if(a[k]<r-i){
				a[i]=a[k];
			}
			else{
				l = i;
				while(r<sz(t)&&t[r-l]==t[r]){
					r++;cnt++;
				}
				a[i] = r-l;
			}
		}
	}
	ll ans = 1ll*sz(s)*sz(tt);
	repA(i,0,sz(s)-1){
		int pp = min(a[sz(tt)+i+1],sz(tt));
		ans-=b[pp];
	}
	cout<<ans;
	return 0;
}