#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<unordered_map>
using namespace std;
struct ask{
	int x,type;
}q[210000];
int a[210000],f[210000],n,m,A[1000000],B[1000000],now;
unordered_map<int,int>M;
int compare(int k1,int k2){
	return q[k1].x<q[k2].x;
}
void pushdown(int k1){
	if (A[k1]!=now+1){
		A[k1*2]=min(A[k1*2],A[k1]); A[k1*2+1]=min(A[k1*2+1],A[k1]); A[k1]=now+1;
	}
	if (B[k1]){
		B[k1*2]=max(B[k1],B[k1*2]); B[k1*2+1]=max(B[k1],B[k1*2+1]); B[k1]=0;
	}
}
int findA(int k1,int k2,int k3,int k4){
	if (k2==k3) return A[k1];
	pushdown(k1); int mid=k2+k3>>1;
	if (mid>=k4) return findA(k1*2,k2,mid,k4); else return findA(k1*2+1,mid+1,k3,k4);
}
int findB(int k1,int k2,int k3,int k4){
	if (k2==k3) return B[k1];
	pushdown(k1); int mid=k2+k3>>1;
	if (mid>=k4) return findB(k1*2,k2,mid,k4); else return findB(k1*2+1,mid+1,k3,k4);
}
void changeallA(int k1,int k2,int k3,int k4,int k5,int k6){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){A[k1]=min(k6,A[k1]); return;}
	int mid=k2+k3>>1; pushdown(k1);
	changeallA(k1*2,k2,mid,k4,k5,k6);
	changeallA(k1*2+1,mid+1,k3,k4,k5,k6);
}
void changeallB(int k1,int k2,int k3,int k4,int k5,int k6){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){B[k1]=max(B[k1],k6); return;}
	int mid=k2+k3>>1; pushdown(k1);
	changeallB(k1*2,k2,mid,k4,k5,k6);
	changeallB(k1*2+1,mid+1,k3,k4,k5,k6);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int k1,k2; scanf("%d%d",&k1,&k2);
		q[i].x=k1; char ch[5];
		scanf("%s",ch+1);
		if (ch[1]=='U') q[i].type=0; else q[i].type=1;
	}
//	for (int i=1;i<=m;i++) cout<<q[i].type<<" "; cout<<endl;
	for (int i=1;i<=m;i++) a[i]=i;
	sort(a+1,a+m+1,compare); now=0;
	for (int i=1;i<=m;i++){
		if (q[a[i]].x!=f[now]) {now++; f[now]=q[a[i]].x;}
		q[a[i]].x=now;
	}
	for (int i=1;i<=900000;i++) A[i]=now+1;
	f[now+1]=n+1;
	for (int i=1;i<=m;i++)
		if (q[i].type==0){
			if (M[q[i].x]){
				printf("0\n"); continue;
			}
			int k1=findA(1,1,now,q[i].x); 
			printf("%d\n",f[k1]-f[q[i].x]);
	//		cout<<"changeB "<<k1<<" "<<f[q[i].x+1]<<" "<<f[k1-1]<<" "<<f[q[i].x]<<endl;
			changeallB(1,1,now,q[i].x+1,k1-1,q[i].x);
			M[q[i].x]=1;
		} else {
			if (M[q[i].x]){
				printf("0\n"); continue;
			}
			int k1=findB(1,1,now,q[i].x);
			printf("%d\n",abs(f[q[i].x]-f[k1]));
	//		cout<<"changeA "<<k1<<" "<<f[k1+1]<<" "<<f[q[i].x-1]<<" "<<f[q[i].x]<<endl;
			changeallA(1,1,now,k1+1,q[i].x-1,q[i].x);
			M[q[i].x]=1;
		}
	return 0;
}