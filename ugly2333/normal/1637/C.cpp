//CF1637A
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
const int N = 1111111;
int n,a[N];
int main()
{
	int T,i,x;
	LL s;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		s=0;
		x=0;
		for(i=2;i<n;i++){
			s+=(a[i]+1)/2;
			x=max(x,a[i]);
		}
		if(x==0)
			printf("%lld\n",s);
		else{
			if(x==1)
				printf("-1\n");
			else{
				if(n==3){
					if(x%2==0)
						printf("%lld\n",s);
					else
						printf("-1\n");
				}
				else
					printf("%lld\n",s);
			}
		}
	}
	return 0;
}