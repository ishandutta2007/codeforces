#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct bian{
	int next,point;
}b[210000];
int p[110000],d[110000],n,m,pd[110000],len,ans[110000];
vector<int>A,x[10];
int compare(vector<int>A,vector<int>B){
	return A.size()<B.size();
}
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len; d[k1]++;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
void dfs(int k){
	pd[k]=1; A.push_back(k);
	for (int i=p[k];i;i=b[i].next){
		int j=b[i].point;
		if (pd[j]==0) dfs(j);
	}
}
void print(){
	printf("YES\n");
	for (int i=1;i<=n;i++) printf("%d ",ans[i]); printf("\n");
}
void dfs2(int k1,int k2,int k3){
	x[k3].push_back(k1);
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2) dfs2(j,k1,k3);
	}
}
int solveextra(int k){
	int tot=0;
	for (int i=0;i<3;i++) x[i].clear();
	for (int i=p[k];i;i=b[i].next){
		int j=b[i].point;
		dfs2(j,k,tot); tot++;
	}
	sort(x,x+3,compare);
	int a=x[0].size(),b=x[1].size(),c=x[2].size();
//	cout<<"fa "<<k<<" "<<a<<" "<<b<<" "<<c<<endl; 
	int lima=0,limb=0,limc=0;
	if (a>1&&b>1&&c>1){
		lima=3; limb=3; limc=3;
	} else if (a==1&&b==1) return 0;
	else {
		lima=2;
		int flag=0;
		for (int i=2;i<=b+1;i++){
			double now=1/4.0+1.0*(i-1)/2/i+(1.0)*(c)/2/(c+1);
		//	cout<<"fa "<<i<<" "<<c<<" "<<now<<endl;
			if (now+1e-9>1){
				limb=i; limc=c+1; flag=1; break;
			}
		}
		if (flag==0) return 0;
	}
	tot=lima;
	tot=tot*limb/__gcd(tot,limb);
	tot=tot*limc/__gcd(tot,limc);
	ans[k]=tot; int lim[3];
	lim[0]=lima; lim[1]=limb; lim[2]=limc;
	for (int i=0;i<3;i++){
		int K=tot/lim[i];
		for (int j=0;j<x[i].size();j++){
			ans[x[i][j]]=max(1ll*K,tot-1ll*K*(j+1));
		}
	}
	print(); return 1;
}
void solve(){
	scanf("%d%d",&n,&m); len=0;
	for (int i=1;i<=n;i++) p[i]=d[i]=pd[i]=ans[i]=0;
	for (int i=1;i<=m;i++){
		int k1,k2; scanf("%d%d",&k1,&k2);
		add(k1,k2);
	}
	for (int i=1;i<=n;i++)
		if (pd[i]==0){
			A.clear();
			dfs(i); int totm=0;
			for (int j=0;j<A.size();j++) totm+=d[A[j]];
			totm/=2; //cout<<totm<<" "<<A.size()<<endl;
			if (totm>=A.size()){
				for (int j=0;j<A.size();j++) ans[A[j]]=1;
				print(); return;
			}
			int num=0;
			for (int j=0;j<A.size();j++)
				if (d[A[j]]==1) num++;
			if (num>=4){
				for (int j=0;j<A.size();j++)
					if (d[A[j]]==1) ans[A[j]]=1; else ans[A[j]]=2;
				print(); return;
			}
			if (num==3){
				int where=0;
				for (int j=0;j<A.size();j++)
					if (d[A[j]]==3) where=A[j];
				if (solveextra(where)) return;
			}
		}
	printf("NO\n");
}
int main(){
	int t; scanf("%d",&t);
	for (;t;t--) solve();
	return 0;
}