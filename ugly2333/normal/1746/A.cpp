//CF1746A
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
const int N = 1111;
int n,k;
int main()
{
	int T,i,s,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		s=0;
		for(i=1;i<=n;i++)
			scanf("%d",&x),s+=x;
		if(s>=1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}