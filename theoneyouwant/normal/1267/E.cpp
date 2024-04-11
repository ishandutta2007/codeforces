#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(int i = s; i >= 0; i--)
#define rforsn(i,s,e) for(int i = s; i >= e; i--)
#define testcases(t) int t,myzx;cin>>myzx;forsn(t,1,myzx+1) 
#define clz(a) __builtin_clz(a) // count leading zeroes
#define ctz(a) __builtin_ctz(a) // count trailing zeroes
#define popc(a) __builtin_popcount(a) // count set bits 
#define ln "\n"
#define kyahai(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cout<<ln; }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << "\t\t";
	err(++it, args...);
}
#define sz(n) (int)n.size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(n) n.begin() , n.end() 
#define tfi first.first
#define tse first.second
#define tth second
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
typedef pair< pair<int,int> , int> tri;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; 
//like set just find_by_order() and order_of_key() are extra
 
#pragma GCC optimize ("-O3")
template < typename tp > void in( tp & dig ){
    char ch=getchar();dig=0;ll flag=0;
    while(!isdigit(ch)){ if(ch=='-')flag=1;ch=getchar(); }
    while(isdigit(ch))dig=dig*10+ch-'0',ch=getchar();
    if(flag)dig=-dig;
}
const int LIM = 2e5+5 ,MOD = 1e9+7;
const double EPS = 1e-9;
int n , m , t , x ,y ;
 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int a[n][m];
	forn(i,m){
		forn(j,n)
		cin>>a[j][i];
	}
	int ans = m;
	v32 res;
	forn(i,n-1){
		p32 b[m];
		int sum = 0;
		forn(j,m){
			b[j].fi = a[n-1][j]-a[i][j];
			b[j].se = j;
			sum += b[j].fi;
		}
		v32 currres;
		int curr = 0;
		int it = m-1;
		sort(b,b+m);
		while(sum > 0){
			//kyahai(sum,i,it);
			sum -= b[it].fi;
			currres.pb(b[it].se);
			curr++;
			it--;
		}
		ans =  min(ans,curr);
		if(curr == ans){
			res = currres;
		}
	}
	cout<<sz(res)<<ln;
	forstl(q,res){
		cout<<q+1<<" ";
	}

}