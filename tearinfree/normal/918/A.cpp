#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

int fib[1001],n;
int main() {
	scanf("%d",&n);
	fib[1]=1; fib[2]=2;
	for(int i=3;i<1000;i++) fib[i]=fib[i-1]+fib[i-2];
	
	int j=0;
	for(int i=1;i<=n;i++) {
		while(fib[j]<i) j++;
		if(i==fib[j]) printf("O");
		else printf("o");
	}
	
	return 0;
}