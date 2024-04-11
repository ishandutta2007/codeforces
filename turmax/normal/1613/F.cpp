#include <bits/stdc++.h>

using namespace std;
uint32_t rd() {
	uint32_t a = 0;
	for (; ; ) {
		char c = getchar();
		if (c < '0')
			return a;
		a = a * 10 + c - '0';
	}
}

template<uint32_t mod>
struct shortMint {
	uint32_t v;
	constexpr inline shortMint(uint32_t v = 0) : v(v) {}
	constexpr inline shortMint operator+(shortMint rhs) const {
		uint32_t r = v + rhs.v;
		return r < mod ? r : r - mod;
	}
	constexpr inline shortMint operator-(shortMint rhs) const {
		uint32_t r = v - rhs.v;
		return r < mod ? r : r + mod;
	}
	constexpr inline shortMint operator-() const {
		return v ? mod - v : 0;
	}
	constexpr inline shortMint operator*(shortMint rhs) const {
		return (uint64_t) v * rhs.v % mod;
	}
	constexpr inline shortMint& operator+=(shortMint rhs) {
		v += rhs.v;
		if (v >= mod)
			v -= mod;
		return *this;
	}
	constexpr inline shortMint& operator-=(shortMint rhs) {
		v -= rhs.v;
		if (v >= mod)
			v += mod;
		return *this;
	}
	constexpr inline shortMint& operator*=(shortMint rhs) {
		v = (uint64_t) v * rhs.v % mod;
		return *this;
	}
	constexpr inline bool operator==(shortMint rhs) const {
		return v == rhs.v;
	}
	constexpr inline bool operator!=(shortMint rhs) const {
		return v != rhs.v;
	}
	constexpr inline shortMint operator^(uint32_t rhs) const {
		shortMint r = 1, b = *this;
		while (rhs) {
			if (rhs & 1)
				r *= b;
			b *= b;
			rhs >>= 1;
		}
		return r;
	}
};
using mint = shortMint<998244353>;

template<bool inv = false>
void ntt(std::vector<mint>& p) {
	assert(!p.empty());
	uint32_t n = p.size();
	if (n == 1)
		return;
	assert(n == (n & -n));
	uint32_t lgn = __builtin_ctz(n);
	for (uint32_t i = 0, j = 0; i < n; i++) {
		if (i < j)
			std::swap(p[i], p[j]);
		for (uint32_t k = n >> 1; ~(j ^= k) & k; k >>= 1);
	}
	/*
		modulus: 998244353 = 2^23 * 119 + 1
		primitive root: 3
		3 ^ 119: 15311432
		15311432 ^ -1 = 469870224
	*/
	mint powers[n >> 1];
	powers[0] = 1;
	powers[1] = mint(inv ? 469870224 : 15311432) ^ (1u << 23 - lgn);
	for (uint32_t i = 2; i < n >> 1; i++)
		powers[i] = powers[i - 1] * powers[1];
	for (uint32_t i = 0; i < lgn; i++) {
		for (uint32_t j = 0; j < n; j += 2u << i) {
			for (uint32_t k = 0; k < uint32_t(1) << i; k++) {
				mint& top = p[j + k], & bottom = p[(1u << i) + j + k];
				bottom = top - bottom * powers[(n >> i + 1) * k];
				top = top + top - bottom;
			}
		}
	}
	if constexpr (inv) {
		mint invn = mint(499122177) ^ lgn;
		for (mint& i : p)
			i *= invn;
	}
}

std::vector<mint> convolution(std::vector<mint> p, std::vector<mint> q) {
	if (p.empty() || q.empty())
		return {};
	uint32_t n = p.size() + q.size() - 1;
	while (n != (n & -n))
		n += n & -n;
	p.resize(n, 0);
	q.resize(n, 0);
	ntt(p);
	ntt(q);
	for (uint32_t i = 0; i < n; i++)
		p[i] *= q[i];
	ntt<true>(p);
	while (!p.empty() && p.back() == 0)
		p.pop_back();
	return p;
}

#define int long long
const int p=998244353;
const int maxn=3e5+5;
vector <int> degs;
int fact[maxn];
int invf[maxn];
int po(int a,int b)
{
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0) {int u=po(a,b/2);return (u*u)%p;}
    else {int u=po(a,b-1);return (a*u)%p;}
}
int inv(int x) {return po(x,p-2);}
int c(int n,int k) {int ans=fact[n];ans*=invf[k];ans%=p;ans*=invf[n-k];ans%=p;return ans;}
vector <int> a[maxn];
bool used[maxn];
int cnt=0;
int ans=0;
void dfs(int x)
{
    used[x]=true;
    bool ok=false;
    int sum=0;
    for(auto v:a[x])
    {
        if(!used[v])
        {
            dfs(v);
            ++sum;
            ok=true;
        }
    }
    if(ok) {++cnt;degs.push_back(sum);}
}
vector <int> mult(vector <int> a,vector <int> b)
{
    vector <mint> a1(a.size()),b1(b.size());
    for(int i=0;i<a.size();++i) a1[i]=a[i];
    for(int i=0;i<b.size();++i) b1[i]=b[i];
    vector <mint> ans1=convolution(a1,b1);
    vector <int> ans(ans1.size());
    for(int i=0;i<ans.size();++i) ans[i]=ans1[i].v;
    return ans;
}
vector <int> mul(vector <vector <int> > v)
{
    if(v.empty()) assert(false);
    if(v.size()==1) return v[0];
    int sz1=v.size()/2;
    vector <vector<int> > v1,v2;
    for(int i=0;i<sz1;++i) v1.push_back(v[i]);
    for(int i=sz1;i<v.size();++i) v2.push_back(v[i]);
    vector <int> ans1=mul(v1);vector <int> ans2=mul(v2);
    return mult(ans1,ans2);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fact[0]=1;invf[0]=1;
    for(int i=1;i<maxn;++i) {fact[i]=fact[i-1]*i;fact[i]%=p;invf[i]=inv(fact[i]);}
    int n;
    cin>>n;
    for(int i=0;i<n-1;++i) {int x,y;cin>>x>>y;x--;y--;a[x].push_back(y);a[y].push_back(x);}
    dfs(0);
    vector <vector <int> > h;
    for(auto h1:degs) {h.push_back({1,h1});}
    vector <int> z=mul(h);
    for(int i=0;i<=cnt;++i)
    {
        if(i%2==0) ans+=z[i]*fact[n-i];
        else ans-=z[i]*fact[n-i];
        ans%=p;
    }
    cout<<((ans%p)+p)%p;
    return 0;
}