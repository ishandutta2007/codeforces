#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long ll;
using namespace std;

template <typename T>
void read(T &x){
	int fl=0,ch;
	while (ch=getchar(),ch<48||57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch&&ch<58) x=(x+(x<<2)<<1)+(ch&15);
	if (fl) x=-x;
}

template <typename T>
void print(T x){
	if (x<0) x=-x,putchar('-');
	if (x>9) print(x/10);
	putchar(x%10+48);
}

template <typename T>
void print(T x,int ch){
	print(x),putchar(ch);
}

template <typename T>
T max(const T &x,const T &y){return x<y?y:x;}

template <typename T>
T min(const T &x,const T &y){return x<y?x:y;}

const int P=998244353;

int n,k;

inline int add(int x,int y) {
	x+=y;
	if(x>=P) x-=P;
	return x;
}

inline int sub(int x,int y) {
	x-=y;
	if(x<0) x+=P;
	return x;
}

inline int mul(int x,int y) {
	return (ll)x*y%P;
}

inline int fpow(int x,int y) {
	int ans=1;
	while(y) {
		if(y&1) ans=mul(ans,x);
		y>>=1; x=mul(x,x);
	}
	return ans;
}

namespace ntt {
	int base=1,root=-1,maxbase=-1;
	vector <int> roots={0,1},rev={0,1};
	
	void init() {
		int tmp=P-1; maxbase=0;
		while(!(tmp&1)) {
			tmp>>=1;
			maxbase++;
		}
		root=2;
		while(1) {
			if(fpow(root,1<<maxbase)==1&&fpow(root,1<<(maxbase-1)) != 1) break;
			root++;
		}
	}
	
	void ensure_base(int nbase) {
		if(maxbase==-1) init();
		if(nbase <= base) return;
		rev.resize(1<<nbase);
		for(register int i=1; i<(1<<nbase); i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(nbase-1));
		roots.resize(1<<nbase);
		while(base<nbase) {
			int z=fpow(root,1<<(maxbase-base-1));
			for(register int i=(1<<(base-1)); i<(1<<base); i++) {
				roots[i<<1]=roots[i];
				roots[i<<1|1]=mul(roots[i],z);
			}
			base++;
		} 
	}
	
	void dft(vector <int> &a) {
		int n=a.size(),zeros=__builtin_ctz(n);
		ensure_base(zeros);
		int shift=base-zeros;
		for(register int i=0; i<n; i++) if(i<(rev[i]>>shift)) swap(a[i],a[rev[i]>>shift]);
		for(register int mid=1; mid<n; mid <<= 1) {
			for(register int i=0; i<n; i+=(mid<<1)) {
				for(register int j=0; j<mid; j++) {
					int x=a[i+j],y=mul(a[i+j+mid],roots[mid+j]);
					a[i+j]=add(x,y); a[i+j+mid]=sub(x,y);
				}
			}
		}
	}
	
	vector <int> pmul(vector <int> a,vector <int> b) {
		int need=a.size()+b.size()-1,nbase=0;
		while((1<<nbase)<need) nbase++;
		ensure_base(nbase); int size=1<<nbase;
		a.resize(size); b.resize(size); dft(a); dft(b);
		int inv=fpow(size,P-2);
		for(register int i=0; i<size; i++) a[i]=mul(a[i],mul(b[i],inv));
		reverse(a.begin()+1,a.end()); dft(a); a.resize(need); return a;
	}
}
using namespace ntt;

int bin[15],a[15],ans;
vector <int> e,res;

signed main() {
	read(n),read(k);
	rep (i,1,k) read(a[i]),++bin[a[i]];
	rep (i,0,9) e.push_back(bin[i]);
	res.push_back(1);
	int t=n>>1;
	while (t){
		if (t&1) res=pmul(res,e);
		t>>=1;
		e=pmul(e,e);
	}
	rep (i,0,(int)res.size()-1) ans=(ans+(ll)res[i]*res[i]%P)%P;
	print(ans,'\n');
	return 0;
}