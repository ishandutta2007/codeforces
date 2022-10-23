//CF1746A
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
const int N = 111111;
int n,k,a[N];
int main()
{
	int T,i,s,x,p;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		s=0;
		for(i=1;i<=n;i++)
			scanf("%d",a+i),s+=a[i];
		p=n-s;
		x=0;
		for(i=1;i<=n;i++){
			x+=a[i];
			p=min(p,max(x,n-s-(i-x)));
		}
		printf("%d\n",p);
	}
	return 0;
}