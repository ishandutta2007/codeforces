//CF1090A
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
int main()
{
	int n,i,j,x,y,z,o,t;
	LL s;
	s=0;
	t=0;
	x=0;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d",&o);
		y=0;
		for(j=1;j<=o;j=j+1){
			scanf("%d",&z);
			y=max(y,z);
		}
		x=max(x,y);
		s+=(LL)y*o;
		t+=o;
	}
	s=(LL)x*t-s;
	cout<<s;
	return 0;
}