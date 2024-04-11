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
const int LIM=105,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n; 
int c[LIM];

void oper(v32 shift){
	// cout<<"Checking oper"<<ln;
	// forn(i,n) cout<<c[i]<<" ";
	
	// cout<<ln;
	// cout<<shift<<ln;
	
	int op[n] = {0};
	int pref = 0;
	int sub = n;
	rforsn(i,shift.size()-1,1){
		sub -= shift[i];
		forsn(j,pref,pref+shift[i]){
			op[j] = c[sub+j-pref];
		}	
		pref += shift[i];
	}
	forn(i,n) c[i] = op[i];
	// forn(i,n) cout<<c[i]<<" ";
	// cout<<ln;
	// cout<<"DONE"<<ln;
}


int main(){
	fastio;

	cin>>n;
	forn(i,n) cin>>c[i];

	if(n == 1){
		cout<<0<<ln;
		return 0;
	}
	// if(n == 2){
	// 	if(c[0] == 1){
	// 		cout<<0<<ln;
	// 	}
	// 	else{
	// 		cout<<1<<ln;
	// 		cout<<"2 1 1"<<ln;
	// 	}
	// 	return 0;
	// }

	bool f = 1;	
	int blocksize = 1;
	v32 operations[n];
	int iter = 0;

	while(blocksize < n){
		int pos = -1, nxt = -1;
		forn(i,n){
			if(c[i] == 1) pos = i;
			if(c[i] == blocksize+1) nxt = i;
		}
		v32 sizes;

		if(nxt>pos){
			if(f == 1){
				sizes.pb(pos);
				forn(i,blocksize) sizes.pb(1);
				sizes.pb(nxt - pos - blocksize + 1);
				sizes.pb(n - 1 - nxt);
			}
			else{
				sizes.pb(pos - blocksize + 1);
				sizes.pb(blocksize);
				sizes.pb(nxt - pos);
				sizes.pb(n - 1 - nxt);
			}
			f = 0;
		}
		else if(nxt<pos){
			if(f == 1){
				sizes.pb(nxt);
				sizes.pb(pos - nxt);
				sizes.pb(blocksize);
				sizes.pb(n - pos - blocksize);
			}
			else{
				sizes.pb(nxt);
				sizes.pb(pos - blocksize + 1 - nxt);
				forn(i,blocksize) sizes.pb(1);
				sizes.pb(n - 1 - pos);
			}
			f = 1;
		}

		// cout<<"first "<<sizes<<ln;

		int cnt = 0;
		forstl(r,sizes){
			if(r>0) cnt++;
		}
		if(cnt>0) operations[iter].pb(cnt);
		forstl(r,sizes){
			if(r>0) operations[iter].pb(r);
		}
		if(operations[iter].size() > 0) oper(operations[iter]);
		blocksize++;
		iter++;
	}

	if(f == 0){
		operations[iter].pb(n);
		forn(i,n) operations[iter].pb(1);
	}

	int num = 0;

	forn(i,n){
		if(operations[i].size()>0) num++;
	}

	cout<<num<<ln;
	forn(i,num){
		forstl(r,operations[i]) cout<<r<<" ";
		cout<<ln;
	}

	return 0;
}