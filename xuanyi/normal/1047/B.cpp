#include <cstdio>
#include <algorithm>

const int MAXN=100005;

int n,ans;
int x[MAXN],y[MAXN];

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	    scanf("%d%d",&x[i],&y[i]),ans=std::max(ans,x[i]+y[i]);
	printf("%d\n",ans);
	return 0;
}