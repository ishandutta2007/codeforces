#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

typedef long long LL;

const int maxn=300007;
int n,a[maxn];
LL b[maxn];
bool ck[maxn];
LL ret=0;

int main(){
	memset(ck,0,sizeof(ck));
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d%lld",&a[i],&b[i]);
	}
	LL ans=0;
	for (int i=1;i<=n;++i){
		ans+=a[i];
	}
	if (ans>0){
		for (int i=1;i<=n;++i){
			a[i]=-a[i];
		} 
	}
	for (int i=0;i<62;++i){
		ans=0;
		for (int j=1;j<=n;++j){
			if (b[j]==1){
				ans+=a[j];
			}
		}
		if (ans<0){
			ret+=(1LL<<i);
			for (int j=1;j<=n;++j){
				if (b[j]&1){
					a[j]=-a[j];
				}
			}
		}
		for (int j=1;j<=n;++j){
			b[j]>>=1;
		}
	}
	printf("%lld\n",ret);
	return 0;
}