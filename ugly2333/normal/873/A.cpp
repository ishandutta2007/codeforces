//CF 873A
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
int a[111];
int main()
{
	int n,k,x,i;
	cin>>n>>k>>x;
	for(i=1;i<=n;i=i+1)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(i=n;i>=n-k+1;i=i-1){
		if(a[i]>x)
			a[i]=x;
	}
	for(i=1;i<=n;i=i+1)
		a[0]+=a[i];
	cout<<a[0]<<endl;
	return 0;
}