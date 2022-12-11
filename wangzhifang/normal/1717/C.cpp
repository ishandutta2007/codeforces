#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
constexpr int max_n=200000;
int a[max_n+1],b[max_n+1];
void test(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	for(int i=1; i<=n; ++i)
		scanf("%d",b+i);
	for(int i=1; i<=n; ++i)
		if(b[i]<a[i]||a[i]<b[i]&&b[i%n+1]<b[i]-1){
			puts("NO");
			return;
		}
	puts("YES");
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}