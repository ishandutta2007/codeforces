#include<cstring>
#include<cstdio>
#define rep(i,a,b) for (int i=a;i<=b;++i)
using namespace std;
int n,k;
int main() {
	scanf("%d%d",&n,&k);
	rep(i,1,n-k)printf("%d ",i);int cnt=n-k+1;
	int ri=n,le=n-k+1,bo=1; 
	while (cnt<=n) {
		if (bo) printf("%d ",ri--);
		else printf("%d ",le++);
		bo^=1;
		cnt++;
	}
	puts("");
	return 0;
}