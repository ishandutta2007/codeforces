#include <cstdio>
#include <algorithm>

using namespace std;

int n,m,a[100000],b[100000];

int main() {
	scanf("%d%d",&n,&m);
	int mn=1,mx=n;
	for(int i=0;i<m;i++) {
		scanf("%d%d",a+i,b+i);
		if(a[i]>b[i]) swap(a[i],b[i]);
		mn=max(mn,a[i]), mx=min(mx,b[i]);
	}
	if(mn>=mx) printf("0\n");
	else printf("%d\n",mx-mn);
	return 0;
}