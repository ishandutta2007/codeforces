#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr int max_n=1000000;
ll a[max_n+1];
int pos[max_n+1],ton[max_n];
int main(){
	int n;
	scanf("%d",&n);
	a[0]=0;
	for(int i=1; i<=n; ++i){
		scanf("%lld",a+i);
		a[i]+=a[i-1];
	}
	memset(ton,-1,sizeof(ton));
	pos[0]=0,ton[0]=0;
	ll sum=0;
	for(int i=1,b; i<=n; ++i){
		scanf("%d",&b);
		sum+=b;
		int p=upper_bound(a+1,a+n+1,sum)-a-1;
		int s=sum-a[p];
		if(ton[s]>=0){
			printf("%d\n",p-pos[ton[s]]);
			for(int i=pos[ton[s]]; ++i<p; printf("%d ",i));
			printf("%d\n",p);
			printf("%d\n",i-ton[s]);
			for(int j=ton[s]; ++j<i; printf("%d ",j));
			printf("%d\n",i);
			return 0;
		}
		ton[s]=i,pos[i]=p;
	}
}