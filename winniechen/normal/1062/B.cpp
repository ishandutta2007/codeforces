#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
// #define N 105
int n,ans,mx,mn;
int main()
{
	scanf("%d",&n);
	if(n==1)return puts("1 0"),0;
	ans=1,mx=0,mn=1<<30;
	for(int i=2;i*i<=n;i++) {
		if(n%i==0) {
			ans*=i;
			int cnt=0;
			while(n%i==0) n/=i,cnt++;
			mx=max(mx,cnt);
			mn=min(mn,cnt);
		}
	}
	if(n!=1) ans*=n,mn=min(mn,1),mx=max(mx,1);
	printf("%d ",ans);
	int ans2=0;

	int x=1;
	while(x<mx) x<<=1,ans2++;
	if(mn!=mx||mx!=x) ans2++;
	printf("%d\n",ans2);
}