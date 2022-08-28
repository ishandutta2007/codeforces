//CF1119D
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
int n,q;
LL a[N],b[N],f[N];
int main()
{
	int i;
	LL x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%lld",a+i);
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
	for(i=1;i<n;i=i+1)
		b[i]=a[i+1]-a[i]-1;
	sort(b+1,b+n);
	f[0]=n;
	for(i=1;i<n;i=i+1)
		f[i]=f[i-1]+(LL)(n-i+1)*(b[i]-b[i-1]);
	scanf("%d",&q);
	while(q--){
		scanf("%lld%lld",&x,&y);
		y-=x;
		i=upper_bound(b+1,b+n,y)-b-1;
		cout<<f[i]+(LL)(n-i)*(y-b[i])<<endl;
	}
	return 0;
}