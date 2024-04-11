#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int mo1=1e9+7,mo2=1e9+9,key1=1000007,key2=5000009;
int K1[110000],K2[110000];
struct ha{
	int w1,w2,len;
	void add(int k){
		w1=(1ll*w1*key1+k)%mo1;
		w2=(1ll*w2*key2+k)%mo2;
		len++;
	}
	ha operator - (ha k1){
		int k3=(w1-1ll*K1[len-k1.len]*k1.w1%mo1+mo1)%mo1;
		int k2=(w2-1ll*K2[len-k1.len]*k1.w2%mo2+mo2)%mo2;
		return (ha){k3,k2,len-k1.len};
	}
	int operator == (ha k1){
		return w1==k1.w1&&w2==k1.w2;
	}
}A[11][110000];
int x[11][110000],where[11][110000],n,m;
int check(int w,int l){
	for (int i=1;i<=m;i++) if (where[i][w]+l-1>n) return 0;
	ha now=A[1][where[1][w]+l-1]-A[1][where[1][w]-1];
	//cout<<w<<" "<<l<<" "<<now.w1<<" "<<now.w2<<endl;
	for (int i=2;i<=m;i++){
		//ha now2=A[i][where[i][w]+l-1]-A[i][where[i][w]-1];
		//cout<<"fa "<<i<<" "<<now2.w1<<" "<<now2.w2<<endl;
		if (A[i][where[i][w]+l-1]-A[i][where[i][w]-1]==now) continue; else return 0;
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	K1[0]=1; for (int i=1;i<=100000;i++) K1[i]=1ll*K1[i-1]*key1%mo1;
	K2[0]=1; for (int i=1;i<=100000;i++) K2[i]=1ll*K2[i-1]*key2%mo2;
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
			scanf("%d",&x[i][j]); where[i][x[i][j]]=j;
			A[i][j]=A[i][j-1]; A[i][j].add(x[i][j]);
		}
	}
	long long tot=0;
	for (int i=1;i<=n;i++){
		int l=1,r=n+1,ans=0;
		while (l<r){
			int mid=l+r>>1;
			if (check(x[1][i],mid)){
				ans=mid; l=mid+1;
			} else r=mid;
		}
		//cout<<i<<" "<<ans<<endl;
		tot+=ans;
	}
	cout<<tot<<endl;
}