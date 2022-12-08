#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,X,sum;
int main() {
	scanf("%d%d",&n,&X);
	for (int i=1;i<=n;++i) {
		int x;
		scanf("%d",&x);
		sum+=x;
	}
	int m=abs(sum)/X;
	if (sum%X==0) printf("%d\n",m);else printf("%d\n",m+1);
	return 0;
	
}