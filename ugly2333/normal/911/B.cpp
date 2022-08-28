//CF 911B
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
int main()
{
	int n,a,b,i,ans=0;
	cin>>n>>a>>b;
	for(i=1;i<=a&&i<n;i=i+1)
		ans=max(ans,min(a/i,b/(n-i)));
	cout<<ans<<endl;
	return 0;
}