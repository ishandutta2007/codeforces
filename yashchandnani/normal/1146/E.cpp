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

void solve(){


}
int ans[100009][2];
string s[100009];
int x[100009];
vector<pii> upd[200009];
int fns[200009],a[100009];
struct FT {
		vector<ll> s;
			FT(int n) : s(n) {}
				void update(int pos, ll dif) { // a[pos] += dif
							for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
								}
					ll query(int pos) { // sum of values in [0, pos)
								ll res = 0;
										for (; pos > 0; pos &= pos - 1) res += s[pos-1];
												return res;
													}
						int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
									// Returns n if no sum is >= sum, or -1 if empty sum is.
									if (sum <= 0) return -1;
											int pos = 0;
													for (int pw = 1 << 25; pw; pw >>= 1) {
																	if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
																						pos += pw, sum -= s[pos-1];
																			}
															return pos;
																}
};
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	int q;cin>>q;
	rep(i,n) cin>>a[i];
	set<pii> s1;
	rep(i,q) {
		cin>>s[i]>>x[i];
		if(s[i]==">") upd[abs(x[i])].pb(mp(i,-1)),s1.insert({i,-1});
		else upd[abs(x[i])].pb(mp(i,1)),s1.insert({i,1});
		
	}
	int cnt = 0;
	FT T(100007);
	repD(i,100000,0){
		int cnt2 = 0;
		int lst = -1;
		trav(j,upd[i]){
			if(x[j.fst]>0&&s[j.fst]==">") s1.erase({j.fst,j.snd});
			if(x[j.fst]<0&&s[j.fst]=="<") s1.erase({j.fst,j.snd});;
		}
		if(sz(s1)){
			auto it = s1.end();
			it--;
			lst = it->fst;
			fns[i+100000] = i*it->snd;
			fns[-i+100000] = i*it->snd;
		}
		else fns[i+100000] = i,fns[-i+100000] = -i;
		if((T.query(100003)-T.query(lst+1))%2) fns[i+100000] = -fns[i+100000],fns[-i+100000]=-fns[-i+100000];	
		trav(j,upd[i]){
			s1.erase({j.fst,j.snd});
			if(x[j.fst]>0&&s[j.fst]=="<") cnt2++,T.update(j.fst,1);
			if(x[j.fst]<0&&s[j.fst]==">") cnt2++,T.update(j.fst,1);
		}
		cnt+=cnt2;
	}
	rep(i,n){
		cout<<fns[a[i]+100000]<<' ';
	}
	return 0;
}