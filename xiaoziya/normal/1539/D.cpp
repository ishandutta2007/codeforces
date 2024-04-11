#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=100005;
int n;
int id[maxn];
__int128 ans,sum;
long long a[maxn],b[maxn];
inline int cmp(int x,int y){
	return b[x]>b[y];
}
void print(__int128 x){
	if(x>9)
		print(x/10);
	putchar(x%10+48);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&a[i],&b[i]),ans+=a[i]*2,sum+=a[i],id[i]=i;
	sort(id+1,id+1+n,cmp);
	for(int i=1;i<=n;i++){
		__int128 lst=sum;
		int x=id[i];
		if(sum-a[x]>=b[x])
			sum-=a[x];
		else sum=min(sum,(__int128)b[x]);
		ans-=lst-sum;
	}
	print(ans);
	return 0;
}