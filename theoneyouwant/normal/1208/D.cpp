//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
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
const int MAXN = 2e5+5;

ll n, t[4*MAXN];

void build(ll a[], int v, int tl, int tr) { 

//Call this with original array a, v=1, tl=0, tr=n-1

    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = 0;

        // CHANGE TO t[v] = 0 if using lazy propagation
    }
}

void rangeupdate(int v, int tl, int tr, int l, int r, ll add) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        t[v] += add;
    } else {
        int tm = (tl + tr) / 2;
        rangeupdate(v*2, tl, tm, l, min(r, tm), add);
        rangeupdate(v*2+1, tm+1, tr, max(l, tm+1), r, add);
    }
}

ll get(int v, int tl, int tr, int pos) {

//Get value after lazy propagation USE t[v]=0 VERSION

    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get(v*2, tl, tm, pos);
    else
        return t[v] + get(v*2+1, tm+1, tr, pos);
}

int link[LIM] = {0};
int size[LIM] = {0};
int lchild[LIM] = {0};
int rchild[LIM] = {0};

int find(int x){
	int a = x;
	while(x!=link[x]){
		x = link[x];
	}
	link[a] = x;
	return x;
}

void unite(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return;
	int lans = min(lchild[a],lchild[b]);
	int rans = max(rchild[a],rchild[b]);
	if(size[a]<size[b]) swap(a,b);
	lchild[a] = lans;
	rchild[a] = rans;
	size[a]+=size[b];
	link[b] = a;
}


int main(){
	fastio;
	
	cin>>n;
	ll s[n];
	forn(i,n) cin>>s[i];

	ll a[n] = {0};
	a[0] = 0;

	forsn(i,1,n){
		a[i] = a[i-1]+i;
	}

	build(a,1,0,n-1);
	// cout<<"OK"<<endl;

	bool taken[n] = {0};

	forn(i,LIM) link[i] = i;
	forn(i,LIM) size[i] = 1;
	forn(i,LIM){
		lchild[i] = i;
		rchild[i] = i;
	}

	int pos[n] = {0};

	// forn(i,n) cout<<i<<" "<<get(1,0,n-1,i)<<ln;

	rforn(i,n-1){
		int l = 0, r = n-1;
		int mid, ml = LIM;
		while(true){
			if(r<l) break;
			mid = (l+r)/2;
			if(mid == ml) break;
			ll c = get(1,0,n-1,mid);
			if(s[i] == c) break;
			else if(s[i] > c) l = mid+1;
			else r = mid-1;
			
			ml = mid;
		}
		// cout<<i<<" FOUND "<<mid+1<<" "<<s[i]<<" VALUE "<<get(1,0,n-1,mid)<<ln;
		int anc = find(mid);
		// cout<<i<<" "<<mid<<" "<<lchild[anc]<<" "<<rchild[anc]<<ln;
		if(taken[mid]){
			int anc = find(mid);
			int lans = lchild[anc], rans = rchild[anc];
			if(lans-1 >= 0 && get(1,0,n-1,lans-1) == s[i]) mid = lans-1;
			else mid = rans+1;
		}
		// cout<<i<<" "<<mid<<ln;
		
		pos[i] = mid;
		taken[mid] = 1;
		if(mid<n-1 && taken[mid+1]) unite(mid,mid+1);
		if(mid>0 && taken[mid-1]) unite(mid,mid-1);
		

		rangeupdate(1,0,n-1,mid+1,n-1,-mid-1);
	}

	forn(i,n) cout<<pos[i]+1<<" ";
	cout<<ln;


	return 0;
}