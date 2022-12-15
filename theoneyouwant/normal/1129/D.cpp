//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i=0;i<e;++i)
#define forsn(i,s,e) for(int i=s;i<e;++i)
#define rforn(i,s) for(int i=s;i>=0;--i)
#define rforsn(i,s,e) for(int i=s;i>=e;--i)
#define bitcount(a) __builtin_popcount(a) // set bits (add ll)
#define ln '\n'
#define getcurrtime() cerr<<"Time = "<<((double)clock()/CLOCKS_PER_SEC)<<endl
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define inputfile freopen("input.txt", "r", stdin)
#define outputfile freopen("output.txt", "w", stdout)
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) { cerr<<endl; }
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << "\t"; err(++it, args...);
}
template<typename T1,typename T2>
ostream& operator <<(ostream& c,pair<T1,T2> &v){
	c<<"("<<v.fi<<","<<v.se<<")"; return c;
}
template <template <class...> class TT, class ...T>
ostream& operator<<(ostream& out,TT<T...>& c){
    out<<"{ ";
    forstl(x,c) out<<x<<" ";
    out<<"}"; return out;
}
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
const int LIM=2e5+5,MOD=998244353;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, k;
int block_size, num_blocks;
int pref[325][650];
int sum[325];
int b[LIM];
int dp[LIM];

int add(int a, int b){
	a += b;
	if(a >= MOD) a -= MOD;
	return a;
}

void upd(int pos){
	if(pos == 0) return;
	int block = (pos - 1) / block_size;
	// update block
	forn(j,2*block_size+1){
		pref[block][j] = 0;
	}
	int cum = 0;
	rforsn(j, (block + 1) * block_size, block * block_size + 1){
		cum += b[j];
		pref[block][cum+block_size] = add(pref[block][cum+block_size], dp[j-1]);
	}
	sum[block] = cum;
	forn(j,2*block_size+1){
		if(j>0) pref[block][j] = add(pref[block][j], pref[block][j-1]);
	}
}

int main(){
	fastio;

	cin >> n >> k;
	int a[n+1];

	forsn(i,1,n+1) cin >> a[i];

	block_size = sqrt(n);
	num_blocks = n/block_size + 1;

	forn(i,num_blocks){
		forn(j,2*block_size+1){
			pref[i][j] = 0;
		}
	}

	dp[0] = 1;
	int last_val[n+1] = {0};
	int second_last[n+1] = {0};

	forsn(i,1,n+1){
		// consider i as the right endpoint
		int cons_blocks = (i-1)/block_size;
		if(second_last[a[i]]>0){
			b[second_last[a[i]]] = 0;
			upd(second_last[a[i]]);
		}
		if(last_val[a[i]]>0){
			b[last_val[a[i]]] = -1;
			upd(last_val[a[i]]);
		}
		second_last[a[i]] = last_val[a[i]];
		last_val[a[i]] = i;
		b[i] = 1;

		int cum = 0;

		rforsn(j, i, cons_blocks * block_size + 1){
			cum += b[j];
			if(cum <= k){
				dp[i] = add(dp[i], dp[j-1]);
			}
		}
		rforn(j, cons_blocks-1){
			if(cum + block_size <= k){
				dp[i] = add(dp[i], pref[j][2*block_size]);
			}
			else if(cum - block_size <= k){
				dp[i] = add(dp[i], pref[j][k+block_size-cum]);
			}
			cum += sum[j];
		}
		if(i%block_size == 0){
			upd(i);
		}
	}

	cout << dp[n] << ln;

	return 0;
}