#include<bits/stdc++.h>
using namespace std;
int n,m;
const int max_m=2e5+5;
int a[max_m];
namespace ST
{
	int f[20][max_m],Log[max_m];
	inline void init()
	{
		Log[0]=-1;
		for(int i=1;i<=m;++i)
		{
			Log[i]=Log[i>>1]+1;
			f[0][i]=a[i];
		}
		for(int i=1;i<=Log[m];++i)
			for(int j=1;j+(1<<i)-1<=m;++j)
				f[i][j]=max(f[i-1][j],f[i-1][j+(1<<(i-1))]);
	}
	inline int query(int l,int r)
	{
		assert(l<=r);
		int k=Log[r-l+1];
		return max(f[k][l],f[k][r-(1<<k)+1]);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d",a+i);
	ST::init();
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int xs,ys,xf,yf,k;
		scanf("%d%d%d%d%d",&xs,&ys,&xf,&yf,&k);
		if(xs%k!=xf%k||ys%k!=yf%k)
		{
			puts("NO");
			continue;
		}
		xs+=(n-xs)/k*k;
		if(ST::query(min(ys,yf),max(ys,yf))>=xs)
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}