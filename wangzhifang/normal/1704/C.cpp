#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr int max_m=100000;
int a[max_m+1];
void test(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
		scanf("%d",a+i);
	sort(a+1,a+m+1);
	a[0]=a[m]-n;
	for(int i=m; i; --i)
		a[i]-=a[i-1]+1;
	sort(a+1,a+m+1);
	int t=0,sum=0;
	for(int i=m; i; --i){
		const int r=a[i]-t*2;
		if(r<=0)
			break;
		if(r<=2){
			++sum,++t;
			continue;
		}
		sum+=r-1,t+=2;
	}
	printf("%d\n",n-sum);
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}