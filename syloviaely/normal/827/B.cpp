#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,K;
int main(){
	scanf("%d%d",&n,&K);
	int fir=1; int ans=0;
	for (int i=0;i<n-1;i++)
		if (i%K==0) ans++; else if (i%K==1) ans++;
	printf("%d\n",ans);
	for (int i=2;i<=n;i++) printf("%d %d\n",max(i-K,1),i);
}