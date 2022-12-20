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
	v32 oo ,ol , lo ,ll;
	cin>>n;
	int totinf = 0;
	forn(i,n){
		cin>>x;
		cin>>y;
		if(x==11) ll.pb(y);
		if(x==10) lo.pb(y);
		if(x==01) ol.pb(y);
		if(x==00) oo.pb(y); 
	}
	forn(i,(int) ll.size()){
		totinf += ll[i];
	}
	sort(all(ol) , greater<int>());
	sort(all(lo),greater<int>());
	forn(i,min((int) ol.size() , (int) lo.size())){
		totinf += ol[i] + lo[i];
	}
	if(ol.size() > lo.size()){
		for(auto i = ol.begin() + lo.size() ; i < ol.end() ; i++){
			oo.pb(*i);
		}
	}else{
		for(auto i = lo.begin() + ol.size() ; i < lo.end() ; i++){
			oo.pb(*i);
		}
	}
	sort(all(oo) , greater<int>());
	forn(i,min((int) ll.size() , (int) oo.size())){
		totinf += oo[i];
	}
	cout<<totinf<<ln;


	return 0;
}