#include <cmath>
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
	k<<=1;
	int cnt=0,mn=a[1],mx=a[1];
	for(int i=2; i<=n; ++i){
		if(a[i]<mn)
			mn=a[i];
		if(a[i]>mx)
			mx=a[i];
		if(mx-mn>k){
			++cnt;
			mn=a[i],mx=a[i];
		}
	}
	printf("%d\n",cnt);
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}