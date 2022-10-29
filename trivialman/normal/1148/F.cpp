#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const int N = 300010;

LL val[N], mask[N], sum=0, ans=0, n;

int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld%lld",val+i,mask+i);
	rep(i,1,n)sum+=val[i];
	if(sum<0){
		sum = -sum;
		rep(i,1,n)val[i]=-val[i];
	}
	rep(i,0,61){
		LL b=0,pwi=(1ll<<i);
		rep(j,1,n)if(mask[j]==pwi)b+=val[j];
		if(b>0){
			rep(j,1,n)if(pwi&mask[j]){
				sum -= (val[j]<<1);
				val[j] = -val[j];
			}
			ans |= pwi;
			if(sum<0)break;
		}
		rep(j,1,n)if(mask[j]&pwi)mask[j]-=pwi;
	}
	printf("%lld\n",ans);
	return 0;
}