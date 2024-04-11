//CF1672A
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
int main()
{
	int T,i,l,r,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		l=n+1,r=0;
		for(i=1;i+1<=n;i++)
			if(a[i]==a[i+1])
				l=min(l,i),r=max(r,i);
		if(r==0||r==l)
			x=0;
		else{
			if(r-l==1)
				x=1;
			else
				x=r-l-1;
		}
		printf("%d\n",x);
	}
	return 0;
}