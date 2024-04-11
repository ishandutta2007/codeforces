// author: xay5421
// created: Fri Jul 16 12:37:45 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
inline char getc(){static char buf[1<<20],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getc()))f^=!(c^45);x=(c&15);while(isdigit(c=getc()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005;
int n,m,Q,dp[N];
long long a[N];
namespace xay1{
	void sol(){
		while(Q--){
			int t;
			rd(t);
			if(t==1){
				int l,r,d;
				rd(l),rd(r),rd(d);
				if(d&1)rep(i,l,r)a[i]^=1;
			}else{
				int l,r;
				rd(l),rd(r);
				int s=0;
				per(i,r,l){
					dp[i]=a[i]&1;
					if(s)dp[i]=0;
					s=(s<<1|dp[i])&((1<<m)-1);
				}
				if(dp[l])puts("2");else puts("1");
			}
		}
	}
}
namespace xay2{
	struct node{
		int w[22],len;
	}t[N*4][2];
	int tg[N*4];
	void pst(int k1){
		tg[k1]^=1,swap(t[k1][0],t[k1][1]);
	}
	void psd(int k1){
		if(tg[k1]){
			pst(k1*2);
			pst(k1*2+1);
			tg[k1]=0;
		}
	}
	node mer(const node&k1,const node&k2){
		node k3;
		k3.len=k1.len+k2.len;
		rep(i,1,m+1){
			if(k2.w[i]==-1){
				if(k1.w[min(m+1,i+k2.len)]==-1){
					k3.w[i]=-1;
				}else k3.w[i]=k1.w[min(m+1,i+k2.len)];
			}else{
				if(k1.w[k2.w[i]]==-1){
					k3.w[i]=min(m+1,k1.len+k2.w[i]);
				}else k3.w[i]=k1.w[k2.w[i]];
			}
		}
		return k3;
	}
	void upd(int k1){
		t[k1][0]=mer(t[k1*2][0],t[k1*2+1][0]);
		t[k1][1]=mer(t[k1*2][1],t[k1*2+1][1]);
	}
	void bud(int k1,int k2,int k3){
		if(k2==k3){
			t[k1][0].len=t[k1][1].len=1;
			if(a[k2]&1){
				rep(i,1,m)t[k1][0].w[i]=-1;
				t[k1][0].w[m+1]=1;
				rep(i,1,m+1)t[k1][1].w[i]=-1;
			}else{
				rep(i,1,m)t[k1][1].w[i]=-1;
				t[k1][1].w[m+1]=1;
				rep(i,1,m+1)t[k1][0].w[i]=-1;
			}
			return;
		}
		psd(k1);
		int mid=(k2+k3)>>1;
		bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
		upd(k1);
	}
	void mdf(int k1,int k2,int k3,int k4,int k5){
		if(k2>k5||k3<k4)return;
		if(k4<=k2&&k3<=k5){
			pst(k1);
			return;
		}
		psd(k1);
		int mid=(k2+k3)>>1;
		mdf(k1*2,k2,mid,k4,k5),mdf(k1*2+1,mid+1,k3,k4,k5);
		upd(k1);
	}
	int res;
	void ask(int k1,int k2,int k3,int k4,int k5){
		if(k2>k5||k3<k4)return;
		if(k4<=k2&&k3<=k5){
			if(t[k1][0].w[res]==-1){
				res=min(m+1,res+t[k1][0].len);
			}else{
				res=t[k1][0].w[res];
			}
			return;
		}
		psd(k1);
		int mid=(k2+k3)>>1;
		ask(k1*2+1,mid+1,k3,k4,k5);
		ask(k1*2,k2,mid,k4,k5);
	}
	void sol(){
		bud(1,1,n);
		while(Q--){
			int t;
			rd(t);
			if(t==1){
				int l,r;
				long long d;
				rd(l),rd(r),rd(d);
				if(d&1){
					mdf(1,1,n,l,r);
				}
			}else{
				int l,r;
				rd(l),rd(r);
				res=m+1;
				ask(1,1,n,l,r);
				if(res==1)puts("2");else puts("1");
			}
		}
	}
}
int main(){
	rd(n),rd(m),rd(Q);
	rep(i,1,n)rd(a[i]),a[i]&=1;
	if(n<=5000&&m<=5000){
		xay1::sol();
	}else{
		xay2::sol();
	}
	return 0;
}