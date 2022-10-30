#include <cstdio>
#include <algorithm>

using namespace std;

int x;

int main() {
	scanf("%d",&x);
	int ans = 0;
	for (int i=0;i<30;i++) if (x&(1<<i)) ans+=1;
	printf("%d\n",ans);

	return 0;
}