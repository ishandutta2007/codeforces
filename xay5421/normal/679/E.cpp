#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=100005;
const LL INFLL=0X3F3F3F3F3F3F3F3FLL;
int n,Q;
int hig[N],pos[N*4];
LL pw[11],tg[N*4],a[N],mn[N*4],clr[N*4];
void upd(int k1){
	mn[k1]=min(mn[k1*2],mn[k1*2+1]);
}
void upd_leaf(int k1){
	int k2=pos[k1];
	while(hig[k2]&&pw[hig[k2]-1]>=a[k2])--hig[k2];
	while(pw[hig[k2]]<a[k2])++hig[k2];
	mn[k1]=pw[hig[k2]]-a[k2];
}
void bud(int k1,int k2,int k3){
	if(k2==k3){
		pos[k1]=k2;
		upd_leaf(k1);
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	upd(k1);
}
void pst(int k1,LL k2){
	if(pos[k1]){
		a[pos[k1]]+=k2;
		upd_leaf(k1);
	}else{
		mn[k1]-=k2;
		tg[k1]+=k2;
	}
}
void pst_clr(int k1,LL k2){
	if(pos[k1]){
		a[pos[k1]]=k2;
		upd_leaf(k1);
	}else{
		mn[k1]=*lower_bound(pw,pw+11,k2)-k2;
		tg[k1]=0;
		clr[k1]=k2;
	}
}
void psd(int k1){
	if(clr[k1]){
		pst_clr(k1*2,clr[k1]);
		pst_clr(k1*2+1,clr[k1]);
		clr[k1]=0;
	}
	if(tg[k1]){
		pst(k1*2,tg[k1]);
		pst(k1*2+1,tg[k1]);
		tg[k1]=0;
	}
}
LL getv(int k1,int k2,int k3,int k4){
	//D("getv %d %d %d %d\n",k1,k2,k3,k4);
	if(k2==k3){
		//D("! %lld\n",a[k2]);
		return a[k2];
	}
	psd(k1);
	int mid=(k2+k3)>>1;
	return k4<=mid?getv(k1*2,k2,mid,k4):getv(k1*2+1,mid+1,k3,k4);
}
void Clear(int k1,int k2,int k3,int k4,int k5,LL k6){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		pst_clr(k1,k6);
		return;
	}
	psd(k1);
	int mid=(k2+k3)>>1;
	Clear(k1*2,k2,mid,k4,k5,k6);
	Clear(k1*2+1,mid+1,k3,k4,k5,k6);
	upd(k1);
}
bool flg;
void doo(int k1,int k2,int k3){
	if(k2==k3){
		upd_leaf(k1);
		assert(mn[k1]>=0);
		return;
	}
	if(clr[k1]){
		clr[k1]+=tg[k1];
		pst_clr(k1,clr[k1]);
		return;
	}
	if(mn[k1]>=0)return;
	psd(k1);
	int mid=(k2+k3)>>1;
	doo(k1*2,k2,mid);
	doo(k1*2+1,mid+1,k3);
	upd(k1);
}
void mdf(int k1,int k2,int k3,int k4,int k5,LL k6){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		D("mdf %d %d %d %d %d %d\n",k1,k2,k3,k4,k5,k6);
		pst(k1,k6);
		if(mn[k1]<0){
			doo(k1,k2,k3);
		}
		if(mn[k1]==0)flg=1;
		return;
	}
	psd(k1);
	int mid=(k2+k3)>>1;
	mdf(k1*2,k2,mid,k4,k5,k6);
	mdf(k1*2+1,mid+1,k3,k4,k5,k6);
	upd(k1);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	pw[0]=1;
	rep(i,1,10)pw[i]=42LL*pw[i-1];
	rd(n),rd(Q);
	rep(i,1,n)rd(a[i]);
	bud(1,1,n);
	rep(_,1,Q){
		int o;
		rd(o);
		if(o==1){
			int i;
			rd(i);
			pt(getv(1,1,n,i),'\n');
		}else if(o==2){
			int a,b,x;
			rd(a),rd(b),rd(x);
			Clear(1,1,n,a,b,x);
		}else if(o==3){
			int a,b,x;
			rd(a),rd(b),rd(x);
			D(">>> %d %d %d %d\n",3,a,b,x);
			do{
				flg=0;
				mdf(1,1,n,a,b,x);
			}while(flg);
		}
		/*D("{");
		rep(i,1,n)D("%lld%c",a[i],i==n?'}':',');
		D("\n");*/
	}
	return 0;
}