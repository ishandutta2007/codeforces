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
const int LIM=2e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	fastio;

	string s;
	cin>>s;
	int n = s.length();

	int num = 0;
	forn(i,n){
		if(s[i] == '#'){
			num++;
		}
	}
	if(num == 0){
		cout<<0<<ln;
		return 0;
	}

	int fi = -1;
	int last = n;
	forn(i,n){
		if(s[i] == '#'){
			fi = i;
			break;
		}
	}
	forn(i,n){
		if(s[i] == '#'){
			last = i;
		}
	}
	int shift = min(fi, n-1-last);

	forsn(shift,0,4){

		bool p = 1;
		vp32 hashes;
		int curr = 0;
		forn(i,n){
			if(s[i] == '_'){
				if(curr>0) hashes.pb(mp(i-1, curr));
				curr = 0;
			}
			else{
				curr++;
			}
		}

		if(curr>0) hashes.pb(mp(n-1, curr));

		int left_rep[n] = {0};

		forn(i,hashes.size()){
			int id = hashes[i].fi;
			int len = shift + hashes[i].se;
			if(id+1-len<0){
				continue;
			}
			forsn(i,id+1-len, id+1){
				left_rep[i] = 1;
			}
		}

		last = 0;
		curr = 0;

		forn(i,n-shift+1){
			if(left_rep[i] == 1){
				// clean curr
				// set last = i+1
				while(curr>3){
					left_rep[last] = 1;
					last += 2;
					curr -= 2;
				}
				if(curr == 3){
					left_rep[last] = 1;
					left_rep[last+1] = 1;
					curr = 0;
				}
				if(curr == 2){
					left_rep[last] = 1;
					curr = 0;
				}
				last = i+2;
				curr = 0;
			}
			else{
				if(last <= i) curr++;
			}
		}
		while(curr>3){
			left_rep[last] = 1;
			last += 2;
			curr -= 2;
		}
		if(curr == 3){
			left_rep[last] = 1;
			left_rep[last+1] = 1;
			curr = 0;
		}
		if(curr == 2){
			left_rep[last] = 1;
			curr = 0;
		}

		forn(i,n){
			if(left_rep[i]==1) cerr<<'#';
			else cerr<<'_';
		}
		cerr<<ln;

		v32 ans;
		curr = 0;
		last = 0;
		forn(i,n){
			if(left_rep[i] == 0){
				if(curr>0) ans.pb(curr);
				curr = 0;
			}
			else{
				last = i;
				curr++;
			}
		}
		if(curr > 0) ans.pb(curr);

		if(left_rep[0] == 0) p = 0;

		int mark[n] = {0};
		int curr_st = 0;

		forstl(r,ans){
			int l_pt = curr_st+shift;
			int r_pt = curr_st+r-1;
			if(r_pt+shift >= n) p = 0;
			forsn(j,l_pt,r_pt+1){
				mark[j] = 1;
			}
			curr_st += r+1;
		}

		int lastmarked = -1;
		forn(i,n){
			if(left_rep[i]) lastmarked = i;
		}
		if(lastmarked + shift != n-1) p = 0;

		forn(i,n){
			if(s[i] == '#'){
				if(mark[i] != 1) p = 0;
			}
			else{
				if(mark[i] != 0) p = 0;
			}
		}

		if(p){
			cout<<ans.size()<<ln;
			forstl(r, ans) cout<<r<<" ";
			cout<<ln;
			return 0;
		}
	}
	cout<<-1<<ln;
	

	// cout<<ans<<ln;



	return 0;
}