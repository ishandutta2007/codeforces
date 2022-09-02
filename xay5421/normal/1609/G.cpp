#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#pragma GCC optimize(2,3,"Ofast")
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=100005;
int n,m,Q,pos[N];
LL a[N],b[N];
LL mx[N*4],w1[N*4],w2[N*4],sum1[N*4],sum2[N*4],tg[N*4];
void pst(int k1,LL k2){
	tg[k1]+=k2;
	//mn[k1]+=k2;
	mx[k1]+=k2;
	sum1[k1]+=k2*w1[k1];
	sum2[k1]+=k2*w2[k1];
}
void psd(int k1){
	if(tg[k1]){
		pst(k1*2,tg[k1]);
		pst(k1*2+1,tg[k1]);
		tg[k1]=0;
	}
}
void upd(int k1){
	//mn[k1]=min(mn[k1*2],mn[k1*2+1]);
	mx[k1]=max(mx[k1*2],mx[k1*2+1]);
	sum1[k1]=sum1[k1*2]+sum1[k1*2+1];
	sum2[k1]=sum2[k1*2]+sum2[k1*2+1];
}
void bud(int k1,int k2,int k3){
	w1[k1]=k3-k2+1;
	w2[k1]=1LL*(k2+k3)*(k3-k2+1)/2;
	if(k2==k3){
		//mn[k1]=b[k2];
		mx[k1]=b[k2];
		sum1[k1]=b[k2];
		sum2[k1]=1LL*k2*b[k2];
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	upd(k1);
}
void add(int k1,int k2,int k3,int k4,int k5,LL k6){
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
LL res1,res2;
void ask(int k1,int k2,int k3,int k4,int k5){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		res1+=sum1[k1],res2+=sum2[k1];
		return;
	}
	psd(k1);
	int mid=(k2+k3)>>1;
	ask(k1*2,k2,mid,k4,k5),ask(k1*2+1,mid+1,k3,k4,k5);
}
void ask(int l,int r){
	res1=0,res2=0;
	ask(1,2,m,l,r);
}
int res;
void find_first(int k1,int k2,int k3,int k4){
	if(k2==k3){
		if(mx[k1]>=k4){
			res=k2;
		}
		return;
	}
	psd(k1);
	int mid=(k2+k3)>>1;
	if(mx[k1*2]>=k4){
		find_first(k1*2,k2,mid,k4);
	}else{
		find_first(k1*2+1,mid+1,k3,k4);
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(m),rd(Q);
	rep(i,1,n)rd(a[i]);
	per(i,n,1)a[i]=a[i]-a[i-1];
	rep(i,1,m)rd(b[i]);
	per(i,m,1)b[i]=b[i]-b[i-1];
	bud(1,2,m);
	LL base=a[1]+b[1];
	rep(_,1,Q){
		int opt,K,d;
		rd(opt),rd(K),rd(d);
		if(opt==1){
			if(K==n){
				base+=d;
				--K;
			}
			rep(i,n-K+1,n){
				a[i]+=d;
			}
		}else{
			if(K==m){
				base+=d;
				--K;
			}
			add(1,2,m,m-K+1,m,d);
		}
		rep(i,2,n){
			res=-1;
			if(mx[1]>=a[i]){
				find_first(1,2,m,a[i]);
			}
			if(res==-1){
				pos[i]=m+1;
			}else{
				pos[i]=res;
			}
		}
		LL ans=base*(n+m-1);
		int lst=2;
		int rem=n+m-2;
		rep(i,2,n){
			if(lst<pos[i]){
				// [lst,pos[i]-1]
				ask(lst,pos[i]-1);
				ans+=1LL*res1*(rem+lst)-res2;
				rem-=pos[i]-lst;
				lst=pos[i];
			}
			ans+=1LL*rem*a[i];
			rem-=1;
		}
		{
			int cur=m+1;
			if(lst<cur){
				ask(lst,cur-1);
				ans+=1LL*res1*(rem+lst)-res2;
				rem-=cur-lst;
				lst=cur;
			}
		}
		pt(ans,'\n');
	}
	return 0;
}