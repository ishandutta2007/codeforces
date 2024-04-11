//CF1396B
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
const int N = 111;
int n,a[N];
int main()
{
	int T,i,x,s;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		x=0,s=0;
		for(i=1;i<=n;i=i+1){
			scanf("%d",a+i);
			x=max(x,a[i]);
			s+=a[i];
		}
		if(x>s-x){
			printf("T\n");
			continue;
		}
		if(s&1)
			printf("T\n");
		else
			printf("HL\n");
	}
	return 0;
}