//CF1753B
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
const int N = 555555;
int n,m,a[N];
int main()
{
	int i,x;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&x),a[x]++;
	for(i=1;i<m;i++){
		if(a[i]){
			if(a[i]%(i+1)){
				printf("No\n");
				return 0;
			}
			a[i+1]+=a[i]/(i+1);
		}
	}
	printf("Yes\n");
	return 0;
}