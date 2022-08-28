//CF1556A
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
	int T,a,b,c,d;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		if((a^b)&1)
			printf("-1\n");
		else{
			if(!a&&!b)
				printf("0\n");
			else{
				if(a==b)
					printf("1\n");
				else
					printf("2\n");
			}
		}
	}
	return 0;
}