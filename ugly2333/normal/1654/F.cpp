//CF1654F
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
const int N = 1<<19;
int n,m,a[N];
char s[N];
pair<pair<int,int>,int> p[N];
int main()
{
	int i,j,x;
	scanf("%d%s",&n,s);
	m=1<<n;
	for(i=0;i<m;i++)
		a[i]=s[i]-'a'+1;
	for(j=1;j<m;j<<=1){
		for(i=0;i<m;i++)
			p[i]=make_pair(make_pair(a[i],a[i^j]),i);
		sort(p,p+m);
		x=0;
		for(i=0;i<m;i++){
			if(i==0||p[i].first!=p[i-1].first)
				x++;
			a[p[i].second]=x;
		}
	}
	for(i=0;i<m;i++)
		if(a[i]==1)
			x=i;
	for(i=0;i<m;i++)
		printf("%c",s[i^x]);
	return 0;
}