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
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define dbg2(x,y) cerr<<#x<<" = "<<x<<" & "<<#y<<" = "<<y<<endl;
#define dbgstl32(v) cerr<<#v<<" = \n"; { int c=0; forstl(it,v) \
cerr<<"    Term "<< ++c <<" = "<<it<<ln;} cerr<<endl
#define dbgstlp32(v) cerr<<#v<<" = \n"; { int c=0; forstl(it,v) \
cerr<<"    Term "<< ++c <<" = "<<it.fi<<" , "<<it.se<<ln;} cerr<<endl
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define inp freopen("input.txt", "r", stdin)
#define outp freopen("output.txt", "w", stdout)
#define dbgm(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
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
const int LIM = 2e5+5,PLIM=1e6+5, MOD = 1e9+7;
int t,n,m,k,x,y,id,in;
int l,r,c[LIM],p[LIM];
ll ft1[PLIM];
ll ft2[PLIM];
map<int,int> M;
ll get(int i){
	ll ans=0;
	while(i){
		ans+=ft1[i];
		i-=(i& -i);
	}
	return ans;
}
ll get2(int i){
	ll ans=0;
	while(i){
		ans+=ft2[i];
		i-=(i& -i);
	}
	return ans;
}
void add(int i,int val){
	int j=i;
	while(i<PLIM){
		ft1[i]+=val;
		ft2[i]+=j*(ll)val;
		i+=(i& -i);
	}
}
ll solve(){
	int l=0,h=PLIM;
	while(l<h){
		int mid=(l+h)/2;
		//dbg(mid);
		if(get(mid)>k){
			h=mid;
		}else{
			if(get(mid+1)>k){
				l=mid;
				break;
			}
			l=mid+1;
		}
	}
	ll x=get(l);
	auto it=M.upper_bound(l);
	if(it==M.end()){
		return get2(l);
	}
	return get2(l)+((*it).fi)*(k-x);
}
int main(){
	fastio;
	cin>>n>>k>>m;
	map<int,vp32 > q;
	forn(i,m){
		cin>>l>>r>>c[i]>>p[i];
		q[l].pb(mp(1,i));
		q[r+1].pb(mp(-1,i));
	}
	ll price=0;
	forsn(i,1,n+1){
		if(q.find(i)==q.end()){
			price+=solve();
			continue;
		}
		auto &qu=q[i];
		forstl(it,qu){
			tie(id,in)=it;
			if(id==1){
				add(p[in],c[in]);
				M[p[in]]+=c[in];
			}else{
				add(p[in],-c[in]);
				M[p[in]]-=c[in];
				if(M[p[in]]==0) M.erase(p[in]);
			}
		}
		price+=solve();
	}
	cout<<price<<ln;
	return 0;
}