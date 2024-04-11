#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,K,d1,d2,m,A[210000],B[210000],w[210000];
void add(int *A,int k1,int k2){
	for (;k1<=n;k1+=k1&(-k1)) A[k1]+=k2;
}
int find(int *A,int k1){
	int ans=0; for (;k1;k1-=k1&(-k1)) ans+=A[k1]; return ans;
}
int main(){
	scanf("%d%d%d%d%d",&n,&K,&d1,&d2,&m);
	memset(A,0x00,sizeof A);
	memset(B,0x00,sizeof B);
	int tot=0;
	for (;m;m--){
		int k1,k2; scanf("%d%d",&k1,&k2);
		if (k1==1){
			int k3; scanf("%d",&k3);
			int pre=w[k2];
			add(A,k2,-min(w[k2],d2));
			add(B,k2,-min(w[k2],d1));
			w[k2]+=k3;
			add(A,k2,min(w[k2],d2));
			add(B,k2,min(w[k2],d1));
		} else if (k1==2){
			int l=k2-1,r=min(k2+K,n+1),ans=find(A,l);
			if (r<=n) ans+=find(B,n)-find(B,r-1);
			printf("%d\n",ans);
		}
	}
	return 0;
}