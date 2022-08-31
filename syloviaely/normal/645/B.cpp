#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,K;
int main(){
	scanf("%d%d",&n,&K);
	K=min(K,n/2);
	long long ans=0;
	for (int i=1;i<=K;i++){
		int l=i,r=n-i+1; ans+=r-l+r-l-1;
	}
	cout<<ans<<endl;
	return 0;
}