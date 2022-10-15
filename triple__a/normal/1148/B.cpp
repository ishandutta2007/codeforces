#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn=200007;
int main(){
	int n,m,k,ta,tb,ans=0;
	int a[maxn],b[maxn];
	scanf("%d%d%d%d%d",&n,&m,&ta,&tb,&k);
	for (int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	for (int i=0;i<m;++i){
		scanf("%d",&b[i]);
	}
	if (n<=k){
		printf("-1");
		return 0;
	}
	for (int i=0;i<=k;++i){
		int key=a[i]+ta,p=lower_bound(b,b+m,key)-b;
		if (p+k-i>=m){
			printf("-1");
			return 0;
		}
		ans=max(ans,b[p+k-i]+tb);
	}
	printf("%d\n",ans);
	return 0;
}