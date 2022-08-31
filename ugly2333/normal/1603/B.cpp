//CF1603B
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
	int T,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&x,&y);
		if(x==y)
			printf("%d\n",x);
		else{
			if(x<y)
				printf("%d\n",(y/x*x+y)/2);
			else
				printf("%d\n",x+y);
		}
	}
	return 0;
}