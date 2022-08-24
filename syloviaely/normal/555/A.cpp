#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,A[110000];
int main(){
	scanf("%d%d",&n,&k); int ans=(n-k)+n+1;
	for (;k;k--){
		int k1; scanf("%d",&k1);
		for (int i=1;i<=k1;i++) scanf("%d",&A[i]);
		if (A[1]==1){
			for (int i=1;i<=k1;i++) if (A[i]==i) ans-=2; else break;
		}
	}
	printf("%d\n",ans);
	return 0;
}