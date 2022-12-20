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

set<string> ans;
map<pair<int,string>,bool> m;
string s;
int n;

void solve(int pos, string last){
	if(m[mp(pos,last)] != 0) return;
	m[mp(pos,last)] = 1;

	string k = "";
	
	if(pos-1 >= 5){
		forsn(i,pos-1,pos+1) k += s[i];
		if(k != last){
			ans.insert(k);
			solve(pos-2,k);
		}
		if(pos-2 >= 5){
			k = s[pos-2]+k;
			if(k != last){
				ans.insert(k);
				solve(pos-3,k);
			}
		}
	}
	return;
}

int main(){
	fastio;

	cin>>s;
	n = s.length();
	solve(n-1,"xxxxx");
	cout<<ans.size()<<ln;
	forstl(r,ans){
		cout<<r<<ln;
	}

	return 0;
}