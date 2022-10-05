#include<bits/stdc++.h>
using namespace std;
int n,q;
int base[110000][20];
int num[110000];
long long qow(long long a,long long k,long long mod){
	if(k==0) return 1;
	long long aa=qow(a,k>>1,mod);
	aa=(aa*aa)%mod;
	if(k&1) return (a*aa)%mod;
	return aa;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=0;i<20;i++) base[0][i]=0;
	num[0]=0;
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		for(int j=0;j<20;j++) base[i][j]=base[i-1][j];
		num[i]=num[i-1];
		for(int j=19;j>=0;j--){
			if((a>>j)&1){
				if(base[i][j]) a^=base[i][j];
				else{
					base[i][j]=a;
					num[i]++;
					break;
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int l,x;
		scanf("%d%d",&l,&x);
		for(int j=19;j>=0;j--){
			if((x>>j)&1){
				if(base[l][j]) x^=base[l][j];
				else break;
			}
		}
		if(x) printf("0\n");
		else printf("%lld\n",qow(2,l-num[l],1000000007));
	}
	return 0;
}