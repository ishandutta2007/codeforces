//CF1534B
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
const int N = 444444;
int n,a[N];
int main()
{
	int T,i;
	LL s;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		a[0]=0,a[n+1]=0;
		s=0;
		for(i=1;i<=n;i++)
			if(a[i]>a[i-1]&&a[i]>a[i+1])
				s+=a[i]-max(a[i-1],a[i+1]),a[i]=max(a[i-1],a[i+1]);
		for(i=1;i<=n+1;i++)
			s+=abs(a[i]-a[i-1]);
		printf("%lld\n",s);
	}
	return 0;
}