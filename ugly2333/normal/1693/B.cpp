//CF1693B
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
int n,p[N],l[N],r[N];
LL s[N];
int main()
{
	int T,i,o;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=2;i<=n;i++)
			scanf("%d",p+i);
		for(i=1;i<=n;i++)
			scanf("%d%d",l+i,r+i),s[i]=0;
		o=0;
		for(i=n;i>=1;i--){
			if(s[i]<l[i]){
				o++;
				s[p[i]]+=r[i];
			}
			else
				s[p[i]]+=min((LL)r[i],s[i]);
		}
		printf("%d\n",o);
	}
	return 0;
}