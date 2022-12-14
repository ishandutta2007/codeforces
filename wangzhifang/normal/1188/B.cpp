#include <map>
#include <cstdio>
using namespace std;
map<int,int> mp;
int main(){
	int n,p,k,ans=0;
	scanf("%d%d%d",&n,&p,&k);
	for(; n; --n){
		long long x,y;
		scanf("%lld",&x);
		y=x*x%p;
		ans+=mp[(y*y-x*k%p+p)%p]++;
	}
	printf("%d",ans);
	return 0;
}