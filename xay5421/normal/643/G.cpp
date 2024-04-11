#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=150005;
int n,m,p,a[N];
struct data{
	int x[5],cnt[5];
	void push(int k1,int k2){
		rep(i,0,p-1)if(x[i]==k1){cnt[i]+=k2;return;}
		rep(i,0,p-1)if(x[i]==0){x[i]=k1,cnt[i]=k2;return;}
		int j=0;
		rep(i,1,p-1)if(cnt[i]<cnt[j])j=i;
		if(k2>cnt[j])swap(k1,x[j]),swap(k2,cnt[j]);
		rep(i,0,p-1)cnt[i]-=k2;
	}
	data operator+(const data&k2)const{
		data k1=*this;
		rep(i,0,p-1)k1.push(k2.x[i],k2.cnt[i]);
		return k1;
	}
	void clear(){memset(x,0,sizeof(x)),memset(cnt,0,sizeof(cnt));}
}t[N<<2],ans;
int tag[N<<2];
void upd(int k1){t[k1]=t[k1*2]+t[k1*2+1];}
void bud(int k1,int k2,int k3){
	if(k2==k3){t[k1].x[0]=a[k2],t[k1].cnt[0]=1;return;}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	upd(k1);
}
void pst(int k1,int k2,int k3){
	tag[k1]=k2,t[k1].clear(),t[k1].x[0]=k2,t[k1].cnt[0]=k3;
}
void psd(int k1,int k2){
	if(tag[k1])pst(k1*2,tag[k1],k2-(k2>>1)),pst(k1*2+1,tag[k1],k2>>1),tag[k1]=0;
}
void mdf(int k1,int k2,int k3,int k4,int k5,int k6){
	if(k5<k2||k3<k4)return;
	if(k4<=k2&&k3<=k5){pst(k1,k6,k3-k2+1);return;}
	psd(k1,k3-k2+1);
	int mid=(k2+k3)>>1;
	mdf(k1*2,k2,mid,k4,k5,k6),mdf(k1*2+1,mid+1,k3,k4,k5,k6);
	upd(k1);
}
void qry(int k1,int k2,int k3,int k4,int k5){
	if(k5<k2||k3<k4)return;
	if(k4<=k2&&k3<=k5){ans=ans+t[k1];return;}
	psd(k1,k3-k2+1);
	int mid=(k2+k3)>>1;
	qry(k1*2,k2,mid,k4,k5),qry(k1*2+1,mid+1,k3,k4,k5);
}
int main(){
	scanf("%d%d%d",&n,&m,&p);p=100/p;
	rep(i,1,n)scanf("%d",&a[i]);
	bud(1,1,n);
	while(m--){
		int k1,k2,k3;scanf("%d%d%d",&k1,&k2,&k3);
		if(k1==1){
			int k4;scanf("%d",&k4);
			mdf(1,1,n,k2,k3,k4);
		}else{
			ans.clear();
			qry(1,1,n,k2,k3);
			printf("%d ",p);
			rep(i,0,p-1)printf("%d ",ans.x[i]);puts("");
		}
	}
	return 0;
}