//CF 901B
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
const int N = 222;
int a[N][N];
int main()
{
	int n,i,j;
	cin>>n;
	n++;
	a[1][1]=1;
	for(i=2;i<=n;i=i+1)
		for(j=1;j<=i;j=j+1)
			a[i][j]=(a[i-1][j-1]+a[i-2][j])&1;
	for(i=0;i<=1;i=i+1){
		cout<<n-1<<endl;
		for(j=1;j<=n;j=j+1)
			cout<<a[n][j]<<' ';
		cout<<endl;
		n--;
	}
	return 0;
}