#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;;i++) {
		int f=0;
		for(int j=1;j<n;j++) {
			int val;
			val=min(a/j,b/(n-j));
			if(val>=i) {
				f=1;
				break;
			}
		}
		if(!f) {
			printf("%d\n",i-1);
			break;
		}
	}
	return 0;
}