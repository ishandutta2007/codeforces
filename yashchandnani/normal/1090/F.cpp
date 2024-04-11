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
typedef pair<ll, int> pii;
typedef vector<int> vi;

void pre(){


}
vector<pii> v;
ll a[1009];
int q(int i,int j,int k){
	cout<<"? "<<i<<" "<<j<<" "<<k<<endl;
	int x;cin>>x;
	return x;
}
void solve(int i){
	int x  =q(v[0].snd,v[2].snd,i);
	int y  =q(v[4].snd,v[2].snd,i);
	if(x>a[v[0].snd]+a[v[2].snd]){
		a[i] = a[v[2].snd] + x  -(a[v[0].snd]+a[v[2].snd]);
		return;
	}
	if(x<a[v[0].snd]+a[v[2].snd]){
		a[i] = a[v[0].snd] + x  -(a[v[0].snd]+a[v[2].snd]);
		return;
	}
	if(y>a[v[4].snd]+a[v[2].snd]){
		a[i] = a[v[4].snd] + y  -(a[v[4].snd]+a[v[2].snd]);
		return;
	}
	if(y<a[v[4].snd]+a[v[2].snd]){
		a[i] = a[v[2].snd] + y  -(a[v[4].snd]+a[v[2].snd]);
		return;
	}
	a[i]  = a[v[2].snd];
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	repA(i,1,5){
		repA(j,1,i-1){
			repA(k,1,j-1){
				cout<<"? "<<i<<" "<<j<<" "<<k<<endl;
				int x;cin>>x;
				a[i]+=x;
				a[j]+=x;
				a[k]+=x;
			}
		}
	}
	repA(i,1,5) v.pb(mp(a[i],i));
	sort(all(v));
	ll x  = q(v[0].snd,v[1].snd,v[2].snd);
	ll y  = q(v[0].snd,v[1].snd,v[4].snd);
	ll z  = q(v[2].snd,v[3].snd,v[4].snd);
	a[v[0].snd] = (x+y+z)/2 - z;
	a[v[2].snd] = (x+y+z)/2 - y;
	a[v[4].snd] = (x+y+z)/2 - x;
	solve(v[1].snd);
	solve(v[3].snd);
	repA(i,6,n) solve(i);
	cout<<"! ";
	repA(i,1,n){
		cout<<a[i]<<' ';
	}
	cout<<endl;
	
	return 0;
}