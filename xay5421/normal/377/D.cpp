#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,l[N],v[N],r[N],mx[N<<2],id[N<<2],tg[N<<2];
struct data{int l,r,x;};
vector<data>g[N];
void pst(int k1,int k2){mx[k1]+=k2,tg[k1]+=k2;}
void psd(int k1){if(tg[k1])pst(k1*2,tg[k1]),pst(k1*2+1,tg[k1]),tg[k1]=0;}
void mdf(int k1,int k2,int k3,int k4,int k5,int k6){
//	printf("mdf:%d %d %d %d %d %d\n",k1,k2,k3,k4,k5,k6);
	if(!id[k1])id[k1]=k2;
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){pst(k1,k6);return;}
	psd(k1); 
	int mid=k2+k3>>1;
	mdf(k1*2,k2,mid,k4,k5,k6),mdf(k1*2+1,mid+1,k3,k4,k5,k6);
	mx[k1]=max(mx[k1*2],mx[k1*2+1]);
	if(id[k1*2]&&mx[k1]==mx[k1*2])id[k1]=id[k1*2];
	else id[k1]=id[k1*2+1];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d%d",&l[i],&v[i],&r[i]),g[l[i]].push_back((data){v[i],r[i],1}),g[v[i]+1].push_back((data){v[i],r[i],-1});
	int ans=0,x=0,y=0;
	for(int i=1;i<N;++i){
		for(auto k1:g[i])mdf(1,1,300000,k1.l,k1.r,k1.x);
		if(mx[1]>ans){
			ans=mx[1];
			x=i,y=id[1];
//			printf("upd:%d %d\n",x,y);
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;++i)if(l[i]<=x&&x<=v[i]&&v[i]<=y&&y<=r[i])printf("%d ",i);
	return 0;
}