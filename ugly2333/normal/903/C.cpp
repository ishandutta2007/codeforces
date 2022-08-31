//CF 900C
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
int a[5555];
int main()
{
	int n,i,j,ans;
	cin>>n;
	for(i=1;i<=n;i=i+1)
		cin>>a[i];
	sort(a+1,a+n+1);
	ans=0;
	i=1;
	while(i<=n){
		j=i;
		while(j<=n&&a[j]==a[i]){
			j++;
		}
		ans=max(ans,j-i);
		i=j;
	}
	cout<<ans<<endl;
	return 0;
}