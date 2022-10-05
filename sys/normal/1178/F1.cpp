#include <bits/stdc++.h>
using namespace std;
const int Maxn=505,p=998244353;
long long vis[Maxn][Maxn]; 
int n,m,a[Maxn];
long long work(int lt,int rt)
{
	if(lt==rt+1) return 1;
	int mini=0;
	if(lt==rt) return 1;
	if(vis[lt][rt]) return vis[lt][rt];
	for(int i=lt;i<=rt;i++)
		mini=a[mini]>a[i]?i:mini;
	long long tot1=0,tot2=0;
	for(int i=lt;i<=mini;i++)
		tot1+=work(lt,i-1)*work(i,mini-1)%p,tot1%=p;
	for(int i=mini;i<=rt;i++)
		tot2+=work(mini+1,i)*work(i+1,rt)%p,tot2%=p;
	return vis[lt][rt]=tot1*tot2%p;
}
int main()
{
	a[0]=0x3f3f3f3f;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	printf("%lld",work(1,n));
	return 0;
}