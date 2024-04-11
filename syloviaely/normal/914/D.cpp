#include <bits/stdc++.h>
using namespace std;
int n,m;
int A[510000],num[2100000];
void change(int k1){
	num[k1]=__gcd(num[k1*2],num[k1*2+1]);
}
void buildtree(int k1,int k2,int k3){
	if (k2==k3){
		num[k1]=A[k2]; return;
	}
	int mid=k2+k3>>1;
	buildtree(k1*2,k2,mid);
	buildtree(k1*2+1,mid+1,k3);
	change(k1);
}
void change(int k1,int k2,int k3,int k4,int k5){
	if (k2==k3){
		num[k1]=k5; return;
	}
	int mid=k2+k3>>1;
	if (mid>=k4) change(k1*2,k2,mid,k4,k5);
	else change(k1*2+1,mid+1,k3,k4,k5);
	change(k1);
}
int getne(int k1,int k2,int k3,int k4,int k5){
	//cout<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<" "<<k5<<" "<<num[k1]<<endl;
	if (num[k1]%k5==0) return n+1;
	if (k3<k4) return n+1;
	if (k2==k3) return k2;
	int mid=k2+k3>>1;
	int ans=getne(k1*2,k2,mid,k4,k5);
	if (ans!=n+1) return ans;
	return getne(k1*2+1,mid+1,k3,k4,k5);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	buildtree(1,1,n);
	scanf("%d",&m);
	for (;m;m--){
		int k1,k2,k3; scanf("%d%d%d",&k1,&k2,&k3);
		if (k1==1){
			int k4; scanf("%d",&k4); int r=getne(1,1,n,k2,k4);
			//cout<<r<<endl;
			if (r>=k3){
				printf("YES\n"); continue;
			}
			r=getne(1,1,n,r+1,k4);// cout<<r<<endl;
			if (r>k3){
				printf("YES\n"); continue;
			}
			printf("NO\n");
		} else change(1,1,n,k2,k3);
	}
	return 0;
}