#include<bits/stdc++.h>
#define D(...) fprintf(stderr,__VA_ARGS__)
#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define fi first
#define se second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;typedef vector<int>VI;typedef vector<PII>VII;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=300005,INF=0X3F3F3F3F;
int n,q,a[N],t[N],ri[N],ans[N];
vector<int>G[N];
void upd(int k1,int k2){
	for(int i=k1;i<=n;i+=i&-i)t[i]+=k2;
}
int qry(int k1){
	int k2=0;
	for(int i=k1;i;i&=i-1)k2+=t[i];
	return k2;
}
int mn[N*4],tg[N*4];
void pst(int k1,int k2){
	mn[k1]+=k2,tg[k1]+=k2;
}
void psd(int k1){
	if(tg[k1]){
		pst(k1*2,tg[k1]);
		pst(k1*2+1,tg[k1]);
		tg[k1]=0;
	}
}
void mdf(int k1,int k2,int k3,int k4,int k5,int k6){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		pst(k1,k6);
		return;
	}
	psd(k1);
	int mid=(k2+k3)>>1;
	mdf(k1*2,k2,mid,k4,k5,k6),mdf(k1*2+1,mid+1,k3,k4,k5,k6);
	mn[k1]=min(mn[k1*2],mn[k1*2+1]);
}
int ask(int k1){
	int k2=1,k3=n;
	while(k2!=k3){
		psd(k1);
		int mid=(k2+k3)>>1;
		if(mn[k1*2]<=0)k1=k1*2,k3=mid;
		else k1=k1*2+1,k2=mid+1;
	}
	return k2;
}
signed main(){
	rep(i,0,N*4-1)mn[i]=INF;
	rd(n),rd(q);
	rep(i,1,n)rd(a[i]),a[i]=(a[i]>i?INF:i-a[i]);
	rep(i,1,q){
		int x,y;rd(x),rd(y);
		ri[i]=n-y;
		G[x+1].PB(i);
	}
	for(int i=n;i>=1;--i){
		mdf(1,1,n,i,i,-INF+a[i]);
		while(mn[1]<=0){
			int num=ask(1);
			upd(num,1);
			if(num<n)mdf(1,1,n,num+1,n,-1);
			mdf(1,1,n,num,num,INF);
		}
		for(auto id:G[i]){
			ans[id]=qry(ri[id]);
		}
	}
	rep(i,1,q)pt(ans[i],'\n');
	return 0;
}