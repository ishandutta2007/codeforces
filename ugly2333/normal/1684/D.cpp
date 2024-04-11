//CF1684C
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
const int N = 222222;
int n,k,a[N],b[N];
int main()
{
	int T,i;
	LL s,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		x=0;
		for(i=1;i<=n;i++)
			scanf("%d",a+i),b[i]=a[i]+i-1,x+=a[i];
		sort(b+1,b+n+1);
		reverse(b+1,b+n+1);
		s=x;
		for(i=1;i<=k;i++){
			x+=n-i;
			x-=b[i];
			s=min(s,x);
		}
		printf("%lld\n",s);
	}
	return 0;
}