#include <cstdio>
using namespace std;
int main(){
	int n,prv;
	scanf("%d%d",&n,&prv);
	long long ans=prv*(long long)(n-prv+1);
	for(int i=n,x,a,b; --i; ans+=x*(long long)(n-x+1)-a*(long long)(n-b+1),prv=x){
		scanf("%d",&x);
		x>prv?(a=prv,b=x):(a=x,b=prv);
	}
	printf("%lld\n",ans);
	return 0;
}