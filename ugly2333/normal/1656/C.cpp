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
	int T,i,j,f,a0,a1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		a0=0,a1=0;
		for(i=1;i<=n;i++)
			scanf("%d",a+i),a0+=a[i]==0,a1+=a[i]==1;
		sort(a+1,a+n+1);
		if(a[1]==a[n])
			f=1;
		else{
			if(a0){
				if(a1)
					f=0;
				else
					f=1;
			}
			else{
				if(a1){
					f=1;
					for(i=1;i<n;i++)
						if(a[i]+1==a[i+1])
							f=0;
				}
				else
					f=1;
			}
		}
		if(f)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}