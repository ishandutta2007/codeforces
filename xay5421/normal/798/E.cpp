#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=500005,M=N*20;
int n,a[N],que[M],deg[M];
int out[N*4],ind;
int pp,lnk[M],to[M*3],nxt[M*3];
void ae(int k1,int k2){
	to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp,++deg[k2];
}
void upd(int k1){
	/*if(!in[k1*2]||!in[k1*2+1]){
		in[k1]=in[k1*2]+in[k1*2+1];
	}else{
		in[k1]=++ind;
		e[in[k1]].pb(in[k1*2]);
		e[in[k1]].pb(in[k1*2+1]);
	}*/
	if(!out[k1*2]||!out[k1*2+1]){
		out[k1]=out[k1*2]+out[k1*2+1];
	}else{
		out[k1]=++ind;
		ae(out[k1*2],out[k1]);
		ae(out[k1*2+1],out[k1]);
		//e[out[k1*2]].pb(out[k1]),++deg[out[k1]];
		//e[out[k1*2+1]].pb(out[k1]),++deg[out[k1]];
	}
}
void bud(int k1,int k2,int k3){
	if(k2==k3){
		out[k1]=k2;
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	upd(k1);
}
void del(int k1,int k2,int k3,int k4){
	if(k2==k3){
		out[k1]=0;
		return;
	}
	int mid=(k2+k3)>>1;
	if(k4<=mid)del(k1*2,k2,mid,k4);
	else del(k1*2+1,mid+1,k3,k4);
	upd(k1);
}
void add2(int k1,int k2,int k3,int k4,int k5,int k6){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		if(out[k1]){
			ae(out[k1],k6);
			//e[out[k1]].pb(k6),++deg[k6];
		}
		return;
	}
	int mid=(k2+k3)>>1;
	add2(k1*2,k2,mid,k4,k5,k6),add2(k1*2+1,mid+1,k3,k4,k5,k6);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n);
	rep(i,1,n)rd(a[i]);
	ind=n;
	bud(1,1,n);
	rep(i,1,n){
		if(a[i]==-1){
			if(1<=i-1)add2(1,1,n,1,i-1,i);
			if(i+1<=n)add2(1,1,n,i+1,n,i);
		}else{
			--a[i];
			if(a[i]<i){
				if(1<=a[i])add2(1,1,n,1,a[i],i);
			}else{
				if(1<=i-1)add2(1,1,n,1,i-1,i);
				if(i+1<=a[i])add2(1,1,n,i+1,a[i],i);
			}
			++a[i];
			//e[i].pb(a[i]),++deg[a[i]];
			ae(i,a[i]);
			del(1,1,n,a[i]);
		}
	}
	int he=0,ta=0;
	rep(i,1,ind){
		if(!deg[i]){
			que[++ta]=i;
		}
	}
	vector<int>ans(n+1);
	int ind=0;
	while(he!=ta){
		int k1=que[++he];
		//D("k1=%d\n",k1);
		if(k1<=n){
			ans[k1]=++ind;
		}
		for(int i=lnk[k1];i;i=nxt[i])if(!--deg[to[i]]){
			que[++ta]=to[i];
		}
	}
	rep(i,1,n)printf("%d ",ans[i]);
	return 0;
}