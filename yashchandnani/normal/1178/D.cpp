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
const int MAX_PR = 5000000;
bitset<MAX_PR> isprime;
vi eratosthenes_sieve(int lim) {
		isprime.set(); isprime[0] = isprime[1] = 0;
			for (int i = 4; i < lim; i += 2) isprime[i] = 0;
				for (int i = 3; i*i < lim; i += 2) if (isprime[i])
							for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
					vi pr;
						repA(i,2,lim-1) if (isprime[i]) pr.push_back(i);
							return pr;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	vi pr = eratosthenes_sieve(1501);
	int x = *lower_bound(all(pr),n);
	cout<<x<<'\n';
	rep(i,n) cout<<i+1<<' '<<(i+1)%n+1<<'\n';
	rep(i,x-n){
		cout<<i+1<<' '<<(i+n/2)%n+1<<'\n';
	}
	
	return 0;
}