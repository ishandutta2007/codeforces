#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
void test(){
	int n,mx,mn,mxpos=1,mnpos=1;
	scanf("%d%d",&n,&mx);
	mn=mx;
	for(int i=2; i<=n; ++i){
		int x;
		scanf("%d",&x);
		x>mx&&(mx=x,mxpos=i);
		x<mn&&(mn=x,mnpos=i);
	}
	printf("%d %d\n",mxpos,mnpos);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}