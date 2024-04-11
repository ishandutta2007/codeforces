// author: xay5421
// created: Thu Oct 28 20:34:02 2021
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
const int N=100005;
int n,m,a[N];
LL ans[N];
struct node{
	LL x,k;
	int id;
}q[N];
struct BIT{
	int t[N];
	void upd(int k1,int k2){
		for(int i=k1;i<=n;i+=i&-i)t[i]+=k2;
	}
	int qry(int k1){
		int k2=0;
		for(int i=k1;i;i&=i-1)k2+=t[i];
		return k2;
	}
	int kth(int k){
		int now=0;
		per(i,20,0)if(now+(1<<i)<=n&&t[now+(1<<i)]<k){
			now+=1<<i;
			k-=t[now];
		}
		return now+1;
	}
}t;
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	int oldm=m;
	rep(i,1,n)scanf("%d",&a[i]);
	int cnt_id=0;
	rep(i,1,m){
		scanf("%lld%lld",&q[i].x,&q[i].k),q[i].id=++cnt_id;
		if(q[i].x<a[1]){
			ans[cnt_id]=q[i].x;
			--i,--m;
		}
	}
	sort(q+1,q+1+m,[&](auto lhs,auto rhs){return lhs.x<rhs.x;});
	rep(i,1,n)t.upd(i,1);
	LL cur=1e15;
	//LL cur=10;
	int pos=m;
	LL times=0;
	for(int i=n;i>=1;){
		D("cur=%lld\n",cur);
		LL tt=(cur-a[i]+i-1)/i,nex=cur-tt*i;
		while(pos>=1&&q[pos].x>=nex){
			q[pos].k=times+(cur-q[pos].x+i-1)/i-q[pos].k;
			q[pos].x=t.kth(i-(cur-q[pos].x+i-1)%i);
			--pos;
		}
		while(i>=1&&a[i]>=nex){
			int tmp=t.kth(a[i]-nex+1);
			t.upd(tmp,-1);
			--i;
		}
		times+=tt,cur=nex;
	}
	/*rep(i,1,m){
		D("{%lld,%lld,%d}\n",q[i].x,q[i].k,q[i].id);
	}*/
	sort(q+1,q+1+m,[&](auto lhs,auto rhs){return lhs.k>rhs.k;});
	rep(i,1,n)t.upd(i,1);
	cur=1e15;
	//cur=10;
	pos=m;
	times=0;
	for(int i=n;i>=1;){
		LL tt=(cur-a[i]+i-1)/i,nex=cur-tt*i;
		while(pos>=1&&q[pos].k<=times+tt){
			ans[q[pos].id]=cur+t.qry(q[pos].x)-(q[pos].k-times)*i-1;
			--pos;
		}
		while(i>=1&&a[i]>=nex){
			int tmp=t.kth(a[i]-nex+1);
			t.upd(tmp,-1);
			--i;
		}
		times+=tt,cur=nex;
	}
	rep(i,1,oldm)printf("%lld\n",ans[i]);
	return 0;
}