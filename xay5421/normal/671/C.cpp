// author: xay5421
// created: Tue Dec  8 21:48:52 2020
#include<bits/stdc++.h>
#define PB push_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
const int N=200005;
int n,a[N];
vector<int>v[N];
int mn[N*4],mx[N*4],tg[N*4];
LL sum[N*4];
void upd(int k1){mn[k1]=min(mn[k1*2],mn[k1*2+1]),mx[k1]=max(mx[k1*2],mx[k1*2+1]),sum[k1]=sum[k1*2]+sum[k1*2+1];}
void pst(int k1,int k2,int sz){
	mn[k1]=mx[k1]=tg[k1]=k2,sum[k1]=1LL*sz*k2;
}
void psd(int k1,int sz){
	if(tg[k1]){
		pst(k1*2,tg[k1],(sz+1)>>1);
		pst(k1*2+1,tg[k1],sz>>1);
		tg[k1]=0;
	}
}
void bud(int k1,int k2,int k3){
	if(k2==k3){
		pst(k1,k2,1);
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	upd(k1);
}
void mdf(int k1,int k2,int k3,int k4,int k5,int k6){
	if(k2>k5||k3<k4||mn[k1]>=k6)return;
	if(k4<=k2&&k3<=k5&&mx[k1]<=k6){
		pst(k1,k6,k3-k2+1);
		return;
	}
	psd(k1,k3-k2+1);
	int mid=(k2+k3)>>1;
	mdf(k1*2,k2,mid,k4,k5,k6),mdf(k1*2+1,mid+1,k3,k4,k5,k6);
	upd(k1);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
		rep(j,1,a[i]/j)if(a[i]%j==0){
			v[j].PB(i);
			if(j*j!=a[i]){
				v[a[i]/j].PB(i);
			}
		}
	}
	bud(1,1,n);
	LL lst=sum[1];
	LL ans=0;
	per(i,N-1,0)if(SZ(v[i])>=2){
		if(v[i][1]<n)mdf(1,1,n,v[i][1]+1,n,n+1);
		mdf(1,1,n,v[i][0]+1,v[i][1],v[i].back());
		mdf(1,1,n,1,v[i][0],v[i][SZ(v[i])-2]);
		ans+=(sum[1]-lst)*i;
		lst=sum[1];
	}
	printf("%lld\n",ans);
	return 0;
}