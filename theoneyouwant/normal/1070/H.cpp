//by Shriram Lokhande
#include <bits/stdc++.h>
using namespace std;
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(int i = s; i >= 0; i--)
#define rforsn(i,s,e) for(int i = s; i >= e; i--)
#define clz(a) __builtin_clz(a) // count leading zeroes
#define ctz(a) __builtin_ctz(a) // count trailing zeroes
#define popc(a) __builtin_popcount(a) // count set bits 
#define ln "\n"
#define dbg(x) cerr<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(n) n.begin() , n.end() 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32; 
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef map<int,int> m32;
#pragma GCC optimize ("-O2")
template<class T,class U>
ostream& operator<< (ostream &o, const pair<T,U> &p){
	o<<p.fi<<" "<<p.se<<"      ";
	return o;
}
template<class T>
ostream& operator<< (ostream &o, const vector<T> &v){
	forstl(i,v){
		o<<i<<" ";
	}
	return o;
}
const int LIM = 2e5+5 ,MOD = 1e9+7;
int n , m , x , y;
int main()
{	
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	map<string,pair< pair < int , string> , int> > str;
	cin>>n;string s , sub , query;
	forn(i,n){
		cin>>s;
		forsn(j,0,s.length()){
			forsn(k,1,s.length()+1-j){
				sub = s.substr(j,k);
			//	dbg(sub);
				if(str.count(sub) == 0){
					str[sub].se = i;
					str[sub].fi.fi = 1 , str[sub].fi.se = s;
				}else{
					if(str[sub].se != i){				
					str[sub].fi.fi++;
					str[sub].se = i;
					}
				}
			}
		}
	}

	cin>>x;
	forn(i,x){
		cin>>query;
		if(str.count(query) == 0){
			cout<<0<<' '<<'-'<<ln;
		}else{
			cout<<str[query].fi.fi<<" "<<str[query].fi.se<<ln;
		}
	}


	return 0;
}