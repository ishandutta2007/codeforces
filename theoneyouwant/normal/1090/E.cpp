//By Tushar Gautam
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(int i = s; i >= 0; i--)
#define rforsn(i,s,e) for(int i = s; i >= e; i--)
#define leadzero(a) __builtin_clz(a) // count leading zeroes
#define trailzero(a) __builtin_ctz(a) // count trailing zeroes
#define bitcount(a) __builtin_popcount(a) // count set bits (add ll)
#define ln "\n"
#define dbg2(x,y) cerr<<#x<<" = "<<x<<" & "<<#y<<" = "<<y<<endl;
#define dbgstl32(v) cerr<<#v<<" = \n"; { int c=0; forstl(it,v) \
cerr<<"    Term "<< ++c <<" = "<<it<<ln;} cerr<<endl
#define dbgstlp32(v) cerr<<#v<<" = \n"; { int c=0; forstl(it,v) \
cerr<<"    Term "<< ++c <<" = "<<it.fi<<" , "<<it.se<<ln;} cerr<<endl
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
typedef long long int  ll;
typedef long double  ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
const int LIM = 1e5+5, MOD = 1e9+7;
int t,n,m,k,x,y;
p32 getpair(string s){
	return mp(s[0]-'a',s[1]-'1');
}
string getstring(int a,int b){
	string res="";
	res+=a+'a';
	res+=b+'1';
	return res;
}
string s;
string seq[65];
vector<string> inp;
void solve(vv32 &mat,bool extreme=0){
	forn(i,8) forn(j,8) seq[mat[i][j]]=getstring(i,j);
	v32 spots,pieces;
	forn(i,n){
		spots.pb(mat[i%8][i/8]);
	}
	sort(spots.begin(),spots.end(),greater<int>());
	forn(i,n){
		s=inp[i];
		auto p=getpair(s);
		tie(x,y)=p;
		pieces.pb(mat[x][y]);
	}
	sort(pieces.begin(),pieces.end());
	vector<string> ans;
	vp32 acc;
	forstl(it,pieces){
		int tar=spots.back();
		spots.pop_back();
		int start=it;
		if(start<tar){
			acc.pb(mp(start,tar));
		}else{
			while(start!=tar){
				string r=seq[start]+"-"+seq[start-1];
				ans.pb(r);
				start--;	
			}
			reverse(acc.begin(),acc.end());
			forstl(it,acc){
				start=it.fi;
				tar=it.se;
				while(start!=tar){
					string r=seq[start]+"-"+seq[start+1];
					ans.pb(r);
					start++;	
				}
			}
			acc.clear();
		}
	}
	reverse(acc.begin(),acc.end());
	forstl(it,acc){
		int start=it.fi;
		int tar=it.se;
		while(start!=tar){
			string r=seq[start]+"-"+seq[start+1];
			ans.pb(r);
			start++;	
		}
	}
	if(extreme || ans.size()<1500){
		cout<<ans.size()<<ln;
		forstl(it,ans) cout<<it<<ln;
		exit(0);
	}
}
int main(){
	fastio;
	cin>>n;
	inp.resize(n);
	forn(i,n){
		cin>>inp[i];
	}
	vv32 mat={{1,4,57,20,47,6,49,22},
  			{34,19,2,5,58,21,46,7},
			{3,56,35,60,37,48,23,50},
			{18,33,38,55,52,59,8,45},
			{39,14,53,36,61,44,51,24},
			{32,17,40,43,54,27,62,9},
			{13,42,15,30,11,64,25,28},
			{16,31,12,41,26,29,10,63}};
	solve(mat,0);
	reverse(mat.begin(),mat.end());
	solve(mat,0);
	forstl(it,mat) reverse(it.begin(),it.end());
	solve(mat,0);
	reverse(mat.begin(),mat.end());
	solve(mat,0);
	vv32 mat1={{63, 20,  3, 24, 59, 36,  5, 26},
  				{2, 23, 64, 37,  4, 25, 58, 35},
 				{19, 62, 21, 50, 55, 60, 27,  6},
 				{22,  1, 54, 61, 38, 45, 34, 57},
 				{53, 18, 49, 44, 51, 56,  7, 28},
 				{12, 15, 52, 39, 46, 31, 42, 33},
 				{17, 48, 13, 10, 43, 40, 29,  8},
 				{14, 11, 16, 47, 30,  9, 32, 41}};
 	solve(mat1,0);
	reverse(mat1.begin(),mat1.end());
	solve(mat1,0);
	forstl(it,mat1) reverse(it.begin(),it.end());
	solve(mat1,0);
	reverse(mat1.begin(),mat1.end());
	solve(mat1,0);
 	vv32 mat2={{20,15,22,45,58,47,38,43},
 				{17,4,19,48,37,44,59,56},
				 {14,21,16,23,46,57,42,39},
				  {3,18,5,36,49,40,55,60},
				  {6,13,8,29,24,35,50,41},
				  {9,2,11,32,27,52,61,54},
				 {12,7,28,25,30,63,34,51},
				  {1,10,31,64,33,26,53,62}};
  	solve(mat2,0);
	reverse(mat2.begin(),mat2.end());
	solve(mat2,0);
	forstl(it,mat2) reverse(it.begin(),it.end());
	solve(mat2,0);
	reverse(mat2.begin(),mat2.end());
	solve(mat2,0);
	assert(1==2);
	return 0;
}