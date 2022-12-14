//*

#include<stdio.h>
#include<algorithm>
#define MOD 1000000007
#pragma warning(disable:4996)

using namespace std;

long long a,b,ans;

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	int i;
	scanf("%lld%lld",&a,&b);
	for(i=1;i<b;i++){
		ans+=((((a+1)*a/2)%MOD*i)%MOD*b)%MOD+(i*a)%MOD;
		ans%=MOD;
	}
	printf("%lld",ans);
	return 0;
}

//*/