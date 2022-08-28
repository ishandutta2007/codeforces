//CF1148D
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
const int N = 333333;
int n,s1,s2,m,a[N],b[N];
pair<int,int> p[N];
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d",a+i,b+i);
		if(a[i]<b[i])
			s1++;
		else
			s2++;
	}
	if(s1>s2){
		for(i=1;i<=n;i=i+1)
			if(a[i]<b[i])
				p[m++]=make_pair(-a[i],i);
	}
	else{
		for(i=1;i<=n;i=i+1)
			if(a[i]>b[i])
				p[m++]=make_pair(a[i],i);
	}
	sort(p,p+m);
	printf("%d\n",m);
	for(i=0;i<m;i=i+1)
		printf("%d ",p[i].second);
	return 0;
}