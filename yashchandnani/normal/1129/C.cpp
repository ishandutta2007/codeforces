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
int m1,m2;
int a[3009];
ll sc[3009];
const int mod = 1e9+7;
ll p[3009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	srand(time(0));
	m1 = rand()%5000000000+5e8,m2=rand()%5000000000+5e8;
	int n;cin>>n;
	vector<pair<pair<pii,int>,pii>> v;
	rep(i,n){
		cin>>a[i];
		ll cur1=0,cur2=0;
		sc[i+1]=1;
		repD(j,i,0){
			cur1=(cur1*2+a[j])%m1;
			cur2 = (cur2*2+a[j])%m2;
			sc[j] = 0;
			rep(k,4){
				if(i-j>=k){
					if(k==3){
						int lst = 0;
						lst = a[j]*8+a[j+1]*4+a[j+2]*2+a[j+3];
						if(lst==5||lst==14||lst==15||lst==3) continue;
					}
					sc[j]+=sc[j+k+1];
				}
			}
			sc[j]%=mod;
			v.pb(mp(mp(mp(cur1,j-i),cur2),mp(sc[j],i)));
		}
	}
	sort(all(v));
	p[v[0].snd.snd]+=v[0].snd.fst;
	repA(i,1,sz(v)-1){
		if(v[i].fst!=v[i-1].fst||v[i].snd.fst!=v[i-1].snd.fst) p[v[i].snd.snd]+=v[i].snd.fst;
	}
	p[0]%=mod;
	cout<<p[0]<<'\n';
	repA(i,1,n-1) {
		p[i]=(p[i]+p[i-1])%mod;
		cout<<p[i]<<'\n';
	}
	return 0;
}