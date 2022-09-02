#include<bits/stdc++.h>
#define D(...) fprintf(stderr,__VA_ARGS__)
#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define fi first
#define se second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;typedef vector<int>VI;typedef vector<PII>VII;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=100005,M=1000005;
int n,m,t[M];
void upd(int k1,int k2){
	++k1;
	for(int i=k1;i<M;i+=i&-i)t[i]+=k2;
}
int qry(int k1){
	++k1;
	int res=0;
	for(int i=k1;i;i&=i-1)res+=t[i];
	return res;
}
int qry(int l,int r){
	return qry(r)-qry(l-1);
}
struct data{
	int x,l,r,id;
	void init(int i){
		rd(x),rd(l),rd(r),id=i;
	}
}A[N],B[N],C[N];
signed main(){
	rd(n),rd(m);
	rep(i,1,n){
		A[i].init(i);
	}
	rep(i,1,m){
		B[i].init(i);
		C[i]=B[i];
	}
	++n,A[n]=(data){1000000,0,1000000,n};
	++n,A[n]=(data){0,0,1000000,n};
	++m,B[m]=(data){1000000,0,1000000,m};
	++m,B[m]=(data){0,0,1000000,m};
	m-=2;
	++m,C[m]=(data){1000000,0,1000000,m};
	++m,C[m]=(data){0,0,1000000,m};
	sort(A+1,A+1+n,[&](data k1,data k2){return k1.x<k2.x;});
	sort(B+1,B+1+m,[&](data k1,data k2){return k1.l<k2.l;});
	sort(C+1,C+1+m,[&](data k1,data k2){return k1.r<k2.r;});
	int ib=1,ic=1;
	int E=0,V=0;
	for(int i=1;i<=n;++i){
		while(ib<=m&&B[ib].l<=A[i].x)upd(B[ib].x,1),++ib;
		while(ic<=m&&C[ic].r<A[i].x)upd(C[ic].x,-1),++ic;
		int x=qry(A[i].l,A[i].r);
		V+=x;
		E+=x-1;
	}
	rep(i,1,n)C[i]=A[i];
	sort(B+1,B+1+m,[&](data k1,data k2){return k1.x<k2.x;});
	sort(A+1,A+1+n,[&](data k1,data k2){return k1.l<k2.l;});
	sort(C+1,C+1+n,[&](data k1,data k2){return k1.r<k2.r;});
	ib=1,ic=1;
	memset(t,0,sizeof(t));
	for(int i=1;i<=m;++i){
		while(ib<=n&&A[ib].l<=B[i].x)upd(A[ib].x,1),++ib;
		while(ic<=n&&C[ic].r<B[i].x)upd(C[ic].x,-1),++ic;
		int x=qry(B[i].l,B[i].r);
		E+=x-1;
	}
	pt(E-V+1,'\n');
	return 0;
}