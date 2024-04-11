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
int ans[200009];
int ex[200009];
int cnt = 0;
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	vector<pii> v;
	rep(i,n){
		int x;cin>>x;
		v.pb({x,i+1});
	}
	sort(all(v));
	reverse(all(v));
	int st = v[0].snd;
	ans[0] = 2*st,ans[v[0].fst]=2*st-1;
	ex[2*st]=ex[2*st-1]=-1;
	cnt = v[0].fst;
	repA(i,1,n-1){
		int l = v[i].fst,ix=v[i].snd;
		if(i>=v[0].fst){
			ex[2*ix] = 0;
			if(l==1){
				ex[2*ix-1]=-1;
				cout<<2*ix<<' '<<2*ix-1<<'\n';
			}
			else{
				ex[2*ix-1]=l-2;
			}
			continue;
		}
		ans[i] = 2*ix;
		int j = i+l;
		ex[2*ix]=-1;
		if(j==cnt+1) {
			ans[j] = 2*ix-1;
			ex[2*ix-1]=-1;
			cnt++;
		}
		else{
			ex[2*ix-1]=j-1;
		}
	}
	repA(i,1,2*n){
		if(ex[i]!=-1){
			cout<<i<<' '<<ans[ex[i]]<<'\n';
		}
	}
	repA(i,1,cnt){
		cout<<ans[i-1]<<' '<<ans[i]<<'\n';
	}
	return 0;
}