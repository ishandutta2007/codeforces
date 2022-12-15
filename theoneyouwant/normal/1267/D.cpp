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
 
int req[257], out[257];
int done[8],stat[257],deploy;
int refe[8];
int inp(){
	int a,b,c;
	cin>>a>>b>>c;
	return 4*a+2*b+c;
}

void got(int i,int refreq);
v32 qw[8];
vp32 ans;
void doit(int i){
	if(done[i] == 1) return;
	done[i] = 1;
	forstl(q,qw[i]){
		if(q == 0) continue;
		deploy++;
		ans.pb({refe[i],q});
		if(done[out[q]] == 0)
		got(out[q],q);
	}
}

void got(int i,int refeq){
	//kyahai(i,refeq);
	refe[i] = refeq;
	doit(i);
	if(done[1] == 1 and done[2] == 1 and done[3] == 0){
		if(sz(qw[3]) != 0){
			deploy++;
			int y = qw[3].back();
			stat[y] = 1;
			refe[3] = y;

			ans.pb({refe[1],refe[3]});
			ans.pb({refe[2],refe[3]});
			qw[3].pop_back();
		}
		doit(3);
	}
	if(done[4] == 1 and done[2] == 1 and done[6] == 0){
		if(sz(qw[6]) != 0){
			int y = qw[6].back();
			stat[y] = 1;
			refe[6] = y;
			deploy++;
			ans.pb({refe[4],refe[6]});
			ans.pb({refe[2],refe[6]});
			qw[6].pop_back();
		}
		doit(6);
	}
	if(done[1] == 1 and done[4] == 1 and done[5] == 0){
		if(sz(qw[5]) != 0){
			deploy++;
			int y = qw[5].back();
			refe[5] = y;
			stat[y] = 1;
			ans.pb({refe[1],refe[5]});
			ans.pb({refe[4],refe[5]});
			qw[5].pop_back();
		}
		doit(5);
	}

}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	forn(i,n){
		req[i] = inp();
	}
	deploy = 1;
	forn(i,n){
		out[i] = inp();
		out[i] = out[i] & req[i];
		qw[req[i]].pb(i);
		if(req[i] == 0) deploy++;

	}

	forn(i,7) done[i] = 0;
	refe[7] = 0;
	done[0]=1;
	doit(7);

	if(deploy  == n){
		cout<<"Possible"<<ln;
		forn(i,n){
			cout<<((stat[i] == 1) ? 0 : 1)<<" ";
		}
		cout<<ln;
		cout<<sz(ans)<<ln;
		forstl(qw,ans){
			cout<<qw.fi+1<<" "<<qw.se+1<<ln;
		}
	}else{
		cout<<"Impossible"<<ln;
	}





}