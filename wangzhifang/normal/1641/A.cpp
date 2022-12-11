#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef const int& ci;
constexpr int max_n=200000;
int a[max_n+1];
void test(){
	int n,ans=0;
	long long k;
	scanf("%d%lld",&n,&k);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(int i=1,j=2; i<=n; ++i){
		if(!a[i])
			continue;
		while(j<=n&&a[i]*k>a[j])
			++j;
		if(j<=n&&a[i]*k==a[j]){
			a[j]=0;
			continue;
		}
		++ans;
	}
	printf("%d\n",ans);
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}