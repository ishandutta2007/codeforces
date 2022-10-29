#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const int P = 998244353;
const int N = 1e5+5;
 
struct mat{
	int a[2][2];
	mat operator*(mat r){
		mat b;
		rep(i,0,1)rep(j,0,1) b.a[i][j] = (1ll*a[i][0]*r.a[0][j] + 1ll*a[i][1]*r.a[1][j])%P;
		return b;
	}
};
 
struct dat{
	int i, d, v, tp;
}a[N<<1];
mat tr[524290];
 
int n, x, v, p[N];
 
int pw(LL x, int n){
	LL res = 1;
	for(;n;n>>=1,x=x*x%P) if(n&1) res=res*x%P;
	return res;
}
int inv(int x){return pw(x,P-2);}
inline int sub(int x, int y){return x>=y? x-y: x+P-y;}
 
void build(int i=1, int l=1, int r=n-1){
	if(l==r){
		tr[i].a[0][0] = tr[i].a[1][0] = sub(1,p[l+1]);
		tr[i].a[0][1] = tr[i].a[1][1] = p[l+1];
		return;
	}
	int mid = l+r>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	tr[i] = tr[i<<1] * tr[i<<1|1];
}
 
void upd(int id, int tp, int i=1, int l=1, int r=n-1){
	if(l==r){
		tr[i].a[tp>>1][tp&1] = 0;
		return;
	}
	int mid = l+r>>1;
	if(id<=mid) upd(id,tp,i<<1,l,mid); else upd(id,tp,i<<1|1,mid+1,r);
	tr[i] = tr[i<<1] * tr[i<<1|1];
}
 
int main(){
	scanf("%d",&n);
	if(n==1){cout<<0;return 0;}
	int m = 0, inv100 = inv(100), lx, lv;
	rep(i,1,n){
		scanf("%d%d%d",&x,&v,&p[i]);
		p[i] = 1ll * p[i] * inv100 % P;
		if(i>1){
			a[++m] = {i-1, x-lx, v+lv, 2};
			if(lv<v) a[++m] = {i-1, x-lx, v-lv, 0};
			if(lv>v) a[++m] = {i-1, x-lx, lv-v, 3};
		}
		lx = x, lv = v;
	}
	build();
	sort(a+1,a+m+1,[](dat x,dat y){return 1ll*x.d*y.v<1ll*x.v*y.d;});
	int oldp = 1, newp, ans = 0;
	rep(i,1,m){
		upd(a[i].i,a[i].tp);
		newp = ( 1ll*sub(1,p[1])*(tr[1].a[0][0]+tr[1].a[0][1]) + 1ll*p[1]*(tr[1].a[1][0]+tr[1].a[1][1]) )%P;
		ans = (ans + 1ll * sub(oldp,newp) * a[i].d % P * inv(a[i].v) % P) % P;
		oldp = newp;
	}
	printf("%d",ans);
	return 0;
}