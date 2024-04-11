//CF1610A
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
	int T,n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		if(n==1&&m==1)
			printf("0\n");
		else{
			if(n==1||m==1)
				printf("1\n");
			else
				printf("2\n");
		}
	}
	return 0;
}