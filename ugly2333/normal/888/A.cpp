//CF 888A
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
int a[111111];
int main()
{
	int n,i,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	ans=0;
	for(i=2;i<n;i=i+1){
		if(a[i-1]>a[i]&&a[i]<a[i+1])
			ans++;
		if(a[i-1]<a[i]&&a[i]>a[i+1])
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}