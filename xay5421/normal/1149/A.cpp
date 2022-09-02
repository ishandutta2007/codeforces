#include<cstdio>
const int N=200005;
int n,a[N],cnt[3];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),++cnt[a[i]];
	if(cnt[2])printf("%d ",2),--cnt[2];
	if(cnt[1])printf("%d ",1),--cnt[1];
	for(int i=1;i<=cnt[2];++i)printf("%d ",2);
	for(int i=1;i<=cnt[1];++i)printf("%d ",1);
	return 0;
}