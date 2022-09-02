#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
using LL=long long;
using ULL=unsigned long long;
const int N=300005,INF=0X3F3F3F3F;
int n,p[N];
struct segtree{
	int tr[N*4],tg[N*4];
	void upd(int k1){
		tr[k1]=max(tr[k1*2],tr[k1*2+1]);
	}
	void pst(int k1,int k2){
		tg[k1]+=k2,tr[k1]+=k2;
	}
	void psd(int k1){
		if(tg[k1]){
			pst(k1*2,tg[k1]);
			pst(k1*2+1,tg[k1]);
			tg[k1]=0;
		}
	}
	void add(int k1,int k2,int k3,int k4,int k5,int k6){
		if(k2>k5||k3<k4)return;
		if(k4<=k2&&k3<=k5){
			pst(k1,k6);
			return;
		}
		psd(k1);
		int mid=(k2+k3)>>1;
		add(k1*2,k2,mid,k4,k5,k6),add(k1*2+1,mid+1,k3,k4,k5,k6);
		upd(k1);
	}
}sgt;
int main(){
	rd(n);
	printf("1 ");
	rep(i,1,n-1){
		int x;
		rd(x);
		sgt.add(1,1,n,x,x,~INF);
		if(x+1<=n)sgt.add(1,1,n,x+1,n,1);
		printf("%d ",sgt.tr[1]+1);
	}
	printf("1\n");
	return 0;
}