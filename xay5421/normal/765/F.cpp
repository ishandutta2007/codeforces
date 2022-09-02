#include<bits/stdc++.h>
using namespace std;
const int N=400005;
int n,m,tmp,a[N],le[N],v[N],ans[N];vector<int>num[N],g[N];
void bud(int k1,int k2,int k3){
	for(int i=k2;i<=k3;++i)num[k1].push_back(a[i]);
	if(k2==k3)return;
	sort(num[k1].begin(),num[k1].end());
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
}
void mdf(int k1,int k2,int k3,int k4,int k5){
	if(k2>k4)return;
	if(k3<=k4){
		auto it=upper_bound(num[k1].begin(),num[k1].end(),k5);
		if(it!=num[k1].end())v[k1]=min(v[k1],*it-k5);
		if(it!=num[k1].begin())--it,v[k1]=min(v[k1],k5-*it);
		if(tmp<=v[k1])return;if(k2>=k3){tmp=min(tmp,v[k1]);return;}
	}
	int mid=(k2+k3)>>1;
	mdf(k1*2+1,mid+1,k3,k4,k5),mdf(k1*2,k2,mid,k4,k5);
	v[k1]=min({v[k1],v[k1*2],v[k1*2+1]});
	tmp=min(tmp,v[k1]);
}
int qry(int k1,int k2,int k3,int k4,int k5){
	if(k3<k4||k2>k5)return 0x3f3f3f3f;
	if(k4<=k2&&k3<=k5)return v[k1];
	int mid=(k2+k3)>>1;
	return min(qry(k1*2,k2,mid,k4,k5),qry(k1*2+1,mid+1,k3,k4,k5));
}
int main(){
	memset(v,63,sizeof(v));
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	bud(1,1,n);
	scanf("%d",&m);
	for(int i=1;i<=m;++i){
		int k1,k2;scanf("%d%d",&k1,&k2);
		le[i]=k1;
		g[k2].push_back(i);
	}
	for(int i=2;i<=n;++i){
		tmp=0x3f3f3f3f;
		mdf(1,1,n,i-1,a[i]);
		for(auto j:g[i]){
			ans[j]=qry(1,1,n,le[j],i);
		}
	}
	for(int i=1;i<=m;++i)printf("%d\n",ans[i]);
	return 0;
}