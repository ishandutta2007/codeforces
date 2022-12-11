#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr int max_n=200000;
int a[max_n+1];
void test(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(int i=1,j=1; j<=n; ++i){
		while(a[j]-a[i]<k)
			if(++j>n){
				puts("NO");
				return;
			}
		if(a[j]-a[i]==k){
			puts("YES");
			return;
		}
	}
	puts("NO");
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}