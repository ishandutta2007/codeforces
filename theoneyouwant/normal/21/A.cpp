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
const int LIM=1e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

queue<char> username, hostname, resource;
bool valid;

void check_username(){

	int len = 0;
	bool pos = 1;

	while(!username.empty()){
		len++;
		char c =username.front();
		if((c-'a'<=26 && c-'a'>=0) || (c-'A'<=26 && c-'A'>=0) || (c-'0'<=9 && c-'0'>=0) || (c == '_'));
		else pos = 0;
		username.pop();
	}
	if(len > 16 || len<1) pos = 0;
	if(pos == 0) valid = 0;

}

void check_hostname(){

	int len = 0;

	while(!hostname.empty()){
		len++;
		char c = hostname.front();
		if(c == '.'){
			check_username();
		}
		else{
			username.push(c);
		}
		hostname.pop();
	}
	check_username();
	if(len<1 || len>32) valid = 0;

}

void check_resource(){
	int len = 0;
	bool pos = 1;


	while(!resource.empty()){
		len++;
		char c = resource.front();
		// cout<<c<<ln;
		if((c-'a'<=26 && c-'a'>=0) || (c-'A'<=26 && c-'A'>=0) || (c-'0'<=9 && c-'0'>=0) || (c == '_'));
		else pos = 0;
		resource.pop();
	}
	// cout<<pos<<ln;
	if(len > 16) pos = 0;
	if(pos == 0) valid = 0;
}

int main(){
	fastio;

	string s;
	cin>>s;

	int cnt = 0;
	bool p = 1;

	forn(i,s.length()){
		if(s[i] == '@'){
			if(cnt>=1){
				p = 0;
				break;
			}
			else{
				cnt = 1;
			}
		}
		else if(s[i] == '/'){
			if(cnt >= 2 || cnt == 0){
				p = 0;
				break;
			}
			else{
				cnt = 2;
			}
		}
		else{
			if(cnt == 0) username.push(s[i]);
			else if(cnt == 1) hostname.push(s[i]);
			else resource.push(s[i]);
		}
	}

	if(p == 0 || (cnt >=2 && resource.size()==0)){
		cout<<"NO"<<ln;
		return 0;
	}

	valid = 1;

	// cout<<username.size()<<" "<<hostname.size()<<" "<<resource.size()<<ln;

	check_username();
	check_hostname();
	check_resource();

	if(valid) cout<<"YES"<<ln;
	else cout<<"NO"<<ln;

	return 0;
}