#include <bits/stdc++.h>
using namespace std;


#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void pre(){


}
const int inf = numeric_limits<int>::max();
template <class T>
struct RMQ {
		vector<vector<T>> jmp;
		RMQ(){}
			RMQ(const vector<T>& V) {
						int N = sz(V), on = 1, depth = 1;
								while (on < sz(V)) on *= 2, depth++;
										jmp.assign(depth, V);
												rep(i,depth-1) rep(j,N)
																jmp[i+1][j] = min(jmp[i][j],
																					jmp[i][min(N - 1, j + (1 << i))]);
													}

				T query(int a, int b) {
							if (b <= a) return inf;
									int dep =  31-__builtin_clz(b - a);
											return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
												}
};
RMQ<int> R;
vi z;
int solve(int l,int r){
	if(r-l<=1) return r-l;
	int x = R.query(l,r);
	rep(i,r-l){
		if(z[l+i]==x){
			return 1+max(solve(l,l+i),solve(l+i+1,r));
		}
		if(z[r-1-i]==x){
			return 1+max(solve(l,r-1-i),solve(r-i,r));
		}
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	vi v(2*n);
	int ix =0;
	rep(i,n){
		cin>>v[i];
		if(v[i]==1) ix=i;
		v[i+n] = v[i];
	}
	if(n==1){
		cout<<1<<' '<<0<<'\n';
		return 0;
	}
	z = vi(v.begin()+ix+1,v.begin()+ix+1+n-1);
	R=RMQ<int>(z);
	int lo=0,hi=sz(z);
	while(lo<hi){
		int m =(lo+hi)/2;
		if(solve(0,m)>=solve(m,sz(z))){
			hi=m;
		}
		else lo=m+1;
	}
	int ans = 1+max(solve(0,lo),solve(lo,sz(z)));
	int ansix=lo,lstns=ans;
	if(lo) ans=min(ans,1+max(solve(0,lo-1),solve(lo-1,sz(z))));
	if(ans<lstns) ansix=lo-1;
	cout<<ans<<' ';
	rep(i,n){
		if(v[i]==z[ansix%(sz(z))]){
			cout<<i;
			return 0;
		}
	}
	return 0;
}