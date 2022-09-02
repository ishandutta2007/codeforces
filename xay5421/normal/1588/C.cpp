// author: xay5421
// created: Sun Nov 14 15:01:07 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=300005;
const LL INFLL=0X3F3F3F3F3F3F3F3FLL;
int T,n,a[N],id[N],pos[N];
LL sum[N],ans;
LL t[N*4][2],tg[N*4];
void upd(int k1){
	t[k1][0]=min(t[k1*2][0],t[k1*2+1][0]);
	t[k1][1]=min(t[k1*2][1],t[k1*2+1][1]);
}
void pst(int k1,LL k2){
	tg[k1]+=k2,t[k1][1]+=k2,t[k1][0]-=k2;
}
void psd(int k1){
	if(tg[k1]){
		pst(k1*2,tg[k1]);
		pst(k1*2+1,tg[k1]);
		tg[k1]=0;
	}
}
void bud(int k1,int k2,int k3){
	tg[k1]=0;
	if(k2==k3){
		t[k1][k2&1]=0,t[k1][~k2&1]=INFLL;
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	upd(k1);
}
void add(int k1,int k2,int k3,int k4,int k5,int k6){ // 
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
int res;
void ask(int k1,int k2,int k3){
	if(t[k1][0]>=0&&t[k1][1]>=0)return;
	if(k2==k3){
		res=k2;
		return;
	}
	psd(k1);
	int mid=(k2+k3)>>1;
	ask(k1*2,k2,mid);
	if(res==n+1)ask(k1*2+1,mid+1,k3);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)rd(a[i]),sum[i]=sum[i-1]+(i&1?a[i]:-a[i]);
		rep(i,0,n)id[i]=i;
		sort(id,id+1+n,[&](int x,int y){return sum[x]!=sum[y]?sum[x]<sum[y]:x<y;});
		rep(i,0,n)pos[id[i]]=i;
		auto calc=[&](int l,int r){ // [l,r]
			int i=pos[l-1];
			per(j,20,0)if(i+(1<<j)<=n&&sum[id[i+(1<<j)]]==sum[l-1]&&id[i+(1<<j)]<=r){
				i+=1<<j;
			}
			return i-pos[l-1];
		};
		bud(1,1,n);
		ans=0;
		per(i,n,1){
			add(1,1,n,i,n,i&1?a[i]:-a[i]);
			res=n+1;
			ask(1,1,n);
			ans+=calc(i,res-1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}