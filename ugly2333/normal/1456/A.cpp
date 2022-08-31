//CF1456A
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 111111;
int n,p,k,x,y,a[N],b[N],c[N];
char s[N];
int main()
{
	int T,i,ans;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%s%d%d",&n,&p,&k,s+1,&x,&y);
		for(i=1;i<=n;i=i+1)
			a[i]=(s[i]=='0');
		for(i=0;i<k;i=i+1)
			b[i]=0,c[i]=0;
		for(i=1;i<=n;i=i+1)
			b[i%k]+=a[i];
		for(i=1;i<p;i=i+1)
			c[i%k]+=a[i];
		ans=2e9;
		for(i=p;i<=n;i=i+1){
			ans=min(ans,(i-p)*y+(b[i%k]-c[i%k])*x);
			c[i%k]+=a[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}