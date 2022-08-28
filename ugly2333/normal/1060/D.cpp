//CF1060D
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
int n,l[N],r[N];
LL s;
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%d%d",l+i,r+i),s+=l[i]+r[i]+1;
	sort(l+1,l+n+1);
	sort(r+1,r+n+1);
	for(i=1;i<=n;i=i+1)
		s-=min(l[i],r[i]);
	cout<<s;
	return 0;
}