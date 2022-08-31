//CF1552D
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
const int N = 22;
int n,f,a[N],b[N],x,y;
void dfs(int k){
	if(k==n+1){
		if(x==0&&y!=0)
			f=1;
		return;
	}
	int i;
	for(i=-1;i<=1;i++){
		b[k]=i;
		x+=i*a[k];
		y+=abs(i);
		dfs(k+1);
		x-=i*a[k];
		y-=abs(i);
	}
}
int main()
{
	int T,i;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		f=0;
		dfs(1);
		if(f)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}