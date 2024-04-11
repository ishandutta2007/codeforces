#include<cstdio>
#include<algorithm>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N=300005;
int n,m,a[N],b[N];
bool chk(int x){
	for(int i=1;i<=n;++i)b[i]=a[i];
	for(int i=1;i<=n;++i){
		if(b[i]<b[i-1]){
			if(b[i]+x>=b[i-1]){
				b[i]=b[i-1];
			}
		}else{
			b[i]=min(b[i],(b[i]+x>=m&&(b[i]+x)%m>=b[i-1])?b[i-1]:0x3f3f3f3f);
		}
		if(b[i]<b[i-1])return 0;
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	int l=0,r=m,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(chk(mid)){
			r=mid-1,ans=mid;
		}else{
			l=mid+1;
		}
	}
	printf("%d\n",ans);
	return 0;
}