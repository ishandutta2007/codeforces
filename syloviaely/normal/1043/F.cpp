#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const int N=310000;
vector<int> go[N];
int A[N],B[N],w1[N],w2[N],mu[N],n;
const int M=300000;
int quick(int k1,int k2,int mo){
	int k3=1;
	while (k2){
		if (k2&1) k3=1ll*k3*k1%mo; k2>>=1; k1=1ll*k1*k1%mo;
	}
	return k3;
}
int check(int mo,int l,int *w){
	int inv=quick(l,mo-2,mo);
	for (int i=1;i<=M;i++) w[i]=1ll*w[i]*(A[i]-l+1)%mo*inv%mo;
	int ans=0;
	for (int i=1;i<=M;i++) ans=(ans+mu[i]*w[i])%mo;
	return ans;
}
int main(){
	for (int i=1;i<=M;i++){
		if (i==1) mu[i]=1;
		for (int j=i+i;j<=M;j+=i) mu[j]-=mu[i];
		for (int j=i;j<=M;j+=i) go[j].pb(i);
	}
	//for (int i=1;i<=10;i++) cout<<mu[i]<<" "; cout<<endl;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int k1; scanf("%d",&k1);
		for (int j=0;j<go[k1].size();j++) A[go[k1][j]]++;
	}
	for (int i=1;i<=M;i++) w1[i]=w2[i]=1;
	for (int i=1;i<=19;i++)
		if (check(1000000007,i,w2)&&check(1000000009,i,w1)){
			printf("%d\n",i); return 0;
		}
	puts("-1");
	return 0;
}