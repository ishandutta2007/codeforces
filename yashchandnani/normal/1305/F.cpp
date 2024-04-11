#include <bits/stdc++.h>
using namespace std;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
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
bool p[10009];
void pre(){
	repA(i,2,10000){
		if(!p[i]) {
			for(int j=i;j<=10000;j+=i) p[j]=1;
		}
	}
}
typedef unsigned long long ull;
const int bits = 10;
// if all numbers are less than 2^k, set bits = 64-k
const ull po = 1 << bits;
ull mod_mul(ull a, ull b, ull &c) {
	ull x = a * (b & (po - 1)) % c;
	while ((b >>= bits) > 0) {
		a = (a << bits) % c;
		x += (a * (b & (po - 1))) % c;
	}
	return x % c;
}
ull mod_pow(ull a, ull b, ull mod) {
	if (b == 0) return 1;
	ull res = mod_pow(a, b / 2, mod);
	res = mod_mul(res, res, mod);
	if (b & 1) return mod_mul(res, a, mod);
	return res;
}
bool prime(ull p) {
	if (p == 2) return true;
	if (p == 1 || p % 2 == 0) return false;
	ull s = p - 1;
	while (s % 2 == 0) s /= 2;
	rep(i,15) {
		ull a = rand() % (p - 1) + 1, tmp = s;
		ull mod = mod_pow(a, tmp, p);
		while (tmp != p - 1 && mod != 1 && mod != p - 1) {
			mod = mod_mul(mod, mod, p);
			tmp *= 2;
		}
		if (mod != p - 1 && tmp % 2 == 0) return false;
	}
	return true;
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

vector<ull> pr;
ull f(ull a, ull n, ull &has) {
	return (mod_mul(a, a, n) + has) % n;
}
vector<ull> factor(ull d,bool fg=0) {
	vector<ull> res;
	if(fg){
	for (int i = 0; i < sz(pr) && pr[i]*pr[i] <= d; i++)
				if (d % pr[i] == 0) {
								while (d % pr[i] == 0) d /= pr[i];
											res.push_back(pr[i]);
													}
	}
	//d is now a product of at most 2 primes.
	if (d > 1) {
		if (prime(d))
			res.push_back(d);
		else while (true) {
			ull has = rand() % 2321 + 47;
			ull x = 2, y = 2, c = 1;
			for (; c==1; c = __gcd((y > x ? y - x : x - y), d)) {
				x = f(x, d, has);
				y = f(f(y, d, has), d, has);
			}
			if (c != d) {
				res.push_back(c); d /= c;
				if (d != c) res.push_back(d);
				break;
			}
		}
	}
	return res;
}
void init(int bits) {//how many bits do we use?
	vi p = eratosthenes_sieve(1 << ((bits + 2) / 3));
	pr.assign(all(p));
}

void solve(){


}
ll a[200009];
vector<ll> v;
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	init(50);
	int n;cin>>n;
	int ans = 0;
	rep(i,n){
		cin>>a[i];
		if(a[i]%2) ans++;
	}
	vector<ll> s;
	ll lo = max(1ll,a[0]-10000+1)-1;
	ll hi = a[0]+10000-1;
	ll qq=lo+1;
	while(qq<=hi) v.pb(qq),qq++;
	trav(i,pr){
		ll st = lo+i-(lo%i);
		if(st<=hi) s.pb(i);
		while(st<=hi){
			int ix=st-lo-1;
			while(v[ix]%i==0){
				v[ix]/=i;
			}
			st+=i;
		}
	}
	trav(i,v){
		if(i>1){
			vector<ull> cur = factor(i);
			trav(j,cur) s.pb(j);
		}
	}
	random_shuffle(a,a+n);
	rep(i,min(1000,n)){
			vector<ull> cur = factor(a[i],1);
			trav(j,cur) s.pb(j);
	}
	sort(all(s));
	s.resize(distance(s.begin(),unique(all(s))));
	trav(i,s){
		ll cur=0;
		int j=0;
		while(cur<=ans&&j<n){
			if(a[j]>=i) cur+=min(a[j]%i,i-a[j]%i);
			else cur+=i-a[j];
			j++;
		}
		ans=min(ll(ans),cur);
	}
	cout<<ans;
	return 0;
}