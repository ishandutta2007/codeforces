#include <bits/stdc++.h>
using namespace std;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
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
int d[200009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,m,ka,kb;cin>>n>>m>>ka>>kb;
	if(ka>m-1||kb>n-1){
		cout<<"No";
	}
	else{
		cout<<"Yes\n";
		vi v1,v2;
		rep(i,ka) {
			int x;cin>>x;
			d[x]++;
			v1.pb(x);
		}
		rep(i,kb) {
			int x;cin>>x;
			d[x]++;
			v2.pb(x);
		}
		d[n+m]+=n-1-kb;
		rep(i,n-1-kb) v2.pb(n+m);
		rep(i,m-1-ka) v1.pb(n);
		d[n]+=m-1-ka;
		priority_queue<int> q;
		repA(i,1,n+m){
			if(d[i]==0){
				q.push(-i);
			}
		}
		reverse(all(v1));
		reverse(all(v2));
		int cnt = 0;
		while(sz(q)){
			if(cnt==n+m-2) break;
			int z = -q.top();
			q.pop();
			cnt++;
			if(z<=n){
				cout<<z<<' '<<v2.back()<<'\n';
				d[v2.back()]--;
				if(d[v2.back()]==0) q.push(-v2.back());
				v2.pop_back();
			}
			else{
				cout<<z<<' '<<v1.back()<<'\n';
				d[v1.back()]--;
				if(d[v1.back()]==0) q.push(-v1.back());
				v1.pop_back();
			}
		}
		int a = -q.top();
		q.pop();
		int b = -q.top();
		cout<<a<<' '<<b<<'\n';
	}
	
	return 0;
}