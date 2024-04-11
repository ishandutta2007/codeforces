//CF1119E
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
const int N = 333333;
int n,a[N];
int main()
{
	int i,x,o;
	LL s;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	x=0,s=0;
	for(i=1;i<=n;i=i+1){
		o=min(x,a[i]/2);
		s+=o;
		a[i]-=o*2;
		x-=o;
		s+=a[i]/3;
		x+=a[i]%3;
	}
	cout<<s;
	return 0;
}