//CF1190A
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
const int N = 111111;
int m,s;
LL n,k,a[N];
int main()
{
	int i,x;
	LL o;
	scanf("%lld%d%lld",&n,&m,&k);
	for(i=1;i<=m;i=i+1)
		scanf("%lld",a+i);
	for(i=1;i<=m;i=i+1){
		s++;
		x=i;
		o=(a[i]-x)/k;
		while(i<=m&&(a[i+1]-x)/k==o){
			i++;
		}
	}
	cout<<s;
	return 0;
}