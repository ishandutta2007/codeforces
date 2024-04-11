//CF 779C
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
int x[200005];
int main()
{
	int n,k,i,ans;
	cin>>n>>k;
	ans=0;
	for(i=1;i<=n;i=i+1){
		cin>>x[i];
		ans=ans+x[i];
	}
	for(i=1;i<=n;i=i+1){
		cin>>x[0];
		x[i]=x[0]-x[i];
	}
	sort(x+1,x+n+1);
	for(i=1;i<=n-k&&x[i]<0;i=i+1)
		ans=ans+x[i];
	cout<<ans<<endl;
	return 0;
}