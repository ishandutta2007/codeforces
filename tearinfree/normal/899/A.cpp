#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int n;
int main() {
	int a=0,b=0,val;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d",&val);
		if(val==1) a++;
		else b++;
	}
	
	int res=min(a,b);
	a-=min(a,b);
	res+=a/3;
	printf("%d\n",res);

	return 0;
}