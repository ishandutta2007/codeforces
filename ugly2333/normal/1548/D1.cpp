//CF1548D1
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
int n,a[11];
LL c3(LL x){
	return x*(x-1)*(x-2)/6;
}
LL c2(LL x){
	return x*(x-1)/2;
}
int main()
{
	int i,x,y,o;
	LL s;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		x/=2,y/=2;
		o=0;
		if(x&1)
			o+=2;
		if(y&1)
			o++;
		a[o]++;
	}
	s=0;
	for(i=0;i<4;i++)
		s+=c3(a[i]);
	for(i=0;i<4;i++)
		s+=c2(a[i])*(n-a[i]);
	printf("%lld\n",s);
	return 0;
}