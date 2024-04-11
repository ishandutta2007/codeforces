//By TheOneYouWant
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
#define ln endl
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define dbg2(x,y) cerr<<#x<<" = "<<x<<" & "<<#y<<" = "<<y<<endl;
#define dbgstl32(v) cerr<<#v<<" = \n"; { int c=0; forstl(it,v) \
cerr<<"    Term "<< ++c <<" = "<<it<<ln;} cerr<<endl
#define dbgstlp32(v) cerr<<#v<<" = \n"; { int c=0; forstl(it,v) \
cerr<<"    Term "<< ++c <<" = "<<it.fi<<" , "<<it.se<<ln;} cerr<<endl
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define inp freopen("input.txt", "r", stdin)
#define outp freopen("output.txt", "w", stdout)
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
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
const ll MOD = 1e9+7, LIM = 1e5+5;
const ld EPS = 1e-9;
ull t,n,k,x,y;
ull a,b;
v64 v;
map<ull,ull> m;

ull answer(ull left, ull right, ull avengers){
	if(left==right){
		if(avengers!=0) return b*avengers;
		else return a;
	}
	ll avengersleft,avengersright;
	ll z=  (left+right)/2;
	auto it1 = lower_bound(v.begin(),v.end(),left);
	auto it2 = upper_bound(v.begin(),v.end(),z);
	if(it1==v.end() || *it1>z){
	//	cout<<"OK"<<" ";
		avengersleft=0;
	}
	else{
		if(it2==v.end()) avengersleft = avengers;
		else avengersleft = m[*it2]-m[*it1];
	}
	avengersright= avengers-avengersleft;
	ull totalmin = 2e19;
//	cout<<*it1<<" "<<*it2<<" "<<left<<" "<<right<<" "<<avengers<<" "<<avengersleft<<" "<<avengersright<<ln;
	if(avengers==0) return a;
	totalmin = min(totalmin, b*avengers*(right+1-left));
	totalmin = min(totalmin, answer(left,z,avengersleft)+answer(z+1,right,avengersright));

	return totalmin;
}

int main(){
	fastio;
	cin>>n>>k;
	cin>>a>>b;
	forn(i,k){
		cin>>x;
		v.pb(x);
	}
	sort(v.begin(),v.end());
//	int ok = 1<<30;
//	cout<<ok<<ln;
	ull count=1;
	forstl(r,v){
		if(m[r]==0) m[r] = count;
		count++;
	}
	cout<<answer(1,1LL<<n,k)<<ln;
	return 0;
}