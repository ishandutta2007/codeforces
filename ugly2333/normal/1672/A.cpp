//CF1672A
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
int n;
int main()
{
	int T,i,s,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		s=0;
		for(i=1;i<=n;i++)
			scanf("%d",&x),s+=x-1;
		if(s&1)
			printf("errorgorn\n");
		else
			printf("maomao90\n");
	}
	return 0;
}