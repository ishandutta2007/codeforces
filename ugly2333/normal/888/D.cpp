//CF 888D
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
int a[5]={0,0,1,2,9};
int main()
{
	int n,k,i;
	LL s,ans;
	scanf("%d%d",&n,&k);
	s=1;
	ans=1;
	for(i=1;i<=k;i=i+1){
		s*=(LL)(n-i+1);
		s/=(LL)i;
		ans+=(LL)s*a[i];
	}
	cout<<ans<<endl;
	return 0;
}