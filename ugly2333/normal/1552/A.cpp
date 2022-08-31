//CF1552A
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
char s[N],t[N];
int n;
int main()
{
	int T,i,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1);
		for(i=1;i<=n;i++)
			t[i]=s[i];
		sort(t+1,t+n+1);
		x=0;
		for(i=1;i<=n;i++)
			if(s[i]!=t[i])
				x++;
		printf("%d\n",x);
	}
	return 0;
}