#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N=60000;
struct bian{
	int next,point;
}b[N<<1];
int dfs[N],r[N],sign,p[N],size[N],father[N],len;
void addall(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void dfs1(int k1,int k2){
	size[k1]=1;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2){
			dfs1(j,k1); size[k1]+=size[j];
		}
	}
}
int where[N],now,l[N],n;
void dfs2(int k1,int k2){
	int k=0; dfs[k1]=++sign; father[k1]=k2;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2&&size[j]>size[k]) k=j;
	}
	if (k==0){r[k1]=sign; return;}
	where[k]=where[k1]; dfs2(k,k1);
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2&&j!=k){
			now++; l[now]=j; where[j]=now; dfs2(j,k1);
		}
	}
	r[k1]=sign;
} 
int pd[N<<2],A[N<<2];
long long f[N<<2],si[N<<2],g[N<<2];
void add(int k1,int k2){
	pd[k1]=sign;
	g[k1]+=2ll*k2*f[k1]+1ll*k2*k2*si[k1];
	f[k1]+=1ll*k2*si[k1];
	A[k1]+=k2;
}
void pushdown(int k1){
	pd[k1]=sign;
	if (A[k1]){	
		add(k1*2,A[k1]); add(k1*2+1,A[k1]); A[k1]=0;
	}
}
void change(int k1){
	pd[k1]=sign;
	f[k1]=f[k1*2]+f[k1*2+1];
	g[k1]=g[k1*2]+g[k1*2+1];
	si[k1]=si[k1*2]+si[k1*2+1];
}
void add(int k1,int k2,int k3,int k4,int k5,int k6){
	pd[k1]=sign;
	//cout<<k1<<" "<<k2<<" "<<k3<<endl;
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
		add(k1,k6); return;
	}
	int mid=k2+k3>>1; pushdown(k1);
	add(k1*2,k2,mid,k4,k5,k6);
	add(k1*2+1,mid+1,k3,k4,k5,k6);
	change(k1);
}
void clear(int k1,int k2,int k3){
	A[k1]=f[k1]=si[k1]=g[k1]=0;
	if (k2==k3) {si[k1]=1; return;}
	if (pd[k1]==sign){
		int mid=k2+k3>>1;
		clear(k1*2,k2,mid);
		clear(k1*2+1,mid+1,k3);
	}
	change(k1);
}
void addin(int k1,int k2){
	while (k1){
		int k3=l[where[k1]];
		//cout<<"addin "<<k1<<" "<<k2<<" "<<dfs[k3]<<" "<<dfs[k1]<<endl;
		add(1,1,n,dfs[k3],dfs[k1],k2);
		k1=father[k3];
	}
}
int m,q,C;
struct atom{
	int t,where,w;
};
vector<atom>B[110000];
int pre[110000],bo[110000],c[110000];
double ans[110000];
double getans(int k){
	return 1.0*C*C+1.0*c[k]*c[k]*g[1]/n-2.0*C*c[k]*f[1]/n;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&q,&C);
	for (int i=1;i<=n;i++){
		int k1; scanf("%d",&k1); pre[i]=k1;
		B[k1].push_back((atom){0,i,1});
	}
	for (int i=2;i<=n;i++){
		scanf("%d",&father[i]); addall(father[i],i);
	}
	dfs1(1,0); now=1; l[1]=1; where[1]=1; dfs2(1,0); sign=0;
	for (int i=1;i<=m;i++) scanf("%d",&c[i]);
	for (int i=1;i<=q;i++){
		int k1,k2; scanf("%d%d",&k1,&k2);
		if (k1==1){
			int k3; scanf("%d",&k3);
			B[pre[k2]].push_back((atom){i,k2,-1});
			pre[k2]=k3;
			B[pre[k2]].push_back((atom){i,k2,1});
		} else {
			B[k2].push_back((atom){i,0,0}); bo[i]=1;
		}
	}
	for (int now=1;now<=m;now++){
		clear(1,1,n); sign++;
		for (int i=0;i<B[now].size();i++){
			atom k1=B[now][i];
			if (k1.w==0) ans[k1.t]=getans(now);
			else addin(k1.where,k1.w);
		}
	}
	for (int i=1;i<=q;i++) if (bo[i]) printf("%.11lf\n",ans[i]);
	return 0;
}