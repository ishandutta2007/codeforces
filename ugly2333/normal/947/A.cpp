//CF 947A
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
int f[1111111];
int main()
{
	int n,i,j,ans;
	cin>>n;
	for(i=2;i<=n;i=i+1)
		if(!f[i])
			for(j=i+i;j<=n;j=j+i)
				f[j]=i;
	ans=n;
	for(i=n-f[n]+1;i<=n;i=i+1){
		ans=min(ans,i-f[i]+1);
	}
	cout<<ans;
	return 0;
}