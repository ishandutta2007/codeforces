//CF 956C
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
typedef double DB;
const int N = 1e5+15;
int n,a[N],b[N];
int main()
{
	int i;
	LL ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i),b[i]=max(a[i]+1,b[i-1]);
	for(i=n;i>1;i=i-1)
		b[i-1]=max(b[i-1],b[i]-1);
	for(i=1;i<=n;i=i+1)
		ans+=(LL)b[i]-a[i]-1;
	cout<<ans;
	return 0;
}