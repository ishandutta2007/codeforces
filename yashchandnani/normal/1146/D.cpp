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
bool vis[200009];
int ans[200009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	int a,b;cin>>a>>b;
	priority_queue<pii> q;
	q.push(mp(0,0));
	memset(ans,-1,sizeof(ans));
	ans[0] = 0;
	while(!q.empty()){
		pii z = q.top();
		q.pop();
		if(vis[z.snd]) continue;
		vis[z.snd]=1;
		if(z.snd+a<a+b&&!vis[z.snd+a]&&(ans[z.snd+a]==-1||ans[z.snd+a]>max(z.snd+a,ans[z.snd]))){
			ans[z.snd+a] = max(z.snd+a,ans[z.snd]);
			q.push(mp(-ans[z.snd+a],z.snd+a));
		}
		if(z.snd-b>=0&&!vis[z.snd-b]&&(ans[z.snd-b]==-1||ans[z.snd-b]>ans[z.snd])){
			ans[z.snd-b] = ans[z.snd];
			q.push(mp(-ans[z.snd-b],z.snd-b));
		}
	}
	ll fns=0;
	int m = min(a+b-2,n);
	rep(i,a+b-1){
		if(ans[i]==-1){
			continue;
		}
		fns+=max(0,m+1-ans[i]);
	}
	if(n>a+b-2){
		m = n;
		rep(i,a){
			if(ans[i]==-1) continue;
			int l = (m)/a;
			if(m%a>=i) l++;
			int d = -a;
			int st = m-i+1;
			fns+=1ll*l*(2*st+1ll*(l-1)*d)/2;
		}
		m = a+b-2;
		rep(i,a){
			if(ans[i]==-1) continue;
			int l = (m)/a;
			if(m%a>=i) l++;
			int d = -a;
			int st = m-i+1;
			fns-=1ll*l*(2*st+1ll*(l-1)*d)/2;
		}
	}
	cout<<fns;
	return 0;
}