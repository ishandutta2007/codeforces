#include <cstdio>
#include <algorithm>
const int MAXN=100005;

int n,A,B,ans,a[MAXN],s[MAXN];

bool check(int x){
	return 1ll*a[1]*A>=1ll*B*s[n-x];
}

int main(){
	scanf("%d%d%d",&n,&A,&B);
	for (int i=1;i<=n;i++) scanf("%d",a+i);
	std::sort(a+2,a+1+n);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int L=0,R=n-1;
	while (L<=R){
		int mid=(R-L>>1)+L;
		if (check(mid)) R=mid-1,ans=mid;
		else L=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}