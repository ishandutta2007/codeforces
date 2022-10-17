#include <bits/stdc++.h>
using namespace std;
long long n,p[4],A[100005],d[100005][4];
int main(){
	cin>>n>>p[1]>>p[2]>>p[3];
	for(int i=1;i<=n;++i)cin>>A[i];
	d[0][1]=d[0][2]=d[0][3]=-5e18;
	for(int k=1;k<4;++k)for(int i=1;i<=n;++i)d[i][k]=max(d[i-1][k],d[i][k-1]+p[k]*A[i]);
	cout<<d[n][3];
	return 0;
}