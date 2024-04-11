#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
long long A[1100000],B[1100000];
int n,where[1100000],pre[1100000],flag;
void print(int k1,int k2,int k3,int k4){
	if (flag){
		swap(k1,k3); swap(k2,k4);
	}
	printf("%d\n",k2-k1+1);
	for (int i=k1;i<=k2;i++) printf("%d ",i); printf("\n");
	printf("%d\n",k4-k3+1);
	for (int i=k3;i<=k4;i++) printf("%d ",i); printf("\n");
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%I64d",&A[i]); A[i]+=A[i-1];
	}
	for (int i=1;i<=n;i++){
		scanf("%I64d",&B[i]); B[i]+=B[i-1];
	}
	if (B[n]<A[n]){
		flag=1;
		for (int i=1;i<=n;i++) swap(A[i],B[i]);
	}
	memset(pre,0xff,sizeof pre);
	pre[0]=0; where[0]=0;
	int now=1;
	for (int i=1;i<=n;i++){
		while (B[now]<A[i]) now++;
		int num=B[now]-A[i];
		if (pre[num]!=-1){
			print(pre[num]+1,i,where[pre[num]]+1,now);
			return 0;
		}
		pre[num]=i; where[i]=now;
	}
	return 0;
}