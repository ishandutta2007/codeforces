#include <cstdio>
using namespace std;
int main(){
	int n,x;
	long long cnt1,cnt2,ans;
	scanf("%d",&n),cnt1=ans=0;
	for(++n; --n; cnt1>=cnt2?ans+=cnt2,cnt1-=cnt2:((ans+=(cnt1+=2*cnt2)/3)&&(cnt1%=3))){
		scanf("%d",&x);
		cnt1+=(x&1),cnt2=(x>>1);
	}
	printf("%lld\n",ans);
	return 0;
}