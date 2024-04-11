//CCF 911A
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
const int N = 111111;
int n,a[N],mn;
int main()
{
	int i,j,ans;
	mn=1e9;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i),mn=min(mn,a[i]);
	j=0;
	ans=N;
	for(i=1;i<=n;i=i+1)
		if(a[i]==mn){
			if(j)
				ans=min(ans,i-j);
			j=i;
		}
	cout<<ans<<endl;
	return 0;
}