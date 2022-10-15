#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=100007;
LL a[maxn],b[maxn],ans;
int n,m;

LL solve(int n,int m,LL a[],LL b[]){
	if (a[n]>b[1]){
		return -1;
	}
	LL ans=0;
	for (int i=1;i<=n-1;++i){
		ans+=a[i]*m;
	}
	if (b[1]!=a[n]){ 
		ans+=a[n]+b[1]-a[n-1];
	}
	else{
		ans+=a[n];
	}
	for (int i=2;i<=m;++i){
		ans+=b[i];
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=m;++i){
		scanf("%d",&b[i]);
	}
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	printf("%lld\n",solve(n,m,a,b));	
	return 0;
}