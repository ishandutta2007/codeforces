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
int y[2000009];
int cnt[2000009];
int s[2000009];
int lst[2000009];
void solve(){
	int n;cin>>n;
	memset(y,0,sizeof(int)*(n+10));
	memset(cnt,0,sizeof(int)*(n+10));
	memset(s,0,sizeof(int)*(n+10));
	memset(lst,0,sizeof(int)*(n+10));
	rep(i,n){
		int c;cin>>c;
		y[c]++;
	}
	int cntx=0;
	repA(i,1,n){
		if(y[i]){
			cntx++;
			int j=1;
			while(j*j<=y[i]){
				int x = ceil(y[i]*1.0/j);
				if(x*(j-1)<=y[i]&&y[i]<=x*j&&lst[j]!=i){
					s[j]+=x;
					cnt[j]++;
					lst[j] = i;
				}
				int j1 = ceil(y[i]*1.0/j);
				int x1 = ceil(y[i]*1.0/j1);
				if(x1*(j1-1)<=y[i]&&y[i]<=x1*j1&&lst[j1]!=i){
					s[j1]+=x1;
					cnt[j1]++;
					lst[j1]=i;
				}
				{
					j1++;
					int x1 = ceil(y[i]*1.0/j1);
					if(x1*(j1-1)<=y[i]&&y[i]<=x1*j1&&lst[j1]!=i){
						s[j1]+=x1;
						cnt[j1]++;
						lst[j1]=i;
					}
				}
				{
					j1-=2;
					int x1 = ceil(y[i]*1.0/j1);
					if(x1*(j1-1)<=y[i]&&y[i]<=x1*j1&&lst[j1]!=i){
						s[j1]+=x1;
						cnt[j1]++;
						lst[j1]=i;
					}
				}
				j++;
			}
			int x = ceil(y[i]*1.0/j);
			if(x*(j-1)<=y[i]&&y[i]<=x*j&&lst[j]!=i){
				s[j]+=x;
				cnt[j]++;
				lst[j] = i;
			}
			if(lst[y[i]+1]!=i){
				cnt[y[i]+1]++;
				s[y[i]+1]++;
			}
		}
	}
	int ans = n;
	repA(i,1,n) if(cnt[i]==cntx) ans=min(ans,s[i]);
	cout<<ans<<'\n';
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) solve();	
	return 0;
}