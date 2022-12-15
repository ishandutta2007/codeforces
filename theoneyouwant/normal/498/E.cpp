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


const int MAX_N = 128;

struct Matrix { int mat[MAX_N][MAX_N]; }; // we will return a 2D array

Matrix matMul(Matrix a, Matrix b, int upto) {
	Matrix ans; int i, j, k;

	for(i = 0; i < MAX_N; i++){
		for(j = 0; j < MAX_N; j++){
			ans.mat[i][j] = 0;
		}
	}

	for (i = 0; i < upto; i++){
		for (k = 0; k < upto; k++){
			int temp = a.mat[i][k];
			for (j = 0; j < upto; j++){
				ans.mat[i][j] += ((ll)temp * b.mat[k][j]) % MOD;
				if(ans.mat[i][j] >= MOD) ans.mat[i][j] -= MOD;
			}
		}
	}
	
	return ans; 
}

// if necessary, use modulo arithmetic

Matrix matPow(Matrix base, int p, int upto) {
	// O(n^3 log p)
	Matrix ans; int i, j;
	for (i = 0; i < MAX_N; i++) for (j = 0; j < MAX_N; j++) 
	ans.mat[i][j] = (i == j); // prepare identity matrix
	while (p) {
		// iterative version of Divide & Conquer exponentiation
		if (p & 1) ans = matMul(ans, base, 1<<upto);	// if p is odd (last bit is on)
		base = matMul(base, base, 1<<upto);	// square the base
		p >>= 1;
		// divide p by 2
	}
	return ans; 
}

Matrix transition(int h){
	// h -> h transition
	Matrix ans;
	forn(i,1<<7){
		forn(j,1<<7){
			ans.mat[i][j] = 0;
		}
	}

	forn(i,1<<h){
		forn(j,1<<h){
			int tot = 0;
			forn(k,1<<(h-1)){
				bool p = 1;
				forn(chk,h){
					bool l = i & (1<<chk);
					bool r = j & (1<<chk);
					bool down = 0;
					if(chk == 0) down = 1;
					else down = k & (1<<(chk-1));
					bool up = 0;
					if(chk == h-1) up = 1;
					else up = k & (1<<chk);
					if((l>0) && (r>0) && (up>0) && (down>0)){
						p = 0;
						break;
					}
				}
				if(p) tot++;
			}
			ans.mat[i][j] = tot;
		}
	}
	return ans;
}

Matrix step_up(int h){
	Matrix ans;
	forn(i,1<<7){
		forn(j,1<<7){
			ans.mat[i][j] = 0;
		}
	}
	// transition from h -> h+1
	forn(i,1<<7){
		forn(j,1<<7){
			ans.mat[i][i^(1<<h)] = 1;
		}
	}
	return ans;
}

int main(){
	fastio;

	int w[7];
	forn(i,7){
		cin >> w[i];
	}	
	Matrix m;

	forn(i,1<<7){
		forn(j,1<<7){
			if(i==j) m.mat[i][j] = 1;
			else m.mat[i][j] = 0;
		}
	}

	forn(i,7){
		Matrix find = transition(i+1);
		find = matPow(find, w[i], i+1);
		m = matMul(m, find, 1<<(i+1));
		if(i!=6) m = matMul(m, step_up(i+1), 1<<(i+2));
	}

	cout << m.mat[1][127] << ln;


	return 0;
}