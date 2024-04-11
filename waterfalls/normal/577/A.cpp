#include <cstdio>
#include <algorithm>

using namespace std;

int n,x;

int main() {
	scanf("%d%d",&n,&x);
	int ans = 0;
	for (int i=1;i<=n;i++) if (x%i==0 && x/i<=n) ans+=1;
	printf("%d\n",ans);

	return 0;
}