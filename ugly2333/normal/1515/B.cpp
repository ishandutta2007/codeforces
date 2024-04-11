//CF1515B
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
bool sq(int x){
	DB y=sqrt((DB)x);
	y+=0.5;
	int z=y;
	return x==z*z;
}
int main()
{
	int T,n,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if((n%2==0&&sq(n/2))||(n%4==0)&&sq(n/4))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}