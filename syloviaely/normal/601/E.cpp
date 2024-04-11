#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int key=1e7+19,mo=1e9+7;
int L[16000],R[16000],w[16000],v[16000],n,K,dp[1010],q[16000],ans[16000],m,a[16000];
void insert(int k1,int k2){
	for (int i=K;i>=k1;i--) dp[i]=max(dp[i],dp[i-k1]+k2);
}
void getans(int k1,int k2,int l,int r){
	if (l>r){
		int num=0;
		for (int i=K;i;i--) num=(1ll*num*key+dp[i])%mo;
	//	cout<<"fa "<<k1<<" "<<k2<<endl;
	//	for (int i=1;i<=K;i++) cout<<dp[i]<<" "; cout<<endl;
		for (int i=k1;i<=k2;i++) ans[i]=num;
		return;
	}
	int pre[1010]; memcpy(pre,dp,sizeof dp); int flag=0;
	int mid=k1+k2>>1; int k3=l;
	for (int i=l;i<=r;i++)
		if (L[a[i]]<=k1&&R[a[i]]>=mid){
		//	cout<<"insert "<<k1<<" "<<mid<<" "<<a[i]<<endl;
			flag=1; insert(w[a[i]],v[a[i]]);
		} else if (L[a[i]]>mid||R[a[i]]<k1) continue;
		else swap(a[k3],a[i]),k3++;
	getans(k1,mid,l,k3-1);
	if (flag) memcpy(dp,pre,sizeof pre);
	k3=l; flag=0;
	for (int i=l;i<=r;i++)
		if (L[a[i]]<=mid+1&&R[a[i]]>=k2){
	//		cout<<"insert "<<mid+1<<" "<<k2<<" "<<a[i]<<endl;
			flag=1; insert(w[a[i]],v[a[i]]);
		} else if (L[a[i]]>k2||R[a[i]]<mid+1) continue;
		else swap(a[k3],a[i]),k3++;
	getans(mid+1,k2,l,k3-1);
	if (flag) memcpy(dp,pre,sizeof pre);
}
int main(){
	scanf("%d%d",&n,&K);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&v[i],&w[i]); L[i]=1;
	}
	memset(R,0xff,sizeof R);
	int now=0; scanf("%d",&m);
	for (int i=1;i<=m;i++){
		int k1; scanf("%d",&k1);
		if (k1==1){
			n++; scanf("%d%d",&v[n],&w[n]); L[n]=now+1;
		} else if (k1==2){
			int k2; scanf("%d",&k2); R[k2]=now;
		} else if (k1==3) now++;
	}
	for (int i=1;i<=n;i++) if (R[i]==-1) R[i]=now;
//	for (int i=1;i<=n;i++) cout<<L[i]<<" "<<R[i]<<" "<<w[i]<<" "<<v[i]<<endl;
	for (int i=1;i<=n;i++) a[i]=i;
	getans(1,now,1,n);
	for (int i=1;i<=now;i++) printf("%d\n",ans[i]);
	return 0;
}