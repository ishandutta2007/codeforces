#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define N 5000
using namespace std;
int n,m,a[N],cnt,mn,mx;
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i) {
		int x;
		scanf("%d",&x);
		if (x==1) {
			int xx,yy;
			scanf("%d%d",&xx,&yy);
			a[++cnt]=xx,a[++cnt]=yy;
			mn+=2;
		}
		else {
			int xx;
			scanf("%d",&xx);
			a[++cnt]=xx;
			mn++;
		}
	}
	a[++cnt]=n;
	sort(a+1,a+cnt+1);
	for (int i=1;i<n;++i) if (a[i]-a[i-1]>1) mx+=(a[i]-a[i-1])/2;
	mn=n-1-mn;
	printf("%d %d\n",mx,mn);
}