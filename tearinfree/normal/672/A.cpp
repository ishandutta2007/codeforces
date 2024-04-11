#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int main() {
	scanf("%d",&n);
	for(int i=1;i<=1000;i++) {
		int c=0,v=i;
		while(v) c++,v/=10;
		n-=c;
		if(n<=0) {
			n+=c; v=i;
			vector<int> arr;
			while(v) arr.push_back(v%10),v/=10;
			printf("%d\n",arr[c-n]);
			break;
		}
	}
	return 0;
}