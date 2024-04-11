//CF 855B
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int N = 111111;
int a[N];
LL f[N],g[N],ans;
int main()
{
	int n,p,q,r,i;
	scanf("%d%d%d%d",&n,&p,&q,&r);
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		f[i]=(LL)a[i]*p;
		g[i]=(LL)a[i]*r;
	}
	for(i=2;i<=n;i=i+1)
		f[i]=max(f[i],f[i-1]);
	for(i=n-1;i>=1;i=i-1)
		g[i]=max(g[i],g[i+1]);
	ans=f[1]+g[1]+(LL)a[1]*q;
	for(i=1;i<=n;i=i+1)
		ans=max(ans,(LL)a[i]*q+f[i]+g[i]);
	cout<<ans<<endl;
	return 0;
}