#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int w[1100000],K,n,q,size[1100000],miu[1100000];
const int mo=1e9+7,N=200000,lim=1000000;
int nI[210000],I[210000],ans;
vector<int>d[1100000];
int quick(int k1,int k2){
	int k3=1;
	while (k2){
		if (k2&1) k3=1ll*k3*k1%mo; k2>>=1; k1=1ll*k1*k1%mo;
	}
	return k3;
}
int C(int k1,int k2){
	if (k1<k2) return 0;
	return 1ll*I[k1]*nI[k2]%mo*nI[k1-k2]%mo;
}
void add(int k1){
	for (int i=0;i<d[k1].size();i++){
		int k2=d[k1][i]; int pre=C(size[k2],K),now=C(size[k2]+1,K); size[k2]++;
	//	cout<<"insert "<<k1<<" "<<k2<<" "<<pre<<" "<<now<<" "<<size[k2]<<endl;
		ans=(ans+1ll*(now-pre)*w[k2])%mo;
	}
}
int main(){
	scanf("%d%d%d",&n,&K,&q);
	I[0]=1; for (int i=1;i<=N;i++) I[i]=1ll*I[i-1]*i%mo;
	for (int i=0;i<=N;i++) nI[i]=quick(I[i],mo-2);
//	for (int i=0;i<=10;i++) cout<<I[i]<<" "<<nI[i]<<endl;
	for (int i=1;i<=lim;i++)
		for (int j=i;j<=lim;j+=i) d[j].push_back(i);
	for (int i=1;i<=lim;i++){
		if (i==1) miu[i]=1;
		for (int j=i*2;j<=lim;j+=i) miu[j]-=miu[i];
	}
	for (int i=1;i<=lim;i++)
		for (int j=i;j<=lim;j+=i) w[j]=(w[j]+1ll*i*miu[j/i])%mo;
//	for (int i=1;i<=10;i++) cout<<miu[i]<<" "; cout<<endl;
//	for (int i=1;i<=10;i++) cout<<w[i]<<" "; cout<<endl;
	for (int i=1;i<=n;i++){
		int k1; scanf("%d",&k1); add(k1);// cout<<ans<<endl;
	}
	for (int i=1;i<=q;i++){
		int k1; scanf("%d",&k1); add(k1); printf("%d\n",(ans+mo)%mo);
	}
	return 0;
}