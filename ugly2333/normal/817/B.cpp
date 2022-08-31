// CF 817B
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
	int n,i,j;
	LL ans;
	cin>>n;
	for(i=1;i<=n;i=i+1)
		cin>>a[i];
	sort(a+1,a+n+1);
	j=3;
	while(j+1<=n&&a[j]==a[j+1]){
		j++;
	}
	if(a[1]==a[2]){
		if(a[2]==a[3]){
			ans=(LL)j*(j-1)*(j-2);
			ans/=(LL)6;
		}
		else
			ans=j-2;
	}
	else{
		if(a[2]==a[3]){
			ans=(LL)(j-1)*(j-2);
			ans/=(LL)2;
		}
		else
			ans=j-2;
	}
	cout<<ans<<endl;
	return 0;
}