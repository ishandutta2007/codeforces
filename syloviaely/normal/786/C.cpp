#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int pre[110000],x[110000];
int num[410000],n,A[110000];
int ans[110000];
vector<int>y[110000],B[110000];
void add(int k1,int k2,int k3,int k4,int k5){
	num[k1]+=k5;
	if (k2==k3) return;
	int mid=k2+k3>>1;
	if (mid>=k4) add(k1*2,k2,mid,k4,k5); else add(k1*2+1,mid+1,k3,k4,k5);
}
int find(int k1,int k2,int k3,int k4){
	if (k2==k3) return k2; int mid=k2+k3>>1;
	if (num[k1*2]>=k4) return find(k1*2,k2,mid,k4); else return find(k1*2+1,mid+1,k3,k4-num[k1*2]);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x[i]);
		pre[i]=A[x[i]]; A[x[i]]=i;
	}
	for (int i=1;i<=n;i++) y[pre[i]].push_back(i),B[1].push_back(i);
	for (int now=1;now<=n;now++){
		for (int i=0;i<y[now-1].size();i++) add(1,1,n+1,y[now-1][i],1);
		for (int i=0;i<B[now].size();i++){
			int ne=find(1,1,n+1,B[now][i]+1);
	//		cout<<"asd "<<B[now][i]<<" "<<now<<" "<<ne<<endl;
			B[ne].push_back(B[now][i]); ans[B[now][i]]++;
		}
		add(1,1,n+1,now,-1);
	}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]); printf("\n");
	return 0;
}