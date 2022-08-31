//CF 810A
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
pair<int,int> a[111111];
long long ans=0;
int main()
{
	int n,k,i,x,y;
	cin>>n>>k;
	for(i=1;i<=n;i=i+1){
		cin>>x>>y;
		a[i].second=min(x,y);
		a[i].first=min(2*x,y);
		a[i].first-=a[i].second;
	}
	sort(a+1,a+n+1);
	for(i=n;i>=n-k+1;i=i-1)
		ans+=(a[i].first+a[i].second);
	for(i=n-k;i>=1;i=i-1)
		ans+=a[i].second;
	cout<<ans<<endl;
	return 0;
}