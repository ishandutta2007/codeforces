#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=200005;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
int n,Q,a[N],mn[N*4],mx[N*4],tg[N*4],len[N*4];
LL sum[N*4];
void pst(int k1,int k2){
	tg[k1]=mn[k1]=mx[k1]=k2,sum[k1]=1LL*len[k1]*k2;
}
void psd(int k1){
	if(tg[k1]){
		pst(k1*2,tg[k1]);
		pst(k1*2+1,tg[k1]);
		tg[k1]=0;
	}
}
void upd(int k1){
	mn[k1]=min(mn[k1*2],mn[k1*2+1]);
	mx[k1]=max(mx[k1*2],mx[k1*2+1]);
	sum[k1]=sum[k1*2]+sum[k1*2+1];
}
void bud(int k1,int k2,int k3){
	len[k1]=k3-k2+1;
	if(k2==k3){
		pst(k1,a[k2]);
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	upd(k1);
}
void umax(int k1,int k2,int k3,int k4,int k5){
	if(k2>k4||mn[k1]>k5)return;
	if(k3<=k4&&mx[k1]<=k5){pst(k1,k5);return;}
	psd(k1);
	int mid=(k2+k3)>>1;
	umax(k1*2,k2,mid,k4,k5),umax(k1*2+1,mid+1,k3,k4,k5);
	upd(k1);
}
int qry(int k1,int k2,int k3,int k4,int&k5){
	if(k3<k4||mn[k1]>k5)return 0;
	if(k2>=k4&&sum[k1]<=k5){
		k5-=sum[k1];
		return len[k1];
	}
	if(k2==k3)return 0;
	psd(k1);
	int mid=(k2+k3)>>1;
	int tem=qry(k1*2,k2,mid,k4,k5);
	return tem+qry(k1*2+1,mid+1,k3,k4,k5);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(Q);
	rep(i,1,n)rd(a[i]);
	bud(1,1,n);
	rep(_,1,Q){
		int t,x,y;
		rd(t),rd(x),rd(y);
		if(t==1){
			umax(1,1,n,x,y);
		}else{
			pt(qry(1,1,n,x,y),'\n');
		}
	}
	return 0;
}