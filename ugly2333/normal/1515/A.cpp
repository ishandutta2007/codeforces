//CF1515A
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
int n,a[N],k;
int main()
{
	int T,i,s,t;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		s=0;
		for(i=1;i<=n;i=i+1){
			scanf("%d",a+i);
			s+=a[i];
		}
		sort(a+1,a+n+1);
		if(k==s){
			printf("NO\n");
		}
		else{
			printf("YES\n");
			t=0;
			for(i=1;i<=n;i=i+1){
				t+=a[i];
				if(k==t)
					swap(a[i],a[i+1]);
			}
			for(i=1;i<=n;i=i+1)
				printf("%d ",a[i]);
			printf("\n");
		}
	}
	return 0;
}