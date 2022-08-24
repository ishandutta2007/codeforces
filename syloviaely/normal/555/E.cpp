#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct bian{
	int next,point;
}b[410000];
int p[210000],len,n,m,f[210000],K,s[210000],d[210000],num[210000],sign,dfs[210000],low[210000],now,pd[210000],head;
int father[210000][18],w[210000];
vector<int>go[210000];
struct atom{
	int u,v;
}A[210000];
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
int findfather(int k){
	if (k==f[k]) return k; f[k]=findfather(f[k]); return f[k];
}
void dfs1(int k1,int k2){
	pd[k1]=1; s[++head]=k1; dfs[k1]=++sign; low[k1]=sign; 
	for (int i=p[k1];i!=-1;i=b[i].next){
		int j=b[i].point;
		if ((i^1)==k2) continue;
		if (pd[j]==0){
			dfs1(j,i); low[k1]=min(low[k1],low[j]);
		} else low[k1]=min(low[k1],dfs[j]);
	}
	if (low[k1]==dfs[k1]){
		now++;
		while (1){
			num[s[head]]=now; head--;
			if (s[head+1]==k1) return;
		}
	}
}
void dfs2(int k1,int k2){
	d[k1]=d[k2]+1; father[k1][0]=k2; pd[k1]=1;
	for (int i=0;i<go[k1].size();i++){
		int j=go[k1][i];
		if (j!=k2) dfs2(j,k1);
	}
}
int findlca(int k1,int k2){
	if (d[k1]<d[k2]) swap(k1,k2);
	for (int i=17;i>=0;i--) if (d[k1]-d[k2]>=(1<<i)) k1=father[k1][i];
	if (k1==k2) return k1;
	for (int i=17;i>=0;i--) if (father[k1][i]!=father[k2][i]){
		k1=father[k1][i]; k2=father[k2][i];
	}
	return father[k1][0];
}
int print(int k1,int k2,int k3){
	if (d[k1]<=d[k2]) return 1;
	k1=findfather(k1); if (w[k1]!=-1&&w[k1]!=k3) return 0;
	while (1){
		if (d[k1]<=d[k2]) return 1;
		if (w[k1]==-1) w[k1]=k3; 
		if (father[k1][0]==k2) return 1;
		int k4=findfather(father[k1][0]);
		if (w[k4]==-1){
			f[k1]=k4; w[k4]=k3; k1=k4; continue;
		}
		if (w[k4]!=k3) return 0;
		f[k1]=k4; k1=k4;
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&K); len=-1;
	memset(p,0xff,sizeof p);
	for (int i=1;i<=n;i++) f[i]=i;
	for (;m;m--){
		int k1,k2; scanf("%d%d",&k1,&k2); add(k1,k2);
		k1=findfather(k1); k2=findfather(k2);
		if (k1!=k2) f[k1]=k2;
	}
	for (int i=1;i<=K;i++){
		scanf("%d%d",&A[i].u,&A[i].v);
	//	cout<<findfather(A[i].u)<<" "<<findfather(A[i].v)<<endl;
		if (findfather(A[i].u)!=findfather(A[i].v)){
			printf("No\n"); return 0;
		}
	}
	sign=0; now=0;
	for (int i=1;i<=n;i++) if (pd[i]==0) dfs1(i,-1);
//	for (int i=1;i<=n;i++) cout<<num[i]<<" "; cout<<endl;
	memset(pd,0x00,sizeof pd);
	for (int i=1;i<=n;i++) f[i]=i;
	for (int k=1;k<=n;k++)
		for (int i=p[k];i!=-1;i=b[i].next){
			int j=b[i].point;
			if (num[j]!=num[k]) go[num[k]].push_back(num[j]);
		}
	for (int i=1;i<=n;i++) if (pd[i]==0) dfs2(i,0);
	for (int i=1;i<=17;i++)
		for (int j=1;j<=n;j++) father[j][i]=father[father[j][i-1]][i-1];
	memset(w,0xff,sizeof w);
	for (int i=1;i<=K;i++){
		int k1=num[A[i].u],k2=num[A[i].v]; int k3=findlca(k1,k2);
		if (print(k1,k3,0)==0||print(k2,k3,1)==0){
			printf("No\n"); return 0;
		}
	}
	printf("Yes\n");
	return 0;
}