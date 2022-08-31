//CF1394A
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
int n,d,m,a[N];
LL s[N];
int main()
{
	int i,j,x;
	LL ans;
	scanf("%d%d%d",&n,&d,&m);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	s[0]=0;
	for(i=1;i<=n;i=i+1)
		s[i]=s[i-1]+a[i];
	for(j=0;j<=n;j=j+1)
		if(a[j+1]<=m)
			break;
	ans=s[n]-s[j];
	for(i=1;i<=n;i=i+1){
		x=n-(i-1)*(d+1)-1;
		if(x<0||a[i]<=m)
			break;
		ans=max(ans,s[i]+s[min(j+x,n)]-s[j]);
	}
	cout<<ans;
	return 0;
}