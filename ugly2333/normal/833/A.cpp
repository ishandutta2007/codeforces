//CF 833A
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
int main()
{
	int T,a,b,d;
	LL c;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		c=(LL)a*b;
		d=(int)(pow((double)c,(double)1/3)+0.5);
		if((LL)d*d*d==c&&a%d==0&&b%d==0)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}