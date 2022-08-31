#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int pd[160000],A[160000],n;
vector<int>where;
int check(int k1,int k2){
	if (k1>k2) swap(k1,k2);
	swap(A[k1],A[k2]); int flag=0;
	for (int i=0;i<where.size();i++){
		int k1=where[i];
		if (k1%2==1){
			if (k1>1&&A[k1]>=A[k1-1]) flag=1;
			if (k1<n&&A[k1]>=A[k1+1]) flag=1;
		} else {
			if (k1>1&&A[k1]<=A[k1-1]) flag=1;
			if (k1<n&&A[k1]<=A[k1+1]) flag=1;
		}
	}
	for (int i=max(k1-1,1);i<=min(k1+1,n);i++){
		int k1=i;
		if (k1%2==1){
			if (k1>1&&A[k1]>=A[k1-1]) flag=1;
			if (k1<n&&A[k1]>=A[k1+1]) flag=1;
		} else {
			if (k1>1&&A[k1]<=A[k1-1]) flag=1;
			if (k1<n&&A[k1]<=A[k1+1]) flag=1;
		}
	}
	for (int i=max(k2-1,1);i<=min(k2+1,n);i++){
		int k1=i;
		if (k1%2==1){
			if (k1>1&&A[k1]>=A[k1-1]) flag=1;
			if (k1<n&&A[k1]>=A[k1+1]) flag=1;
		} else {
			if (k1>1&&A[k1]<=A[k1-1]) flag=1;
			if (k1<n&&A[k1]<=A[k1+1]) flag=1;
		}
	}
	swap(A[k1],A[k2]);
	if (flag==0) return 1; else return 0;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	for (int i=1;i<n;i++){
		if (i%2==1&&A[i]>=A[i+1]) pd[i]=1,pd[i+1]=1;
		if (i%2==0&&A[i]<=A[i+1]) pd[i]=1,pd[i+1]=1;
	}
	for (int i=1;i<=n;i++) if (pd[i]) where.push_back(i);
	if (where.size()>10){
		printf("0\n"); return 0;
	}
	int ans=0;
	for (int i=0;i<where.size();i++)
		for (int j=1;j<=n;j++)
			if (pd[j]==0||(pd[j]==1&&j<where[i])) ans+=check(where[i],j);
	printf("%d\n",ans);
	return 0;
}