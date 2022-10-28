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
ll cal(int k,ll n){
	ll z = 1;
	ll ans =0;
	int h = 1;
	while(n>0){
		ans+=1ll*h*min(z,n);
		n-=z;
		z = z*k;
		h++;
	}
	return ans;
}
int p[100009],h[100009],d[100009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	ll s;cin>>s;
	if(s==1ll*n*(n+1)/2){
		cout<<"Yes\n";
		rep(i,n-1) cout<<i+1<<' ';
		exit(0);
	}
	else if(s>1ll*n*(n+1)/2||s<2*n-1){
		cout<<"No\n";
		exit(0);
	}
	cout<<"Yes\n";
	int ans=2;
	while(s<cal(ans,n)) ans++;
	ll cur = 1ll*n*(n+1)/2;
	int st = 1,en=n;
	repA(i,1,n) h[i]=i,p[i]=i-1,d[i]=1;
	d[n] = 0;
	priority_queue<pii> q;
	repA(i,2,n){
		q.push(mp(-i,-i));
	}
	while(cur>s){
		if(d[st]==ans) {
			st=-q.top().snd;
			q.pop();
		}
		if(cur-h[en]+h[st]+1<s){
			repA(i,1,n){
				if(d[i]<ans&&cur-h[en]+h[i]+1==s){
					p[en] = i;
					break;
				}
			}
			break;
		}
		else{
			d[st]++;
			d[p[en]]--;
			cur = cur-h[en]+h[st]+1;
			p[en] = st;
			h[en]=h[st]+1;
			q.push(mp(-h[en],-en));
			en--;
		}
	}
	repA(i,2,n) cout<<p[i]<<' ';
	return 0;
}