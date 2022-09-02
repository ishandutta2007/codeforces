// author: xay5421
// created: Sat Oct	9 19:42:25 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
const int P=1e9+7;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<typename... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<typename... T>int su(int k1,T... k2){return su(k1,ad(k2...));}
template<typename... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
template<typename... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<typename... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const LL INFLL=0X3F3F3F3F3F3F3F3FLL;
const int N=50005;
int n,Q,a[2][N];
struct mat{
	int a[2][2];
	mat operator*(const mat&b)const{
		mat c;
		rep(i,0,1)rep(j,0,1)c.a[i][j]=(1LL*a[i][0]*b.a[0][j]+1LL*a[i][1]*b.a[1][j])%P;
		return c;
	}
	mat operator+(const mat&b)const{
		mat c;
		rep(i,0,1)rep(j,0,1)c.a[i][j]=ad(a[i][j],b.a[i][j]);
		return c;
	}
	mat operator-(const mat&b)const{
		mat c;
		rep(i,0,1)rep(j,0,1)c.a[i][j]=su(a[i][j],b.a[i][j]);
		return c;
	}
	mat operator*(const int&k)const{
		mat c;
		rep(i,0,1)rep(j,0,1)c.a[i][j]=mu(a[i][j],k);
		return c;
	}
	mat inv()const{
		const int I=po(((1LL*a[0][0]*a[1][1]-1LL*a[0][1]*a[1][0])%P+P)%P,P-2);
		return (mat){{{a[1][1],su(0,a[0][1])},{su(0,a[1][0]),a[0][0]}}}*I;
	}
	void operator+=(const mat&k){
		rep(i,0,1)rep(j,0,1)uad(a[i][j],k.a[i][j]);
	}
}base=(mat){{{1,1},{1,0}}};
mat get_mat(LL k){
	if(k<0){
		return get_mat(-k).inv();
	}
	mat res=(mat){{{1,0},{0,1}}};
	mat w=base;
	while(k){
		if(k&1){
			res=res*w;
		}
		k>>=1;
		if(k)w=w*w;
	}
	return res;
}
struct fibint{
	LL x;
	mat mt;
	bool operator<(const fibint&k)const{return x<k.x;}
	bool operator>(const fibint&k)const{return x>k.x;}
	bool operator<=(const fibint&k)const{return x<=k.x;}
	bool operator>=(const fibint&k)const{return x>=k.x;}
	bool operator==(const fibint&k)const{return x==k.x;}
	bool operator!=(const LL&k)const{return x!=k;}
	fibint operator+(const fibint&k)const{
		return (fibint){x+k.x,mt*k.mt};
	}
	fibint operator-(const fibint&k)const{
		return (fibint){x-k.x,mt*k.mt.inv()};
	}
	void operator+=(const fibint&k){
		x+=k.x,mt=mt*k.mt;
	}
};
struct segment_tree_beats{
	struct data {
		fibint mx, mx2, mn, mn2, tmx, tmn, tad;
		int cmx, cmn;
		mat sum;
	} t[N*4];

	void pushup(int u) {
		const int lu = u << 1, ru = u << 1 | 1;
		t[u].sum = t[lu].sum + t[ru].sum;
		if (t[lu].mx == t[ru].mx) {
			t[u].mx = t[lu].mx, t[u].cmx = t[lu].cmx + t[ru].cmx;
			t[u].mx2 = max(t[lu].mx2, t[ru].mx2);
		} else if (t[lu].mx > t[ru].mx) {
			t[u].mx = t[lu].mx, t[u].cmx = t[lu].cmx;
			t[u].mx2 = max(t[lu].mx2, t[ru].mx);
		} else {
			t[u].mx = t[ru].mx, t[u].cmx = t[ru].cmx;
			t[u].mx2 = max(t[lu].mx, t[ru].mx2);
		}
		if (t[lu].mn == t[ru].mn) {
			t[u].mn = t[lu].mn, t[u].cmn = t[lu].cmn + t[ru].cmn;
			t[u].mn2 = min(t[lu].mn2, t[ru].mn2);
		} else if (t[lu].mn < t[ru].mn) {
			t[u].mn = t[lu].mn, t[u].cmn = t[lu].cmn;
			t[u].mn2 = min(t[lu].mn2, t[ru].mn);
		} else {
			t[u].mn = t[ru].mn, t[u].cmn = t[ru].cmn;
			t[u].mn2 = min(t[lu].mn, t[ru].mn2);
		}
	}
	void push_add(int u, int l, int r, fibint v) {
		//  $\min$  $\max$ 
		//t[u].sum += v.mt * (r - l + 1);
		t[u].sum=t[u].sum*v.mt;
		t[u].mx += v, t[u].mn += v;
		if (t[u].mx2 != -INFLL) t[u].mx2 += v;
		if (t[u].mn2 != INFLL) t[u].mn2 += v;
		if (t[u].tmx != -INFLL) t[u].tmx += v;
		if (t[u].tmn != INFLL) t[u].tmn += v;
		t[u].tad += v;
	}
	void push_min(int u, fibint tg) {
		//  $\max$ 
		if (t[u].mx <= tg) return;
		t[u].sum += (tg.mt - t[u].mx.mt) * t[u].cmx;
		if (t[u].mn2 == t[u].mx) t[u].mn2 = tg;	// !!!
		if (t[u].mn == t[u].mx) t[u].mn = tg;		// !!!!!
		if (t[u].tmx > tg) t[u].tmx = tg;				//  $\max$ 
		t[u].mx = tg, t[u].tmn = tg;
	}
	void push_max(int u, fibint tg) {
		if (t[u].mn > tg) return;
		t[u].sum += (tg.mt - t[u].mn.mt)* t[u].cmn;
		if (t[u].mx2 == t[u].mn) t[u].mx2 = tg;
		if (t[u].mx == t[u].mn) t[u].mx = tg;
		if (t[u].tmn < tg) t[u].tmn = tg;
		t[u].mn = tg, t[u].tmx = tg;
	}
	void pushdown(int u, int l, int r) {
		const int lu = u << 1, ru = u << 1 | 1, mid = (l + r) >> 1;
		if (t[u].tad.x)
			push_add(lu, l, mid, t[u].tad), push_add(ru, mid + 1, r, t[u].tad);
		if (t[u].tmx != -INFLL) push_max(lu, t[u].tmx), push_max(ru, t[u].tmx);
		if (t[u].tmn != INFLL) push_min(lu, t[u].tmn), push_min(ru, t[u].tmn);
		t[u].tad = (fibint){0,(mat){{{1,0},{0,1}}}}, t[u].tmx = (fibint){-INFLL, (mat){{{0,0},{0,0}}}}, t[u].tmn = (fibint){INFLL, (mat){{{0,0},{0,0}}}};
	}
	void build(int*a, int u = 1, int l = 1, int r = n) {
		//D("u=%d l=%d r=%d\n",u,l,r);
		t[u].tmn = (fibint){INFLL, (mat){{{0,0},{0,0}}}}, t[u].tmx = (fibint){-INFLL, (mat){{{0,0},{0,0}}}};	// 
		t[u].tad = (fibint){0,(mat){{{1,0},{0,1}}}};
		if (l == r) {
			t[u].mx = t[u].mn = (fibint){a[l], t[u].sum = get_mat(a[l])};
			t[u].mx2 = (fibint){-INFLL, (mat){{{0,0},{0,0}}}}, t[u].mn2 = (fibint){INFLL, (mat){{{0,0},{0,0}}}};
			t[u].cmx = t[u].cmn = 1;
			return;
		}
		int mid = (l + r) >> 1;
		build(a, u << 1, l, mid), build(a, u << 1 | 1, mid + 1, r);
		pushup(u);
	}
	void add(int L, int R, const fibint&v, int u = 1, int l = 1, int r = n) {
		if (R < l || r < L) return;
		if (L <= l && r <= R) return push_add(u, l, r, v);	// !!!  return
		int mid = (l + r) >> 1;
		pushdown(u, l, r);
		add(L, R, v, u << 1, l, mid), add(L, R, v, u << 1 | 1, mid + 1, r);
		pushup(u);
	}
	void tomin(int L, int R, const fibint&v, int u = 1, int l = 1, int r = n) {
		if (R < l || r < L || t[u].mx <= v) return;
		if (L <= l && r <= R && t[u].mx2 < v) return push_min(u, v);	// BUG: 
		int mid = (l + r) >> 1;
		pushdown(u, l, r);
		tomin(L, R, v, u << 1, l, mid), tomin(L, R, v, u << 1 | 1, mid + 1, r);
		pushup(u);
	}
	void tomax(int L, int R, const fibint&v, int u = 1, int l = 1, int r = n) {
		if (R < l || r < L || t[u].mn >= v) return;
		if (L <= l && r <= R && t[u].mn2 > v) return push_max(u, v);
		int mid = (l + r) >> 1;
		pushdown(u, l, r);
		tomax(L, R, v, u << 1, l, mid), tomax(L, R, v, u << 1 | 1, mid + 1, r);
		pushup(u);
	}
	mat qsum(int L, int R, int u = 1, int l = 1, int r = n) {
		if (R < l || r < L) return (mat){{{0,0},{0,0}}};
		if (L <= l && r <= R) return t[u].sum;
		int mid = (l + r) >> 1;
		pushdown(u, l, r);
		return qsum(L, R, u << 1, l, mid) + qsum(L, R, u << 1 | 1, mid + 1, r);
	}
}t[2];
mat ans;
void sol(int k1,int k2,int k3,int k4,int k5){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		/*if(k2==k3){
			mat cur=get_mat(t[0].t[k1].mn.x);
			assert(t[0].t[k1].mn.mt.a[0][0]==cur.a[0][0]);
			assert(t[0].t[k1].mn.mt.a[0][1]==cur.a[0][1]);
			assert(t[0].t[k1].mn.mt.a[1][0]==cur.a[1][0]);
			assert(t[0].t[k1].mn.mt.a[1][1]==cur.a[1][1]);
			ans+=t[0].t[k1].sum*t[1].t[k1].sum;
			return;
		}*/
		if(t[0].t[k1].mn==t[0].t[k1].mx){
			ans+=t[0].t[k1].mn.mt*t[1].t[k1].sum;
			return;
		}else if(t[1].t[k1].mn==t[1].t[k1].mx){
			ans+=t[1].t[k1].mn.mt*t[0].t[k1].sum;
			return;
		}
	}
	t[0].pushdown(k1,k2,k3),t[1].pushdown(k1,k2,k3);
	int mid=(k2+k3)>>1;
	sol(k1*2,k2,mid,k4,k5),sol(k1*2+1,mid+1,k3,k4,k5);
	//t[0].pushup(k1),t[1].pushup(k1);
	/*auto w1=t[0].t[k1],w2=t[1].t[k1];
	assert(w1.mn==t[0].t[k1].mn);
	assert(w1.mx==t[0].t[k1].mx);
	assert(w2.mn==t[1].t[k1].mn);
	assert(w2.mx==t[1].t[k1].mx);*/
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(Q);
	rep(i,1,n)rd(a[0][i]);
	rep(i,1,n)rd(a[1][i]);
	rep(i,0,1){
		//D("bud %d\n",i);
		t[i].build(a[i]);
	}
	rep(_,1,Q){
		//D("_=%d\n",_);
		int opt;
		rd(opt);
		if(opt==1){
			int k,l,r,x;
			rd(k),rd(l),rd(r),rd(x);
			--k;
			t[k].tomin(l,r,(fibint){x,get_mat(x)});
		}else if(opt==2){
			int k,l,r,x;
			rd(k),rd(l),rd(r),rd(x);
			--k;
			t[k].tomax(l,r,(fibint){x,get_mat(x)});
		}else if(opt==3){
			int k,l,r,x;
			rd(k),rd(l),rd(r),rd(x);
			--k;
			t[k].add(l,r,(fibint){x,get_mat(x)});
		}else{
			int l,r;
			rd(l),rd(r);
			ans=(mat){{{0,0},{0,0}}};
			sol(1,1,n,l,r);
			/*ans=(mat){{{0,0},{0,0}}};
			rep(i,l,r){
				mat A=t[0].qsum(i,i);
				mat B=t[1].qsum(i,i);
				ans+=A*B;
			}*/
			printf("%d\n",ans.a[0][1]);
		}
	}
	return 0;
}