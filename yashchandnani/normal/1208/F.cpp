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
int a[(1<<21)];
int cnt[(1<<21)];
void add(int x, int j){
	if((x>>j)==0) return;
	if(cnt[x]>2) return;
	add(x,j+1);
	if(x&(1<<j)){
		x ^= (1<<j);
		cnt[x]++;
		add(x,j+1);
	}
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) {
		cin>>a[i];
	}
	int ans = 0;
	repD(i,n-1,0){
		int cur = 0,s2=0;
		repD(j,20,0){
			if(a[i]&(1<<j)) cur |= (1<<j);
			else if(cnt[s2|(1<<j)]>=2){
				cur |= (1<<j);
				s2|=(1<<j);
			}
		}
		if(i<n-2) if(cnt[s2]>=2) ans = max(ans,cur);
		cnt[a[i]]++;
		add(a[i],0);
	}
	cout<<ans;
	return 0;
}