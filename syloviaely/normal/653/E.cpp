#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
struct bian{
	int next,point;
}b[610000];
int f[310000],pd[310000],n,m,len,p[310000],bo[310000],K,d[310000],pd2[310000],sign;
vector<int>rem;
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len; d[k1]++;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
int findfather(int k1){
	if (f[k1]==k1) return k1; f[k1]=findfather(f[k1]); return f[k1];
}
int merge(int k1,int k2){
	k1=findfather(k1); k2=findfather(k2);
	f[k1]=k2; bo[k2]|=bo[k1];
}
void insert(int k){
	sign++;
	for (int i=p[k];i;i=b[i].next){
		int j=b[i].point;
		pd2[j]=sign;
	}
	for (int i=2;i<=n;i++) if (pd2[i]!=sign) merge(k,i);
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	int tot=n-1;
	for (int i=1;i<=m;i++){
		int k1,k2; scanf("%d%d",&k1,&k2); add(k1,k2);
		if (k1==1||k2==1) tot--;
	}
	if (tot<K){
		printf("impossible\n"); return 0;
	}
	for (int i=2;i<=n;i++) bo[i]=1;
	for (int i=p[1];i;i=b[i].next){
		int j=b[i].point;
		d[j]--; bo[j]=0;
	}
	int where=2;
	for (int i=3;i<=n;i++) if (d[i]<d[where]) where=i;
	for (int i=2;i<=n;i++) f[i]=i;
	for (int i=2;i<=n;i++) pd[i]=1;
	for (int i=p[where];i;i=b[i].next){
		int j=b[i].point;
		pd[j]=0;
	}
	for (int i=2;i<=n;i++) if (pd[i]==1) merge(i,where);
	for (int i=2;i<=n;i++) if (pd[i]==0) rem.push_back(i);
	for (int i=2;i<=n;i++) if (pd[i]==0) insert(i);
	int num=0;
	for (int i=2;i<=n;i++) if (findfather(i)==i){
		if (bo[i]==0){printf("impossible\n"); return 0;}
		num++;
	}
	if (num>K) printf("impossible\n"); else printf("possible\n");
	return 0;
}