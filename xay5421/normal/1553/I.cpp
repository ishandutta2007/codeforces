// author: xay5421
// created: Thu Jul 22 23:45:31 2021
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int P=998244353;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<typename... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<typename... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<typename... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
template<typename... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
namespace ntt{
	int base=1,root=-1,maxbase=-1;
	std::vector<int>roots={0,1},rev={0,1};
	void init(){
		int tmp=P-1;
		maxbase=0;
		while(!(tmp&1))tmp>>=1,maxbase++;
		root=2;
		while(1){
			if(po(root,1<<maxbase)==1&&po(root,1<<(maxbase-1))!=1)break;
			root++;
		}
	}
	void ensure_base(int nbase){
		if(maxbase==-1)init();
		if(nbase<=base)return;
		rev.resize(1<<nbase);
		for(int i=1;i<(1<<nbase);++i)rev[i]=(rev[i>>1]>>1)|((i&1)<<(nbase-1));
		roots.resize(1<<nbase);
		while(base<nbase){
			int z=po(root,1<<(maxbase-base-1));
			for(int i=(1<<(base-1));i<(1<<base);++i)roots[i<<1]=roots[i],roots[i<<1|1]=mu(roots[i],z);
			base++;
		}
	}
	void dft(std::vector<int>&a){
		int n=a.size(),zeros=__builtin_ctz(n);
		ensure_base(zeros);
		int shift=base-zeros;
		for(int i=0;i<n;++i)if(i<(rev[i]>>shift))std::swap(a[i],a[rev[i]>>shift]);
		for(int mid=1;mid<n;mid<<=1)for(int i=0;i<n;i+=(mid<<1))for(int j=0;j<mid;++j){
			int x=a[i+j],y=mu(a[i+j+mid],roots[mid+j]);
			a[i+j]=ad(x,y);
			a[i+j+mid]=su(x,y);
		}
	}
	std::vector<int>operator*(std::vector<int>a,std::vector<int>b){
		if(SZ(a)<=50&&SZ(b)<=50){
			vector<int>c(SZ(a)+SZ(b)-1);
			rep(i,0,SZ(a)-1)rep(j,0,SZ(b)-1)uad(c[i+j],mu(a[i],b[j]));
			return c;
		}
		int need=a.size()+b.size()-1,nbase=0;
		while((1<<nbase)<need)nbase++;
		ensure_base(nbase);
		int size=1<<nbase;
		a.resize(size);
		b.resize(size);
		dft(a);
		dft(b);
		int inv=po(size,P-2);
		for(int i=0;i<size;++i)a[i]=mu(a[i],mu(b[i],inv));
		std::reverse(a.begin()+1,a.end());
		dft(a);
		a.resize(need);
		return a;
	}
}
using ntt::operator *;

vector<int>operator+(vector<int>a,vector<int>b){
    if(a.size()<b.size())a.resize(b.size());
    for(int i=0;i<(int)b.size();i++)uad(a[i],b[i]);
    return a;
}

const int N = 1e5 + 5;

vector <int> poly[N];
int a[N], b[N], fac[N], inv[N];
int n, m, tot;

vector <int> solve(int l, int r) {
    if (l == r) return poly[l];
    int mid = (l + r) >> 1;
    return solve(l, mid) * solve(mid + 1, r);
}

vector <int> f[N][2][2];
int vis[N][2][2];
vector <int> calc(int len, int l, int r) {
    if (len == 0) {
        vector <int> ans(1);
        ans[0] = 1;
        return ans;
    }
    if (len == 1) {
        vector <int> ans(2);
        ans[0] = 1; ans[1] = mu((P + 1) / 2, po(2, 2 - l - r));
        return ans;
    }
    if (len == 2) {
        vector <int> ans(3);
        ans[0] = 1;
        ans[1] = 4 - l - r;
        ans[2] = mu((P + 1) / 2, po(2, 2 - l - r));
        return ans;
    }
    if (vis[len][l][r]) return f[len][l][r];
    vis[len][l][r] = 1;
    for (int i = 0; i <= 1; i++) {
        vector <int> L = calc((len - 1) >> 1, l, i);
        vector <int> R = calc(len >> 1, i, r);
        L = L * R;
        if (i == 1) {
            L.push_back(0);
            for (int i = (int)L.size() - 1; i >= 1; i--) L[i] = mu(L[i - 1], 2);
            L[0] = 0;
        }
        f[len][l][r] = f[len][l][r] + L;
    }
    return f[len][l][r];
}

int main() {
    fac[0] = 1;
    for (int i = 1; i <= 100000; i++) fac[i] = mu(fac[i - 1], i);
    inv[100000] = po(fac[100000], P - 2);
    for (int i = 100000; i >= 1; i--) inv[i - 1] = mu(inv[i], i);
    rd(n);
    for (int i = 1; i <= n; i++) rd(a[i]);
    for (int l = 1, r; l <= n; l = r + 1) {
        int len = a[l]; r = l + len - 1;
        if (r > n) {
            pt(0, '\n');
            return 0;
        }
        for (int i = l; i <= r; i++) {
            if (a[i] != len) {
                pt(0, '\n');
                return 0;
            }
        }
        b[++m] = len;
    }
    for (int l = 1, r; l <= m; l = r + 1) {
        r = l;
        if (b[l] != 1) continue;
        while (r < m && b[r + 1] == 1) ++r;
        poly[++tot] = calc(r - l + (l != 1) + (r != m), l != 1, r != m);
    }
    for (int i = 1; i < m; i++) {
        if (b[i] != 1 && b[i + 1] != 1) {
            ++tot;
            poly[tot].resize(2);
            poly[tot][0] = 1;
            poly[tot][1] = (P + 1) / 2;
        }
    }
    int coef = 1;
    for (int i = 1; i <= m; i++) {
        if (b[i] != 1) {
            coef = mu(coef, 2);
        }
    }
    vector <int> res(1, 1);
    if (tot) res = solve(1, tot);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int now = mu(res[i], fac[m - i]);
        if (i & 1) ans = su(ans, now);
        else ans = ad(ans, now);
    }
    pt(mu(ans, coef), '\n');
    return 0;
}