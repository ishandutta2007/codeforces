#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct atom{
	int where,w;
}q[510000];
vector<atom>A[3000000],B[510000];
struct atom2{
	int where,w,pd;
}s[3000000];
int n,m,u[510000],v[510000],Q,K,father[51][510000],no[510000],size[51][510000],c[510000],pd[51][510000],len;
int compare(atom k1,atom k2){
	return k1.where<k2.where;
}
void add(int k1,int k2,int k3,int k4,int k5,int where,int w){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
		A[k1].push_back((atom){where,w}); return;
	}
	int mid=k2+k3>>1;
	add(k1*2,k2,mid,k4,k5,where,w);
	add(k1*2+1,mid+1,k3,k4,k5,where,w);
}
void insert(int k1,int fl=1){
	if (no[k1]==B[k1].size()) return;
	int L=B[k1][no[k1]].where,R=0,w=B[k1][no[k1]].w;
	if (fl==0) w=c[k1]; else c[k1]=w;
	no[k1]++; if (no[k1]==B[k1].size()) R=Q; else R=B[k1][no[k1]].where-2;
	if (w==0) return;
	add(1,1,Q,L,R,k1,w);
}
int getfather(int k1,int k2){
	while (father[k1][k2]) k2=father[k1][k2];
	return k2;
}
int getw(int k1,int k2){
	int ans=0;
	while (father[k1][k2]) ans^=pd[k1][k2],k2=father[k1][k2];
	return ans;
}
void link(int k1,int k2,int k3){
	int f1=getfather(k3,k1),f2=getfather(k3,k2),w1=getw(k3,k1),w2=getw(k3,k2);
	if (f1==f2) return;
	if (size[k3][f1]>size[k3][f2]) swap(f1,f2);
	//cout<<"link "<<k1<<" "<<k2<<" "<<k3<<" "<<f1<<" "<<f2<<" "<<w1<<" "<<w2<<endl;
	father[k3][f1]=f2; pd[k3][f1]=1^w1^w2;
	len++; s[len]=(atom2){f1,k3,0};
	if (size[k3][f1]==size[k3][f2]) {size[k3][f2]++; s[len].pd=1;}
}
void getback(int k1){
	while (len>k1){
		int a=s[len].w,b=s[len].where;
		if (s[len].pd) size[a][father[a][b]]--;
		father[a][b]=0; pd[a][b]=0;
		len--;
	}
}
void getans(int k1,int k2,int k3){
	int prelen=len;
	for (int i=0;i<A[k1].size();i++) link(u[A[k1][i].where],v[A[k1][i].where],A[k1][i].w);
	if (k2==k3){
		int k4=u[q[k2].where],k5=v[q[k2].where];
		if (q[k2].w&&getfather(q[k2].w,k4)==getfather(q[k2].w,k5)&&getw(q[k2].w,k4)==getw(q[k2].w,k5)){
			printf("NO\n"); insert(q[k2].where,0);
		} else {
			printf("YES\n"); insert(q[k2].where);
		}
	} else {
		int mid=k2+k3>>1; getans(k1*2,k2,mid); getans(k1*2+1,mid+1,k3);
	}
	getback(prelen);
}
int main(){
	scanf("%d%d%d%d",&n,&m,&K,&Q);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&u[i],&v[i]); 
		B[i].push_back((atom){1,0});
	}
	for (int i=1;i<=Q;i++){
		scanf("%d%d",&q[i].where,&q[i].w);
		B[q[i].where].push_back((atom){i+1,q[i].w});
	}
	for (int i=1;i<=m;i++) sort(B[i].begin(),B[i].end(),compare);
	for (int i=1;i<=m;i++) insert(i); 
	getans(1,1,Q);
	return 0;
}