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

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,m;cin>>n>>m;
	if(n<=2){
		if(m==0){
			repA(i,1,n) cout<<i<<' ';
		}
		else cout<<-1;
	}
	else{
		vi v;
		v.pb(1);
		v.pb(2);
		int lst = 2;
		repA(i,3,n){
			if(m>=sz(v)/2){
				m-=sz(v)/2;
				v.pb(i);
				lst=i;
			}
			else break;
		}
		if(lst==n&&m>0){
			cout<<-1;
		}
		else{
			if(m){
				repA(i,lst+1,2*lst-1){
					int j = i-lst;
					int cnt = lst-j+1;
					if(m==cnt/2){
						v.pb(i);
						m=0;
						break;
					}
				}

			}
			int mx = v.back()+1;
			int lf = n-sz(v);
			rep(i,lf) v.pb(1e8+i*mx);
			rep(i,n) cout<<v[i]<<' ';
		}
	}

	
	return 0;
}