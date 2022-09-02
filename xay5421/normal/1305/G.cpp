#include<cstdio>
#include<cassert>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
const int N=262150;
int n,a[N],b[N],fa[N],sz[N];
LL ans;
int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
int mer(int k1,int k2){
	if((k1=fd(k1))==(k2=fd(k2)))return 0;
	int res=(sz[k1]==1?b[k1]:1)+(sz[k2]==1?b[k2]:1)-1;
	if(sz[k1]>sz[k2])sz[k1]+=sz[k2],fa[k2]=k1;
	else sz[k2]+=sz[k2],fa[k1]=k2;
	return res;
}
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]),ans-=a[i],++b[a[i]];
	for(i=0;i<N;++i)fa[i]=i,sz[i]=1;
	for(++b[0],i=N-1;i>=1;--i)for(j=i;j>(i^j);--j&=i)if(b[j]&&b[i^j])ans+=1LL*i*mer(j,i^j);
	printf("%lld\n",ans);
	return 0;
}