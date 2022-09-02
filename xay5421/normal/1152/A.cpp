#include<cstdio>
#include<algorithm>
const int N=100005;
int n,m,a[N],b[N],cnt,sum;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",a+i),cnt+=a[i]&1;
	for(int i=1;i<=m;++i)scanf("%d",b+i),sum+=!(b[i]&1);
	printf("%d\n",std::min(cnt,sum)+std::min(n-cnt,m-sum));
	return 0;
}