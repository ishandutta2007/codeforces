#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=110000;
int A[N<<2][10],n,m,B[10],y[10],D[N],x[N];
long long num[N<<2][10],C[10];
void change(int k1){
	for (int i=0;i<10;i++) num[k1][i]=num[k1*2][i]+num[k1*2+1][i];
}
void add(int k1,int *x){
	memcpy(C,num[k1],sizeof C);
	memset(num[k1],0x00,sizeof num[k1]);
	for (int i=0;i<10;i++) num[k1][x[i]]+=C[i];
	for (int i=0;i<10;i++) A[k1][i]=x[A[k1][i]];
}
void pushdown(int k1){
	int flag=0;
	for (int i=0;i<10;i++)
		if (A[k1][i]!=i) {flag=1; break;} 
	if (flag){
		add(k1*2,A[k1]); add(k1*2+1,A[k1]);
		for (int i=0;i<10;i++) A[k1][i]=i;
	}
}
void buildtree(int k1,int k2,int k3){
	for (int i=0;i<10;i++) A[k1][i]=i;
	if (k2==k3){
		int now=x[k2],w=1;
		while (now){
			num[k1][now%10]+=w; w*=10; now/=10;
		}
	//	for (int i=0;i<10;i++) cout<<num[k1][i]<<" "; cout<<endl;
		return;
	}
	int mid=k2+k3>>1; 
	buildtree(k1*2,k2,mid);
	buildtree(k1*2+1,mid+1,k3);
	change(k1);
}
void change(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
		add(k1,B); return;
	}
	int mid=k2+k3>>1; pushdown(k1);
	change(k1*2,k2,mid,k4,k5);
	change(k1*2+1,mid+1,k3,k4,k5);
	change(k1);
}
long long find(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4) return 0;
	if (k2>=k4&&k3<=k5){
		long long ans=0;
	//	for (int i=0;i<10;i++) cout<<num[k1][i]<<" "; cout<<endl;
		for (int i=0;i<10;i++) ans+=num[k1][i]*i;
		return ans;
	}
	int mid=k2+k3>>1; pushdown(k1);
	return find(k1*2,k2,mid,k4,k5)+find(k1*2+1,mid+1,k3,k4,k5);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	buildtree(1,1,n);
	for (;m;m--){
		int k1,k2,k3; scanf("%d%d%d",&k1,&k2,&k3);
		if (k1==2) printf("%I64d\n",find(1,1,n,k2,k3));
		else {
			int k4,k5; scanf("%d%d",&k4,&k5);
			for (int i=0;i<10;i++) B[i]=i; B[k4]=k5;
			change(1,1,n,k2,k3);
		}
	}
	return 0;
}