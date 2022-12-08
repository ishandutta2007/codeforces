#include<cstring>
#include<cstdio>
#include<algorithm>
#define pii pair<int,int>
#define mp make_pair
#define N 10005
#define X first
#define Y second
#define M 200005
using namespace std;
pii b[M],a[N];
int cnt=0,n;
void work(int l,int r) {
	int m=(l+r)>>1,nx=a[m].X;
	for (int i=l;i<=r;++i) b[++cnt]=mp(nx,a[i].Y);
	if (l<m) work(l,m-1);
	if (m<r) work(m+1,r);
}

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d%d",&a[i].X,&a[i].Y);
	sort(a+1,a+n+1);work(1,n);
	sort(b+1,b+cnt+1);int len=unique(b+1,b+cnt+1)-(b+1);
	printf("%d\n",len);
	for (int i=1;i<=len;++i) printf("%d %d\n",b[i].X,b[i].Y);
	return 0;
}