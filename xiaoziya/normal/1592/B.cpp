#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=100005;
int T,n,m;
int a[maxn],b[maxn];
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m);
		int flg=1;
		for(int i=1; i<=n; i++) {
			scanf("%d",&a[i]),b[i]=a[i];
			if(i>1)
				flg&=(a[i]>=a[i-1]);
		}
		sort(b+1,b+1+n);
		if(flg==1) {
			puts("YES");
			continue;
		}
		if(2*m-1<n) {
			puts("YES");
			continue;
		}
		flg=1;
		for(int i=max(1,n-m+1); i<=min(n,m); i++)
			if(a[i]!=b[i])
				flg=0;
		puts(flg==0? "NO":"YES");
	}
	//please
	return 0;
}
////