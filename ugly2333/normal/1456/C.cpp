//CF1456C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 555555;
int n,k,a[N];
int main()
{
	int i;
	LL x,s;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	x=0;
	s=0;
	for(i=n;i>=1&&x>=0;i=i-1){
		s+=x;
		x+=a[i];
	}
	n=i+1;
	a[n]=x;
	for(i=1;i<=n;i=i+1)
		s+=(LL)a[i]*((i-1)/(k+1));
	cout<<s;
	return 0;
}