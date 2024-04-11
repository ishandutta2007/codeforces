#include<iostream>
#include<cmath>
using namespace std;

int ans(int n,int m){
	int mod=1;
	for (int i=1;i<=n;++i){
		mod*=2;
		if (mod>m) return m;
	}
	return m%mod;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d\n",ans(n,m));
}