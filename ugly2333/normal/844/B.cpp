//CF 844B
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
int a[55][55];
LL p2[55];
int main()
{
	int n,m,i,j,s;
	LL ans;
	p2[0]=1;
	for(i=1;i<=52;i=i+1)
		p2[i]=(LL)p2[i-1]*2;
	cin>>n>>m;
	ans=-n*m;
	for(i=1;i<=n;i=i+1){
		s=0;
		for(j=1;j<=m;j=j+1){
			cin>>a[i][j];
			s+=a[i][j];
		}
		ans+=(LL)p2[s]-1;
		ans+=(LL)p2[m-s]-1;
	}
	for(j=1;j<=m;j=j+1){
		s=0;
		for(i=1;i<=n;i=i+1)
			s+=a[i][j];
		ans+=(LL)p2[s]-1;
		ans+=(LL)p2[n-s]-1;
	}
	cout<<ans<<endl;
	return 0;
}