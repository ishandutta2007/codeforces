//CF1446A
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
const int N = 222222;
int n,a[N];
LL w,u,s;
int main()
{
	int T,i,j,f,o;
	scanf("%d",&T);
	while(T--){
		scanf("%d%lld",&n,&w);
		u=(w+1)/2;
		f=0;
		for(i=1;i<=n;i=i+1){
			scanf("%d",a+i);
			if(!f&&u<=a[i]&&a[i]<=w){
				f=1;
				printf("1\n%d\n",i);
			}
		}
		if(f)
			continue;
		s=0;
		o=0;
		for(i=1;i<=n;i=i+1){
			if(a[i]>w)
				continue;
			s+=a[i];
			o++;
			if(!f&&u<=s&&s<=w){
				f=1;
				printf("%d\n",o);
				for(j=1;j<=i;j=j+1)
					if(a[j]<=w)
						printf("%d ",j);
				printf("\n");
			}
		}
		if(!f)
			printf("-1\n");
	}
	return 0;
}