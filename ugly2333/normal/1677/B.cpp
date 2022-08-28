//CF1677B
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
const int N = 2e6+26;
char c[N];
int n,m,w,s[N],a[N],b[N];
int main()
{
	int T,i;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%s",&n,&m,c);
		w=n*m;
		for(i=w;i<w*2;i++)
			s[i]=s[i-1]+(c[i-w]=='1');
		for(i=0;i<w;i++)
			a[i]=a[i-m]+(s[i+w]>s[i-m+w]);
		for(i=w;i<w*2;i++)
			s[i]=s[i-m]+(c[i-w]=='1');
		for(i=0;i<w;i++)
			b[i]=b[i-1]-(s[i-m+w]>s[i])+(s[i+w]>s[i]);
		for(i=0;i<w;i++)
			printf("%d ",a[i]+b[i]);
		printf("\n");
		for(i=0;i<w*2;i++)
			a[i]=0,b[i]=0,s[i]=0;
	}
	return 0;
}