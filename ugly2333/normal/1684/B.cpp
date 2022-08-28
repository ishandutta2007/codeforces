//CF1684A
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
	int T,a,b,c;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&a,&b,&c);
		printf("%d %d %d\n",a+b+c,b+c,c);
	}
	return 0;
}