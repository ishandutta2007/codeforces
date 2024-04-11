#include<cstring>
#include<cstdio>
#include<algorithm>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define N 100005
using namespace std;
int n,k,cnt[N],sum[N],m,q[N],r[N],l[N],a[N];
bool work(int x) {
	memset(cnt,0,sizeof cnt);memset(sum,0,sizeof sum);
	rep(i,1,m) if (q[i]>>(x-1)&1) cnt[l[i]]++,cnt[r[i]+1]--;
	rep(i,1,n) cnt[i]+=cnt[i-1],sum[i]=sum[i-1]+(cnt[i]==0),a[i]|=(cnt[i]!=0)<<(x-1);
	rep(i,1,m) if (!(q[i]>>(x-1)&1)&&sum[r[i]]-sum[l[i]-1]==0) return 0;
	return 1;
}
int main() {
	scanf("%d%d",&n,&m);rep(i,1,m)scanf("%d%d%d",&l[i],&r[i],&q[i]);
	rep(i,1,30) if(!work(i)) return puts("NO"),0;puts("YES");
	rep(i,1,n) printf("%d ",a[i]);puts("");
	return 0;
}