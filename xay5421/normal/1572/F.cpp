// author: xay5421
// created: Tue Sep 21 23:58:08 2021
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
typedef long long LL;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005,INF=0X3F3F3F3F;
int n,Q;
struct seg2{
	LL t[N*4],tg[N*4];
	int length[N*4];
	void pst(int k1,LL k2){
		tg[k1]+=k2;
		t[k1]+=k2*length[k1];
	}
	void psd(int k1){
		if(tg[k1]){
			pst(k1*2,tg[k1]);
			pst(k1*2+1,tg[k1]);
			tg[k1]=0;
		}
	}
	void upd(int k1){
		t[k1]=t[k1*2]+t[k1*2+1];
	}
	void bud(int k1,int k2,int k3){
		length[k1]=k3-k2+1;
		if(k2==k3){
			t[k1]=1;
			return;
		}
		int mid=(k2+k3)>>1;
		bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
		upd(k1);
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
	LL res;
	void ask(int k1,int k2,int k3,int k4,int k5){
		if(k2>k5||k3<k4)return;
		if(k4<=k2&&k3<=k5){
			res+=t[k1];
			return;
		}
		psd(k1);
		int mid=(k2+k3)>>1;
		ask(k1*2,k2,mid,k4,k5),ask(k1*2+1,mid+1,k3,k4,k5);
	}
	LL ask(int l,int r){
		res=0;
		ask(1,1,n,l,r);
		return res;
	}
	void out(int k1,int k2,int k3){
		if(k2==k3){
			D("%lld ",t[k1]);
			return;
		}
		psd(k1);
		int mid=(k2+k3)>>1;
		out(k1*2,k2,mid),out(k1*2+1,mid+1,k3);
	}
	void out(){
		D("T ");
		out(1,1,n),D("\n");
	}
}T;
int mx[N*4],cnt[N*4],mx_[N*4];
void upd(int k1){
	if(mx[k1*2]==mx[k1*2+1]){
		mx[k1]=mx[k1*2];
		cnt[k1]=cnt[k1*2]+cnt[k1*2+1];
		mx_[k1]=max(mx_[k1*2],mx_[k1*2+1]);
	}else if(mx[k1*2]>mx[k1*2+1]){
		mx[k1]=mx[k1*2];
		cnt[k1]=cnt[k1*2];
		mx_[k1]=max(mx_[k1*2],mx[k1*2+1]);
	}else{
		mx[k1]=mx[k1*2+1];
		cnt[k1]=cnt[k1*2+1];
		mx_[k1]=max(mx_[k1*2+1],mx[k1*2]);
	}
}
void bud(int k1,int k2,int k3){
	if(k2==k3){
		mx[k1]=k2,mx_[k1]=~INF;
		cnt[k1]=1;
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	upd(k1);
}
void mdf(int k1,int k2,int k3,int k4,int k5,int k6){
	if(k2>k5||k3<k4||mx[k1]<=k6)return;
	if(k4<=k2&&k3<=k5){
		if(mx_[k1]<k6){
			T.add(1,1,n,k6+1,mx[k1],-cnt[k1]);
			mx[k1]=k6;
			return;
		}
	}
	mx[k1*2]=min(mx[k1*2],mx[k1]);
	mx[k1*2+1]=min(mx[k1*2+1],mx[k1]);
	int mid=(k2+k3)>>1;
	mdf(k1*2,k2,mid,k4,k5,k6),mdf(k1*2+1,mid+1,k3,k4,k5,k6);
	upd(k1);
}
void chg(int k1,int k2,int k3,int k4,int k5){
	if(k2==k3){
		if(k2<mx[k1]){
			T.add(1,1,n,k2+1,mx[k1],-1);
		}
		mx[k1]=k5;
		if(k2<mx[k1]){
			T.add(1,1,n,k2+1,mx[k1],1);
		}
		return;
	}
	mx[k1*2]=min(mx[k1*2],mx[k1]);
	mx[k1*2+1]=min(mx[k1*2+1],mx[k1]);
	int mid=(k2+k3)>>1;
	if(k4<=mid)chg(k1*2,k2,mid,k4,k5);else chg(k1*2+1,mid+1,k3,k4,k5);
	upd(k1);
}
void out(int k1,int k2,int k3){
	if(k2==k3){
		D("%d ",mx[k1]);
		return;
	}
	mx[k1*2]=min(mx[k1*2],mx[k1]);
	mx[k1*2+1]=min(mx[k1*2+1],mx[k1]);
	int mid=(k2+k3)>>1;
	out(k1*2,k2,mid),out(k1*2+1,mid+1,k3);
	upd(k1);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(Q);
	T.bud(1,1,n);
	bud(1,1,n);
	rep(i,1,Q){
		int tp;
		rd(tp);
		if(tp==1){
			int c,g;
			rd(c),rd(g);
			if(1<=c-1)mdf(1,1,n,1,c-1,c-1);
			chg(1,1,n,c,g);
			//T.out();
			//D("mx "),out(1,1,n),D("\n");
		}else{
			int l,r;
			rd(l),rd(r);
			/*static int ind=0;
			D("%d:\n\t",++ind);
			if(ind==22){
				D("!!\n");
			}*/
			printf("%lld\n",T.ask(l,r));
		}
	}
	return 0;
}