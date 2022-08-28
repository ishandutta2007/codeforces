//CF 913C
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
int n,l;
LL a[111];
int main()
{
	int i;
	LL s=0,ans;
	cin>>n>>l;
	for(i=1;i<=n;i=i+1){
		cin>>a[i];
		if(i>1)
			a[i]=min(a[i-1]+a[i-1],a[i]);
	}
	for(i=n+1;i<=31;i=i+1)
		a[i]=a[i-1]+a[i-1];
	ans=(LL)3e18;
	for(i=31;i>=1;i=i-1){
		if(i<31)
			a[i]=min(a[i],a[i+1]);
		if(l&(1<<(i-1)))
			s+=a[i];
		ans=min(ans,s+a[i]);
	}
	ans=min(ans,s);
	cout<<ans<<endl;
	return 0;
}