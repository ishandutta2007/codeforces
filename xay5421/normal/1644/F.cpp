#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
constexpr int P = 998244353;
namespace jiangly{
using i64 = long long;
// assume -P <= x < 2P
int norm(int x) {
	if (x < 0) {
		x += P;
	}
	if (x >= P) {
		x -= P;
	}
	return x;
}
template<class T>
T power(T a, int b) {
	T res = 1;
	for (; b; b /= 2, a *= a) {
		if (b % 2) {
			res *= a;
		}
	}
	return res;
}
struct Z {
	int x;
	Z(int x = 0) : x(norm(x)) {}
	int val() const {
		return x;
	}
	Z operator-() const {
		return Z(norm(P - x));
	}
	Z inv() const {
		assert(x != 0);
		return power(*this, P - 2);
	}
	Z &operator*=(const Z &rhs) {
		x = i64(x) * rhs.x % P;
		return *this;
	}
	Z &operator+=(const Z &rhs) {
		x = norm(x + rhs.x);
		return *this;
	}
	Z &operator-=(const Z &rhs) {
		x = norm(x - rhs.x);
		return *this;
	}
	Z &operator/=(const Z &rhs) {
		return *this *= rhs.inv();
	}
	friend Z operator*(const Z &lhs, const Z &rhs) {
		Z res = lhs;
		res *= rhs;
		return res;
	}
	friend Z operator+(const Z &lhs, const Z &rhs) {
		Z res = lhs;
		res += rhs;
		return res;
	}
	friend Z operator-(const Z &lhs, const Z &rhs) {
		Z res = lhs;
		res -= rhs;
		return res;
	}
	friend Z operator/(const Z &lhs, const Z &rhs) {
		Z res = lhs;
		res /= rhs;
		return res;
	}
};
 
std::vector<int> rev;
std::vector<Z> roots{0, 1};
void dft(std::vector<Z> &a) {
    int n = a.size();
    
    if (int(rev.size()) != n) {
        int k = __builtin_ctz(n) - 1;
        rev.resize(n);
        for (int i = 0; i < n; i++) {
            rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (rev[i] < i) {
            std::swap(a[i], a[rev[i]]);
        }
    }
    if (int(roots.size()) < n) {
        int k = __builtin_ctz(roots.size());
        roots.resize(n);
        while ((1 << k) < n) {
            Z e = power(Z(3), (P - 1) >> (k + 1));
            for (int i = 1 << (k - 1); i < (1 << k); i++) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = roots[i] * e;
            }
            k++;
        }
    }
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                Z u = a[i + j];
                Z v = a[i + j + k] * roots[k + j];
                a[i + j] = u + v;
                a[i + j + k] = u - v;
            }
        }
    }
}
void idft(std::vector<Z> &a) {
    int n = a.size();
    std::reverse(a.begin() + 1, a.end());
    dft(a);
    Z inv = (1 - P) / n;
    for (int i = 0; i < n; i++) {
        a[i] *= inv;
    }
}
struct Poly {
    std::vector<Z> a;
    Poly() {}
    Poly(const std::vector<Z> &a) : a(a) {}
    Poly(const std::initializer_list<Z> &a) : a(a) {}
    int size() const {
        return a.size();
    }
    void resize(int n) {
        a.resize(n);
    }
    Z operator[](int idx) const {
        if (idx < 0 || idx >= size()) {
            return 0;
        }
        return a[idx];
    }
    Z &operator[](int idx) {
        return a[idx];
    }
    Poly mulxk(int k) const {
        auto b = a;
        b.insert(b.begin(), k, 0);
        return Poly(b);
    }
    Poly modxk(int k) const {
        k = std::min(k, size());
        return Poly(std::vector<Z>(a.begin(), a.begin() + k));
    }
    Poly divxk(int k) const {
        if (size() <= k) {
            return Poly();
        }
        return Poly(std::vector<Z>(a.begin() + k, a.end()));
    }
    friend Poly operator+(const Poly &a, const Poly &b) {
        std::vector<Z> res(std::max(a.size(), b.size()));
        for (int i = 0; i < int(res.size()); i++) {
            res[i] = a[i] + b[i];
        }
        return Poly(res);
    }
    friend Poly operator-(const Poly &a, const Poly &b) {
        std::vector<Z> res(std::max(a.size(), b.size()));
        for (int i = 0; i < int(res.size()); i++) {
            res[i] = a[i] - b[i];
        }
        return Poly(res);
    }
    friend Poly operator*(Poly a, Poly b) {
        if (a.size() == 0 || b.size() == 0) {
            return Poly();
        }
        int sz = 1, tot = a.size() + b.size() - 1;
        while (sz < tot)
            sz *= 2;
        a.a.resize(sz);
        b.a.resize(sz);
        dft(a.a);
        dft(b.a);
        for (int i = 0; i < sz; ++i) {
            a.a[i] = a[i] * b[i];
        }
        idft(a.a);
        a.resize(tot);
        return a;
    }
    friend Poly operator*(Z a, Poly b) {
        for (int i = 0; i < int(b.size()); i++) {
            b[i] *= a;
        }
        return b;
    }
    friend Poly operator*(Poly a, Z b) {
        for (int i = 0; i < int(a.size()); i++) {
            a[i] *= b;
        }
        return a;
    }
    Poly &operator+=(Poly b) {
        return (*this) = (*this) + b;
    }
    Poly &operator-=(Poly b) {
        return (*this) = (*this) - b;
    }
    Poly &operator*=(Poly b) {
        return (*this) = (*this) * b;
    }
    Poly deriv() const {
        if (a.empty()) {
            return Poly();
        }
        std::vector<Z> res(size() - 1);
        for (int i = 0; i < size() - 1; ++i) {
            res[i] = (i + 1) * a[i + 1];
        }
        return Poly(res);
    }
    Poly integr() const {
        std::vector<Z> res(size() + 1);
        for (int i = 0; i < size(); ++i) {
            res[i + 1] = a[i] / (i + 1);
        }
        return Poly(res);
    }
    Poly inv(int m) const {
        Poly x{a[0].inv()};
        int k = 1;
        while (k < m) {
            k *= 2;
            x = (x * (Poly{2} - modxk(k) * x)).modxk(k);
        }
        return x.modxk(m);
    }
    Poly log(int m) const {
        return (deriv() * inv(m)).integr().modxk(m);
    }
    Poly exp(int m) const {
        Poly x{1};
        int k = 1;
        while (k < m) {
            k *= 2;
            x = (x * (Poly{1} - x.log(k) + modxk(k))).modxk(k);
        }
        return x.modxk(m);
    }
    Poly sqrt(int m) const {
        Poly x{1};
        int k = 1;
        while (k < m) {
            k *= 2;
            x = (x + (modxk(k) * x.inv(k)).modxk(k)) * ((P + 1) / 2);
        }
        return x.modxk(m);
    }
    Poly mulT(Poly b) const {
        if (b.size() == 0) {
            return Poly();
        }
        int n = b.size();
        std::reverse(b.a.begin(), b.a.end());
        return ((*this) * b).divxk(n - 1);
    }
    std::vector<Z> eval(std::vector<Z> x) const {
        if (size() == 0) {
            return std::vector<Z>(x.size(), 0);
        }
        const int n = std::max(int(x.size()), size());
        std::vector<Poly> q(4 * n);
        std::vector<Z> ans(x.size());
        x.resize(n);
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                q[p] = Poly{1, -x[l]};
            } else {
                int m = (l + r) / 2;
                build(2 * p, l, m);
                build(2 * p + 1, m, r);
                q[p] = q[2 * p] * q[2 * p + 1];
            }
        };
        build(1, 0, n);
        std::function<void(int, int, int, const Poly &)> work = [&](int p, int l, int r, const Poly &num) {
            if (r - l == 1) {
                if (l < int(ans.size())) {
                    ans[l] = num[0];
                }
            } else {
                int m = (l + r) / 2;
                work(2 * p, l, m, num.mulT(q[2 * p + 1]).modxk(m - l));
                work(2 * p + 1, m, r, num.mulT(q[2 * p]).modxk(r - m));
            }
        };
        work(1, 0, n, mulT(q[1].inv(n)));
        return ans;
    }
};

}
using Z=jiangly::Z;
using Poly=jiangly::Poly;
using namespace std;
const int N=200005;
Z fac[N],ifac[N];
Z C(int n,int m){
	if(m<0||n-m<0)return Z(0);
	return fac[n]*ifac[m]*ifac[n-m];
}
Z calc(int n,int K){
	Poly f,g;
	f.resize(n+1);
	g.resize(n+1);
	rep(i,0,n)f[i]=power(Z(i),n)*ifac[i];
	rep(i,0,n)g[i]=i&1?-ifac[i]:ifac[i];
	f=(f*g).modxk(n+1);
	K=min(K,n);
	Z ans=0;
	rep(i,0,K)ans+=f[i];
	return ans;
}
int main(){
#ifdef local
	freopen("a.in","r",stdin);
#endif
	fac[0]=1;
	rep(i,1,N-1)fac[i]=fac[i-1]*i;
	ifac[N-1]=fac[N-1].inv();
	per(i,N-1,1)ifac[i-1]=ifac[i]*i;
	int n,K;
	scanf("%d%d",&n,&K);
	if(K==1)puts("1"),exit(0);
	Poly base;
	base.resize(n+1);
	rep(i,1,n){
		base[i]=ifac[i];
	}
	Poly g;
	g.resize(n+1);
	vector<bool>vis(n+1);
	rep(i,1,n){
		vis[n/i]=1;
		if(i!=1)vis[n/i+1]=1;
	}
	//rep(i,1,n)vis[i]=1;
	if(0){
		Poly f({1});
		K=min(K,n);
		rep(i,0,K){
			if(i){
				f=(f*base).modxk(n+1);
			}
			g=g+f*ifac[i];
		}
		rep(i,0,n)g[i]*=fac[i];
	}else{
		rep(i,1,n)if(vis[i]){
			g[i]=calc(i,K);
		}
	}
	rep(i,2,n)g[i]-=g[1];
	vector<Z>cf(n+1);
	rep(i,2,n){
		cf[i]+=cf[i-1];
		g[i]+=cf[i];
		rep(k,2,n/(i-1)+5){
			int l=k*i-(k-1);
			if(l<=i)l=i+1;
			int r=k*i;
			if(r>=n)r=n;
			if(l<=r){
				cf[l]-=g[i];
				if(r<n)cf[r+1]+=g[i];
			}
			if(l<=n&&r>=n){
				assert(vis[i]);
			}
		}
	}
	printf("%d\n",g[n].val());
}