//CF 837C
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
int n,a,b;
int x[111],y[111];
bool ok(int i,int j)
{
	int xx,yy;
	xx=x[i]+x[j];
	yy=max(y[i],y[j]);
	if(min(xx,yy)<=a&&max(xx,yy)<=b)
		return 1;
	xx=x[i]+y[j];
	yy=max(y[i],x[j]);
	if(min(xx,yy)<=a&&max(xx,yy)<=b)
		return 1;
	xx=y[i]+x[j];
	yy=max(x[i],y[j]);
	if(min(xx,yy)<=a&&max(xx,yy)<=b)
		return 1;
	xx=y[i]+y[j];
	yy=max(x[i],x[j]);
	if(min(xx,yy)<=a&&max(xx,yy)<=b)
		return 1;
	return 0;
}
int main()
{
	int i,j,ans;
	cin>>n>>a>>b;
	if(a>b)
		swap(a,b);
	for(i=1;i<=n;i=i+1){
		cin>>x[i]>>y[i];
		if(x[i]>y[i])
			swap(x[i],y[i]);
	}
	ans=0;
	for(i=1;i<=n;i=i+1)
		for(j=i+1;j<=n;j=j+1)
			if(ok(i,j))
				ans=max(ans,x[i]*y[i]+x[j]*y[j]);
	cout<<ans<<endl;
	return 0;
}