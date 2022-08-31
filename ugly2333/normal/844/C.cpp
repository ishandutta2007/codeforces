//CF 843A
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
int a[111111],b[111111],f[111111];
pair<int,int> p[111111];
vector<int> v[111111];
int main()
{
	int n,i,j,x,s;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		p[i]=make_pair(a[i],i);
	}
	sort(p+1,p+n+1);
	for(i=1;i<=n;i=i+1)
		b[p[i].second]=i;
	s=0;
	for(i=1;i<=n;i=i+1){
		if(f[i])
			continue;
		s++;
		v[s].push_back(i);
		f[i]=1;
		x=b[i];
		while(x!=i){
			f[x]=1;
			v[s].push_back(x);
			x=b[x];
		}
	}
	printf("%d\n",s);
	for(i=1;i<=s;i=i+1){
		x=v[i].size();
		printf("%d",x);
		for(j=0;j<x;j=j+1)
			printf(" %d",v[i][j]);
		printf("\n");
	}
	return 0;
}