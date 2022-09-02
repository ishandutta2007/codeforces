// author: xay5421
// created: Wed Oct 27 15:18:16 2021
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
const int N=200005,K=20;
int n,a[N*2],pre[N*2],nex[N*2],f[N][K],lg[N],val[N];
int max_(int k1,int k2){return a[k1]<a[k2]?k1:k2;} // min
int qmax(int l,int r){
	int x=lg[r-l+1];
	return max_(f[l][x],f[r-(1<<x)+1][x]);
}
void bud(int l,int r,int dep){
	if(l>r)return;
	int mid=qmax(l,r);
	val[mid]=dep;
	bud(l,mid-1,dep+1),bud(mid+1,r,dep+1);
}
struct segTree{
	const static int N=::N*2;
	int t[N*4],tg[N*4];
	void pst(int k1,int k2){
		t[k1]+=k2;
		tg[k1]+=k2;
	}
	void psd(int k1){
		if(tg[k1]){
			pst(k1*2,tg[k1]);
			pst(k1*2+1,tg[k1]);
			tg[k1]=0;
		}
	}
	void upd(int k1){
		t[k1]=max(t[k1*2],t[k1*2+1]);
	}
	void bud(int k1,int k2,int k3){
		if(k2==k3){
			if(k2<=n){
				t[k1]=val[k2];
			}
			return;
		}
		int mid=(k2+k3)>>1;
		bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
		upd(k1);
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
		upd(k1);
	}
	void set(int k1,int k2,int k3,int k4,int k5){
		if(k2==k3){
			t[k1]=k5;
			return;
		}
		psd(k1);
		int mid=(k2+k3)>>1;
		if(k4<=mid)set(k1*2,k2,mid,k4,k5);
		else set(k1*2+1,mid+1,k3,k4,k5);
		upd(k1);
	}
	int res;
	void ask(int k1,int k2,int k3,int k4){
		if(k2==k3){
			res=t[k1];
			return;
		}
		psd(k1);
		int mid=(k2+k3)>>1;
		if(k4<=mid)ask(k1*2,k2,mid,k4);
		else ask(k1*2+1,mid+1,k3,k4);
	}
	int ask(int pos){
		res=0;
		ask(1,1,n*2,pos);
		return res;
	}
	void out(int k1,int k2,int k3){
		if(k2==k3){
			D("%d ",t[k1]);
			return;
		}
		psd(k1);
		int mid=(k2+k3)>>1;
		out(k1*2,k2,mid),out(k1*2+1,mid+1,k3);
		if(k1==1)D("\n");
	}
}tr;
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rep(i,2,N-1)lg[i]=lg[i>>1]+1;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]),a[i+n]=a[i];
	{
		vector<int>st;
		rep(i,1,n*2){
			while(!st.empty()&&a[i]<a[st.back()])nex[st.back()]=i,st.pop_back();
			st.pb(i);
		}
		while(!st.empty())nex[st.back()]=n*2+1,st.pop_back();
	}
	{
		vector<int>st;
		per(i,n*2,1){
			while(!st.empty()&&a[i]<a[st.back()])pre[st.back()]=i,st.pop_back();
			st.pb(i);
		}
		while(!st.empty())pre[st.back()]=0,st.pop_back();
	}
	rep(i,1,n)f[i][0]=i;
	rep(j,1,K-1)rep(i,1,n-(1<<j)+1)f[i][j]=max_(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	bud(1,n,1);
	tr.bud(1,1,n*2);
	int ans=tr.t[1],ans_=0;
	//tr.out(1,1,n*2);
	rep(i,1,n-1){
		tr.mdf(1,1,n*2,i,min(i+n-1,nex[i]-1),-1);
		tr.mdf(1,1,n*2,max(i+1,pre[i+n]+1),i+n,1);
		tr.set(1,1,n*2,i,0);
		tr.set(1,1,n*2,i+n,pre[i+n]<=i?1:tr.ask(pre[i+n])+1);
		//D("i=%d ans=%d\n",i,tr.t[1]);
		if(tr.t[1]<ans){
			ans=tr.t[1],ans_=i;
		}
		//tr.out(1,1,n*2);
	}
	printf("%d %d\n",ans,ans_);
	return 0;
}