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
ll p[200009];
void solve(){
	int n;cin>>n;
	repA(i,1,n) cin>>p[i];
	sort(p+1,p+n+1,greater<int>());
	repA(i,1,n) p[i]+=p[i-1];
	int x,a;cin>>x>>a;
	int y,b;cin>>y>>b;
	ll k;cin>>k;
	int cnt0=0,cnt1=0,cnt2=0;
	if(y>x) swap(x,y),swap(a,b);
	repA(i,1,n){
		if(i%a==0&&i%b==0) cnt0++;
		else if(i%a==0) cnt1++;
		else if(i%b==0) cnt2++;
		if((p[cnt0]*(x+y)+(p[cnt0+cnt1]-p[cnt0])*x+(p[cnt0+cnt1+cnt2]-p[cnt0+cnt1])*y)*1ll/100>=k){
			cout<<i<<'\n';
			return;
		}
	}
	cout<<-1<<'\n';
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) solve();	
	
	
	return 0;
}