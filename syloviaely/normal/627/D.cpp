#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct bian{
	int next,point;
}b[410000];
int a[210000],p[210000],len,n,K,num[210000],ans[210000],pd[210000],f[210000],m,tot,g[210000],where[210000];
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
void dfs(int k1,int k2){
	num[k1]=0; ans[k1]=1; pd[k1]=1; f[k1]=0; g[k1]=0; where[k1]=0;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j==k2) continue;
		if (a[j]<K) num[k1]++;
		else {
			dfs(j,k1);
			if (num[j]){
				num[k1]+=num[j];
				if (ans[j]+f[j]>f[k1]){
					g[k1]=f[k1]; where[k1]=j; f[k1]=ans[j]+f[j];
				} else if (ans[j]+f[j]>g[k1])
					g[k1]=ans[j]+f[j];
			} else ans[k1]+=ans[j];
		}
	}
}
void findans(int k1,int k2,int k3,int k4){
//	cout<<"findans "<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<" "<<ans[k1]<<" "<<num[k1]<<" "<<f[k1]<<endl;
	if (k3==0) tot=max(tot,ans[k1]+f[k1]+k4);
	else tot=max(tot,ans[k1]+max(f[k1],k4));
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j==k2||a[j]<K) continue;
		if (num[k1]-num[j]+k3==0){
			int k5=ans[k1]+k4; if (num[j]==0) k5-=ans[j]; findans(j,k1,0,k5);
		} else if (num[j]==0){
			int k5=ans[k1]-ans[j]; 
			if (k3) k5+=max(f[k1],k4); else k5+=f[k1]+k4;
			findans(j,k1,1,k5);
		} else if (j==where[k1]){
			int k5=ans[k1]; 
			if (k3) k5+=max(g[k1],k4); else k5+=g[k1]+k4;
			findans(j,k1,1,k5);
		} else {
			int k5=ans[k1]; 
			if (k3) k5+=max(f[k1],k4); else k5+=f[k1]+k4;
			findans(j,k1,1,k5);
		}
	}
}
int check(){
	memset(pd,0x00,sizeof pd);
	tot=0;
//	cout<<"check "<<K<<endl;
	for (int i=1;i<=n;i++)
		if (pd[i]==0&&a[i]>=K){
			dfs(i,0); findans(i,0,0,0);
		}
	return tot>=m;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++){
		int k1,k2; scanf("%d%d",&k1,&k2); add(k1,k2);
	}
	int l=1,r=1000001,ans=0;
	while (l<r){
		int mid=l+r>>1; K=mid;
		if (check()){
			l=mid+1; ans=mid;
		} else r=mid;
	}
	printf("%d\n",ans); return 0;
}