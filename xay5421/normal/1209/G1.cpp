#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=200005;
int n,Q,a[N];
set<int>S[N];
int tg[N*4],t[N*4],mn[N*4],mx[N*4],lw[N*4],rw[N*4];
void pst(int k1,int k2){
	tg[k1]+=k2,mn[k1]+=k2;
}
void psd(int k1){
	if(tg[k1]){
		pst(k1*2,tg[k1]);
		pst(k1*2+1,tg[k1]);
		tg[k1]=0;
	}
}
void upd(int k1){
	mx[k1]=max(mx[k1*2],mx[k1*2+1]);
	mn[k1]=min(mn[k1*2],mn[k1*2+1]);
	if(mn[k1*2]<mn[k1*2+1]){
		lw[k1]=lw[k1*2];
		rw[k1]=max(rw[k1*2],mx[k1*2+1]);
		t[k1]=t[k1*2];
	}
	else if(mn[k1*2]>mn[k1*2+1]){
		lw[k1]=max(mx[k1*2],lw[k1*2+1]);
		rw[k1]=rw[k1*2+1];
		t[k1]=t[k1*2+1];
	}
	else{
		lw[k1]=lw[k1*2];
		rw[k1]=rw[k1*2+1];
		t[k1]=t[k1*2]+t[k1*2+1]+max(rw[k1*2],lw[k1*2+1]);
	}
	/*if(t[k1]){
		D("233\n");
	}*/
}
void bud(int k1,int k2,int k3){
	if(k2==k3){
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	upd(k1);
}
void chg(int k1,int k2,int k3,int k4,int k5){
	//if(k1==1)D("chg %d %d\n",k4,k5);
	if(k2==k3){
		mx[k1]=k5;
		lw[k1]=k5;
		rw[k1]=0;
		t[k1]=0;
		return;
	}
	psd(k1);
	int mid=(k2+k3)>>1;
	k4<=mid?chg(k1*2,k2,mid,k4,k5):chg(k1*2+1,mid+1,k3,k4,k5);
	upd(k1);
}
void add(int k1,int k2,int k3,int k4,int k5,int k6){
	//if(k1==1)D("add %d %d %d\n",k4,k5,k6);
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
void ps(int x,int y){
	if(SZ(S[x])==0)return;
	chg(1,1,n,*S[x].begin(),y>0?SZ(S[x]):0);
	add(1,1,n,*S[x].begin(),*--S[x].end()-1,y);
}
void out(int k1,int k2,int k3){
	if(k2==k3)return;
	//D(">>> k1=%d [%d,%d] lw=%d rw=%d t=%d\n",k1,k2,k3,lw[k1],rw[k1],t[k1]);
	psd(k1);
	int mid=(k2+k3)>>1;
	out(k1*2,k2,mid),out(k1*2+1,mid+1,k3);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&Q);
	rep(i,1,n)scanf("%d",&a[i]),S[a[i]].insert(i);
	bud(1,1,n);
	rep(i,1,N-1)ps(i,1);
	out(1,1,n);
	rep(i,0,Q){
		if(i){
			int pos,x;
			scanf("%d%d",&pos,&x);
			ps(a[pos],-1),S[a[pos]].erase(pos),ps(a[pos],1);
			a[pos]=x;
			ps(a[pos],-1),S[a[pos]].insert(pos),ps(a[pos],1);
		}
		printf("%d\n",n-t[1]-lw[1]-rw[1]);
	}
	return 0;
}