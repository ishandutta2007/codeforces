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
const int N=150005;
int n,len,h,a[N],b[N];
int t[N*4],tg[N*4];
void upd(int k1){
	t[k1]=min(t[k1*2],t[k1*2+1]);
}
void pst(int k1,int k2){
	t[k1]+=k2,tg[k1]+=k2;
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
int main(){
	scanf("%d%d%d",&n,&len,&h);
	rep(i,1,len)scanf("%d",&b[i]);
	rep(i,1,n)scanf("%d",&a[i]);
	sort(b+1,b+1+len);
	rep(i,1,n)a[i]=lower_bound(b+1,b+1+len,h-a[i])-b;
	rep(i,1,len){
		add(1,1,len+1,i,i,len-i+1);
	}
	rep(i,1,len-1){
		add(1,1,len+1,1,a[i],-1);
	}
	int ans=0;
	rep(i,len,n){
		add(1,1,len+1,1,a[i],-1);
		if(t[1]>=0)++ans;
		add(1,1,len+1,1,a[i-len+1],1);
	}
	printf("%d\n",ans);
	return 0;
}