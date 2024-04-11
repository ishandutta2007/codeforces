//CF1654B
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
char s[N];
int main()
{
	int T,x,i,k;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		for(i='a';i<='z';i++)
			a[i]=n+1;
		for(i=1;i<=n;i++)
			a[s[i]]=i;
		x=n+1;
		for(i='a';i<='z';i++)
			x=min(x,a[i]);
		printf("%s\n",s+x);
	}
	return 0;
}