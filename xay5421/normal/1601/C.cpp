// author: xay5421
// created: Mon Oct 25 15:02:30 2021
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
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=1000005;
int T,n,m,a[N],b[N],id[N];
int w1[N*4],w2[N*4],w3[N*4]; // w2:cnt(-1) w3:cnt(1)
LL ans;
void upd(int k1){
	w2[k1]=w2[k1*2]+w2[k1*2+1];
	w3[k1]=w3[k1*2]+w3[k1*2+1];
	w1[k1]=min(w1[k1*2]+w2[k1*2+1],w1[k1*2+1]+w3[k1*2]);
}
void bud(int k1,int k2,int k3){
	if(k2==k3){
		w1[k1]=0;
		w2[k1]=0;
		w3[k1]=1;
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	upd(k1);
}
void mdf(int k1,int k2,int k3,int k4,int k5){
	if(k2==k3){
		if(k5==-1){
			w1[k1]=0;
			w2[k1]=1;
			w3[k1]=0;
		}else if(k5==0){
			w1[k1]=0;
			w2[k1]=0;
			w3[k1]=0;
		}
		return;
	}
	int mid=(k2+k3)>>1;
	if(k4<=mid)mdf(k1*2,k2,mid,k4,k5);else mdf(k1*2+1,mid+1,k3,k4,k5);
	upd(k1);
}
int id_[N];
void mer(int l,int r){
	if(l>=r)return;
	int mid=(l+r)>>1;
	mer(l,mid),mer(mid+1,r);
	int i=l,j=mid+1;
	rep(k,l,r){
		if(i<=mid&&(j>r||a[id[i]]<=a[id[j]]))ans+=j-mid-1,id_[k]=id[i++];else id_[k]=id[j++];
	}
	rep(k,l,r)id[k]=id_[k];
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		ans=0;
		rd(n),rd(m);
		rep(i,1,n)rd(a[i]),id[i]=i;
		rep(i,1,m)rd(b[i]);
		mer(1,n);
		sort(b+1,b+1+m);
		int pos=1;
		bud(1,1,n);
		rep(i,1,m){
			if(i>1&&b[i]==b[i-1]){
				ans+=w1[1];
				continue;
			}
			while(pos<=n&&a[id[pos]]<b[i])mdf(1,1,n,id[pos],-1),++pos;
			int oldpos=pos;
			while(pos<=n&&a[id[pos]]==b[i])mdf(1,1,n,id[pos],0),++pos;
			ans+=w1[1];
			pos=oldpos;
		}
		printf("%lld\n",ans);
	}
	return 0;
}