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
int cnt[2][26][109];
vi p[2][26];
char ans[109];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	cout<<"? "<<1<<" "<<n<<endl;
	if(n==1){
		string s;cin>>s;
		cout<<"! "<<s<<endl;
		return 0;
	}
	rep(i,n*(n+1)/2){
		string s;cin>>s;
		trav(j,s) cnt[0][j-'a'][sz(s)]++;
	}
	cout<<"? "<<1<<" "<<n-1<<endl;
	rep(i,n*(n-1)/2){
		string s;cin>>s;
		trav(j,s) cnt[1][j-'a'][sz(s)]++;
	}
	rep(j,26) if(cnt[0][j][1]>cnt[1][j][1]) ans[n-1] = 'a'+j;
	rep(i,2){
		rep(j,26){
			repA(l,1,(n+1)/2-1){
				if(cnt[i][j][l]*(l+1)!=cnt[i][j][l+1]*(l)){
					p[i][j].pb(l);
					repA(k,1,(n+1)/2){
						if(k<=l) cnt[i][j][k]-=k;
						else cnt[i][j][k]-=l;
					}
				}
				if(cnt[i][j][l]*(l+1)!=cnt[i][j][l+1]*(l)){
					p[i][j].pb(l);
					repA(k,1,(n+1)/2){
						if(k<=l) cnt[i][j][k]-=k;
						else cnt[i][j][k]-=l;
					}
				}
			}
		}
		rep(j,26) rep(k,cnt[i][j][1]) p[i][j].pb((n+1)/2);
	}
	int lst = ans[n-1]-'a';
	vi gg = p[0][lst];
	p[0][lst].clear();
	sort(all(gg));
	p[0][lst] = vi(gg.begin()+1,gg.end());
	rep(i,26){
		sort(all(p[0][i]));
		sort(all(p[1][i]));
		reverse(all(p[1][i]));
		reverse(all(p[0][i]));
		while(sz(p[0][i])){
			if(p[0][i].back()==p[1][i].back()) ans[p[0][i].back()-1] = 'a'+i;
			else ans[n-p[0][i].back()]='a'+i;
			p[0][i].pop_back();
			p[1][i].pop_back();
		}
	}
	cout<<"! ";
	cout<<string(ans,ans+n)<<endl;
	return 0;
}