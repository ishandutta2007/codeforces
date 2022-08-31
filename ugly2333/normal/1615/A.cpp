//CF1615A
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
int n,a[N];
int main()
{
	int T,i,s;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		s=0;
		for(i=1;i<=n;i++)
			scanf("%d",a+i),s+=a[i];
		if(s%n)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}