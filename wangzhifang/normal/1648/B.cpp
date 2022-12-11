#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr int max_n=1000000;
int a[max_n+1];
void test(){
	int n,c;
	scanf("%d%d",&n,&c);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
	c=a[n];
	if(a[1]!=1){
		puts("No");
		return;
	}
	for(int i=1; i<=n; ++i){
		int lst=i;
		for(int j=1; lst<n&&j<=n&&ll(a[i])*a[j]<=c; ++j){
			if(a[lst+1]/a[i]>a[j])
				continue;
			if(a[lst+1]/a[i]<a[j]){
				puts("No");
				return;
			}
			lst=lower_bound(a+1,a+n+1,a[i]*(a[j]+1))-a-1;
		}
		if(lst<n){
			puts("No");
			return;
		}
	}
	puts("Yes");
}
int main(){
//	test();
	int t;
	scanf("%d",&t);
	for(; t; test(),--t);
	return 0;
}