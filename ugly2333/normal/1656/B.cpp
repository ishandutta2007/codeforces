//CF1656B
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
int n,k,a[N];
int main()
{
	int T,i,j,f;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		sort(a+1,a+n+1);
		i=1,j=2;
		f=0;
		while(j<=n){
			if(a[j]-a[i]==k)
				f=1;
			if(a[j]-a[i]>=k)
				i++;
			else
				j++;
		}
		if(f)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}